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

static std::vector<std::string> string_split(const std::string &str, char delimiter)
{
    std::vector<std::string> result;
    size_t start_pos = 0, end_pos = 0;
    while((end_pos = str.find(delimiter, start_pos)) != std::string::npos)
    {
        result.push_back(str.substr(start_pos, end_pos - start_pos));
        start_pos = end_pos + 1;
    }
    result.push_back(str.substr(start_pos));
    return result;
}

static std::string string_join(const std::vector<std::string> &tokens, char delimiter)
{
    if(tokens.empty())
        return "";
    std::string result = tokens[0];
    for(size_t i = 1; i < tokens.size(); ++i)
    {
        result += delimiter;
        result += tokens[i];
    }
    return result;
}

static std::string replace_all(std::string str, char from, char to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
        str.replace(start_pos++, 1, 1, to);
    return str;
}

static std::string ltrim(const std::string &str)
{
    size_t start_pos = 0;
    while(start_pos < str.length() && std::isspace(str[start_pos]))
        ++start_pos;
    return str.substr(start_pos);
}

static std::string rtrim(const std::string &str)
{
    size_t end_pos = str.length();
    while(end_pos > 0 && std::isspace(str[end_pos - 1]))
        --end_pos;
    return str.substr(0, end_pos);
}

static std::string trim(const std::string &str)
{
    return ltrim(rtrim(str));
}

static std::string lang_enchant_to_ms(const std::string &str)
{
    return replace_all(str, '_', '-');
}

static std::string lang_enchant_from_ms(const std::string &str)
{
    return replace_all(str, '-', '_');
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
    struct Checker
    {
        ISpellChecker *checker;
        std::string language;
    };
    std::vector<Checker> checkers;
    std::set<std::string> ignores;

    _EnchantDict(ISpellCheckerFactory *factory, const char *const tag)
    {
        if(!factory)
            return;

        const std::vector<std::string> langs = string_split(tag, ',');
        for(std::vector<std::string>::const_iterator it = langs.cbegin(); it != langs.cend(); ++it)
        {
            Checker checker;
            checker.language = trim(*it);

            const std::wstring lang = utf8_to_wstring(lang_enchant_to_ms(checker.language));
            if(FAILED(factory->CreateSpellChecker(lang.c_str(), &checker.checker)))
            {
                dprintf("CreateSpellChecker failed for lang=%s", checker.language.c_str());
                continue;
            }

            LPWSTR value = NULL;
            if(FAILED(checker.checker->get_LanguageTag(&value)))
            {
                dprintf("get_LanguageTag failed for lang=%s", checker.language.c_str());
            }
            if(value)
            {
                checker.language = lang_enchant_from_ms(wstring_to_utf8(value));
                CoTaskMemFree(value);
            }

            dprintf("Created dict for lang=%s", checker.language.c_str());
            checkers.emplace_back(checker);
        }
    }

    ~_EnchantDict()
    {
        for(std::vector<Checker>::const_iterator it = checkers.cbegin(); it != checkers.cend(); ++it)
        {
            if(it->checker)
                it->checker->Release();
        }
    }

    std::vector<std::string> languages() const
    {
        std::vector<std::string> result;
        for(std::vector<EnchantDict::Checker>::const_iterator it = checkers.cbegin(); it != checkers.cend(); ++it)
        {
            if(!it->checker)
                continue;
            result.push_back(it->language);
        }
        return result;
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
    if(dict->checkers.empty())
    {
        delete dict;
        return NULL;
    }
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
    dprintf("lang=%s, word=%s", (dict ? string_join(dict->languages(), ',').c_str() : "NULL"), (word ? word : "NULL"));
    if(!dict || !word)
        return -1;

    if(len < 0)
        len = (ssize_t)strlen(word);

    const std::string str(word, (size_t)len);
    if(str.empty())
        return -1;

    if(dict->ignores.find(str) != dict->ignores.cend())
    {
        dprintf("lang=%s, result=%s", string_join(dict->languages(), ',').c_str(), ("IGNORED"));
        return 0;
    }

    bool check_completed = false;
    bool check_ok = false;
    const std::wstring wstr = utf8_to_wstring(str);
    for(std::vector<EnchantDict::Checker>::const_iterator it = dict->checkers.cbegin(); it != dict->checkers.cend(); ++it)
    {
        if(!it->checker)
            continue;

        IEnumSpellingError *value = NULL;
        if(FAILED(it->checker->Check(wstr.c_str(), &value)) || !value)
        {
            if(value)
                value->Release();
            dprintf("lang=%s, result=%s", it->language.c_str(), "FAILED");
            continue;
        }

        ISpellingError *error = NULL;
        switch(value->Next(&error))
        {
        case S_OK:
            check_completed = true;
            dprintf("lang=%s, result=%s", it->language.c_str(), "BAD");
            break;
        case S_FALSE:
            check_completed = true;
            check_ok = true;
            dprintf("lang=%s, result=%s", it->language.c_str(), "GOOD");
            break;
        default:
            dprintf("lang=%s, result=%s", it->language.c_str(), "FAILED");
            break;
        }
        if(error)
            error->Release();
        value->Release();

        if(check_ok)
            break;
    }

    if(check_ok)
        return 0;
    if(check_completed)
        return 1;
    return -1;
}

char **enchant_dict_suggest(EnchantDict *dict, const char *const word, ssize_t len, size_t *out_n_suggs)
{
    dprintf("lang=%s, word=%s", (dict ? string_join(dict->languages(), ',').c_str() : "NULL"), (word ? word : "NULL"));
    if(!dict || !word || !out_n_suggs)
        return NULL;
    *out_n_suggs = 0;

    if(len < 0)
        len = (ssize_t)strlen(word);
    const std::wstring wstr = utf8_to_wstring(std::string(word, (size_t)len));
    std::vector<std::string> suggestions;
    for(std::vector<EnchantDict::Checker>::const_iterator it = dict->checkers.cbegin(); it != dict->checkers.cend(); ++it)
    {
        if(!it->checker)
            continue;

        IEnumString *value = NULL;
        if(FAILED(it->checker->Suggest(wstr.c_str(), &value)) || !value)
        {
            if(value)
                value->Release();
            continue;
        }

        while(true)
        {
            LPOLESTR suggest = NULL;
            ULONG fetched = 0;
            if(FAILED(value->Next(1, &suggest, &fetched)) || fetched == 0)
            {
                if(suggest)
                    CoTaskMemFree(suggest);
                break;
            }
            suggestions.emplace_back(wstring_to_utf8(suggest));
            CoTaskMemFree(suggest);
            dprintf("lang=%s, suggest=%s", it->language.c_str(), suggestions[suggestions.size() - 1].c_str());
        }
        value->Release();
    }

    *out_n_suggs = suggestions.size();
    char **result = (char**)malloc((*out_n_suggs + 1) * sizeof(char*));
    char **curr = result;
    for(std::vector<std::string>::const_iterator it = suggestions.cbegin(); it != suggestions.cend(); ++it)
    {
        const size_t guess_len = it->size() + 1;
        *curr = (char*)malloc(sizeof(char) * guess_len);
        memcpy(*curr, it->c_str(), it->size());
        (*curr)[guess_len - 1] = '\0';
        dprintf("lang=%s, guess_len=%lu, result=%s", string_join(dict->languages(), ',').c_str(), (unsigned long)guess_len, *curr);
        ++curr;
    }
    *curr = NULL;
    return result;
}

void enchant_dict_add(EnchantDict *dict, const char *const word, ssize_t len)
{
    dprintf("lang=%s, word=%s", (dict ? string_join(dict->languages(), ',').c_str() : "NULL"), (word ? word : "NULL"));
    if(!dict || !word)
        return;

    if(len < 0)
        len = (ssize_t)strlen(word);
    const std::wstring wstr = utf8_to_wstring(std::string(word, (size_t)len));
    if(wstr.empty())
        return;

    for(std::vector<EnchantDict::Checker>::const_iterator it = dict->checkers.cbegin(); it != dict->checkers.cend(); ++it)
    {
        if(!it->checker)
            continue;

        dprintf("lang=%s, word=%s", it->language.c_str(), (word ? word : "NULL"));
        it->checker->Add(wstr.c_str());
        break;
    }
}

void enchant_dict_add_to_session(EnchantDict *dict, const char *const word, ssize_t len)
{
    dprintf("lang=%s, word=%s", (dict ? string_join(dict->languages(), ',').c_str() : "NULL"), (word ? word : "NULL"));
    if(!dict || !word)
        return;

    if(len < 0)
        len = (ssize_t)strlen(word);
    dict->ignores.insert(std::string(word, (size_t)len));
}

void enchant_dict_store_replacement(EnchantDict *dict, const char *const mis, ssize_t mis_len, const char *const cor, ssize_t cor_len)
{
    dprintf("lang=%s, mis=%s, cor=%s", (dict ? string_join(dict->languages(), ',').c_str() : "NULL"), (mis ? mis : "NULL"), (cor ? cor : "NULL"));
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
    std::string lang = "";
    for(std::vector<EnchantDict::Checker>::const_iterator it = dict->checkers.cbegin(); it != dict->checkers.cend(); ++it)
    {
        if(!it->checker)
            continue;
        lang = it->language;
        break;
    }
    dprintf("lang=%s", lang.c_str());
    fn(lang.c_str(), "Microsoft", "MicrosoftSpellCheckerProvider", "spellcheck.h", user_data);
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
        const std::string lang = lang_enchant_from_ms(wstring_to_utf8(str));
        dprintf("lang=%s", lang.c_str());
        fn(lang.c_str(), "Microsoft", "MicrosoftSpellCheckerProvider", "spellcheck.h", user_data);
        CoTaskMemFree(str);
    }
    value->Release();
}
