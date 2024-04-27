/*
g++ -O3 -std=c++14 -shared -fPIC -o libenchant-2.dll -Wall \
    -Wl,--export-all-symbols -Wl,--enable-auto-import \
    -Wl,--whole-archive enchant.cpp -Wl,--no-whole-archive \
    -lole32 -s
*/

#if defined(_WIN32_WINNT) && (_WIN32_WINNT < 0x0602)
#undef _WIN32_WINNT
#endif
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0602
#endif

#include <windows.h>
#include <spellcheck.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <set>
#include <string>
#include <vector>

#ifdef _MSC_VER
#define ssize_t SSIZE_T
#endif

#include "enchant.h"

/* gtkspell-2.0.16:
enchant_broker_free
enchant_broker_free_dict
enchant_broker_init
enchant_broker_list_dicts
enchant_broker_request_dict
enchant_dict_add_to_pwl => enchant_dict_add
enchant_dict_add_to_session
enchant_dict_check
enchant_dict_describe
enchant_dict_free_string_list
enchant_dict_store_replacement
enchant_dict_suggest
*/

#if __cplusplus < 201103L
#define cbegin begin
#define cend end
#define emplace_back push_back
#endif

static BOOL ENCHANT_DEBUG = FALSE;

#define dprintf(fmt, ...) do { \
    if(ENCHANT_DEBUG) { \
        fprintf(stderr, "[ENCHANT_DEBUG] %s:%d: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        fflush(stderr); \
    } \
} while (0)

static std::wstring utf8_to_wstring(const std::string &str)
{
    if(str.empty())
        return std::wstring();
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

static std::string wstring_to_utf8(const std::wstring &wstr)
{
    if(wstr.empty())
        return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

struct _EnchantBroker
{
    ISpellCheckerFactory *factory;
    HRESULT init_result;

    _EnchantBroker()
        : factory(NULL)
    {
        init_result = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
        if(FAILED(CoCreateInstance(__uuidof(SpellCheckerFactory), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory))))
            factory = NULL;
    }

    ~_EnchantBroker()
    {
        if(factory)
            factory->Release();
        if(init_result == S_OK || init_result == S_FALSE)
            CoUninitialize();
    }
};

struct _EnchantDict
{
    ISpellChecker *checker;
    std::string language;
    std::set<std::string> ignores;

    _EnchantDict(ISpellCheckerFactory *factory, const char *const tag)
        : checker(NULL)
        , language(tag)
    {
        if(!factory)
            return;

        const std::wstring lang = utf8_to_wstring(tag);
        if(FAILED(factory->CreateSpellChecker(lang.c_str(), &checker)) || !checker)
        {
            checker = NULL;
            return;
        }

        LPWSTR value = NULL;
        if(FAILED(checker->get_LanguageTag(&value)) || !value)
        {
            if(value)
                CoTaskMemFree(value);
            return;
        }
        language = wstring_to_utf8(value);
        CoTaskMemFree(value);
    }

    ~_EnchantDict()
    {
        if(checker)
            checker->Release();
    }
};

EnchantBroker *enchant_broker_init()
{
    ENCHANT_DEBUG = !!getenv("ENCHANT_DEBUG");
    dprintf();
    EnchantBroker *broker = new EnchantBroker();
    return broker;
}

void enchant_broker_free(EnchantBroker *broker)
{
    dprintf();
    if(!broker)
        return;
    delete broker;
}

EnchantDict *enchant_broker_request_dict(EnchantBroker *broker, const char *const tag)
{
    dprintf("tag=%s", (tag ? tag : "NULL"));
    if(!broker || !tag || !broker->factory)
        return NULL;
    EnchantDict *dict = new EnchantDict(broker->factory, tag);
    return dict;
}

void enchant_broker_free_dict(EnchantBroker *broker, EnchantDict *dict)
{
    dprintf();
    if(!broker || !dict)
        return;
    delete dict;
}

int enchant_dict_check(EnchantDict *dict, const char *const word, ssize_t len)
{
    dprintf("lang=%s, word=%s", dict->language.c_str(), (word ? word : "NULL"));
    if(!dict || !word || !dict->checker)
        return -1;

    if(len < 0)
        len = (ssize_t)strlen(word);

    const std::string str(word, (size_t)len);
    if(str.empty())
        return -1;

    if(dict->ignores.find(str) != dict->ignores.cend())
    {
        dprintf("lang=%s, result=%s", dict->language.c_str(), ("IGNORED"));
        return 0;
    }

    const std::wstring wstr = utf8_to_wstring(str);
    IEnumSpellingError *value = NULL;
    if(FAILED(dict->checker->Check(wstr.c_str(), &value)) || !value)
    {
        if(value)
            value->Release();
        return -1;
    }

    int result;
    ISpellingError *error = NULL;
    switch(value->Next(&error))
    {
    case S_OK:
        result = 1;
        dprintf("lang=%s, result=%s", dict->language.c_str(), "BAD");
        break;
    case S_FALSE:
        result = 0;
        dprintf("lang=%s, result=%s", dict->language.c_str(), "GOOD");
        break;
    default:
        result = -1;
        dprintf("lang=%s, result=%s", dict->language.c_str(), "FAILED");
        break;
    }
    if(error)
        error->Release();
    value->Release();
    return result;
}

char **enchant_dict_suggest(EnchantDict *dict, const char *const word, ssize_t len, size_t *out_n_suggs)
{
    dprintf("lang=%s, word=%s", dict->language.c_str(), (word ? word : "NULL"));
    if(!dict || !word || !out_n_suggs || !dict->checker)
        return NULL;
    *out_n_suggs = 0;

    if(len < 0)
        len = (ssize_t)strlen(word);
    const std::wstring wstr = utf8_to_wstring(std::string(word, (size_t)len));
    IEnumString *value = NULL;
    if(FAILED(dict->checker->Suggest(wstr.c_str(), &value)) || !value)
    {
        if(value)
            value->Release();
        return NULL;
    }

    std::vector<std::string> suggestions;
    while(true)
    {
        LPOLESTR str = NULL;
        ULONG fetched = 0;
        if(FAILED(value->Next(1, &str, &fetched)) || fetched == 0)
        {
            if(str)
                CoTaskMemFree(str);
            break;
        }
        suggestions.emplace_back(wstring_to_utf8(str));
        CoTaskMemFree(str);
    }
    value->Release();

    *out_n_suggs = suggestions.size();
    char **result = (char**)malloc((*out_n_suggs + 1) * sizeof(char*));
    char **curr = result;
    for(std::vector<std::string>::const_iterator it = suggestions.cbegin(); it != suggestions.cend(); ++it)
    {
        const size_t guess_len = it->size() + 1;
        *curr = (char*)malloc(sizeof(char) * guess_len);
        memcpy(*curr, it->c_str(), it->size());
        (*curr)[guess_len - 1] = '\0';
        dprintf("lang=%s, guess_len=%lu, result=%s", dict->language.c_str(), (unsigned long)guess_len, *curr);
        ++curr;
    }
    *curr = NULL;
    return result;
}

void enchant_dict_add(EnchantDict *dict, const char *const word, ssize_t len)
{
    dprintf("lang=%s, word=%s", dict->language.c_str(), (word ? word : "NULL"));
    if(!dict || !word || !dict->checker)
        return;

    if(len < 0)
        len = (ssize_t)strlen(word);
    const std::wstring wstr = utf8_to_wstring(std::string(word, (size_t)len));
    if(wstr.empty())
        return;
    dict->checker->Add(wstr.c_str());
}

void enchant_dict_add_to_session(EnchantDict *dict, const char *const word, ssize_t len)
{
    dprintf("lang=%s, word=%s", dict->language.c_str(), (word ? word : "NULL"));
    if(!dict || !word)
        return;
    dict->ignores.insert(word);
}

void enchant_dict_store_replacement(EnchantDict *dict, const char *const mis, ssize_t mis_len, const char *const cor, ssize_t cor_len)
{
    dprintf("lang=%s, mis=%s, cor=%s", dict->language.c_str(), (mis ? mis : "NULL"), (cor ? cor : "NULL"));
    dprintf("NOT_IMPLEMENTED");
    (void)(dict);
    (void)(mis);
    (void)(mis_len);
    (void)(cor);
    (void)(cor_len);
}

void enchant_dict_free_string_list(EnchantDict *dict, char **string_list)
{
    dprintf();
    if(!dict || !string_list)
        return;
    for(char **curr = string_list; *curr; ++curr)
        free(*curr);
    free(string_list);
}

void enchant_dict_describe(EnchantDict *dict, EnchantDictDescribeFn fn, void *user_data)
{
    dprintf();
    if(!dict || !fn)
        return;
    dprintf("lang=%s", dict->language.c_str());
    fn(dict->language.c_str(), "Microsoft", "MicrosoftSpellCheckerProvider", "spellcheck.h", user_data);
}

void enchant_broker_list_dicts(EnchantBroker *broker, EnchantDictDescribeFn fn, void *user_data)
{
    dprintf();
    if(!broker || !fn || !broker->factory)
        return;

    IEnumString *value = NULL;
    if(FAILED(broker->factory->get_SupportedLanguages(&value)) || !value)
    {
        if(value)
            value->Release();
        return;
    }

    while(true)
    {
        LPOLESTR str = NULL;
        ULONG fetched = 0;
        if(FAILED(value->Next(1, &str, &fetched)) || fetched == 0)
        {
            if(str)
                CoTaskMemFree(str);
            break;
        }
        const std::string lang = wstring_to_utf8(str);
        fn(lang.c_str(), "Microsoft", "MicrosoftSpellCheckerProvider", "spellcheck.h", user_data);
        CoTaskMemFree(str);
    }
    value->Release();
}
