#include <iostream>

#define BUILDING_WEBKIT
#include <webkit/webkit.h>
#include <webkit/webkitwebview.h>
#undef BUILDING_WEBKIT

using namespace std;

extern "C" {

struct _WebKitWebViewPrivate
{
    int _;
};

G_DEFINE_TYPE(WebKitWebView, wkwv_shim, GTK_TYPE_WIDGET)

WEBKIT_API GtkWidget * webkit_web_view_new(void);


WEBKIT_API WebKitWebSettings *
webkit_web_view_get_settings                    (WebKitWebView        *web_view);

WEBKIT_API void
webkit_web_view_set_settings                    (WebKitWebView        *web_view,
                                                 WebKitWebSettings    *settings);

WEBKIT_API void
webkit_web_view_load_string                     (WebKitWebView        *web_view,
                                                 const gchar          *content,
                                                 const gchar          *mime_type,
                                                 const gchar          *encoding,
                                                 const gchar          *base_uri);

}

// https://wiki.gnome.org/HowDoI/CustomWidgets
// https://www.cc.gatech.edu/data_files/public/doc/gtk/tutorial/gtk_tut-20.html
// https://stackovergo.com/ru/q/2843892/how-to-get-xid-of-gtk2-gtkdrawingarea-to-embed-mplayer
// https://stackoverflow.com/questions/21102622/how-to-create-a-cairo-t-on-a-gtk-2-window
// https://cgit.freedesktop.org/spice/spice-gtk/commit/?id=fdd80e5ed4002f94d3e31c9a76426b49823ea7e5
// https://cpp.hotexamples.com/examples/-/-/GDK_WINDOW_HWND/cpp-gdk_window_hwnd-function-examples.html
// https://zetcode.com/gui/gtk2/customwidget/
// (!) https://gstreamer.freedesktop.org/documentation/video/gstvideooverlay.html?gi-language=c#gstvideooverlay-and-gtk
// (!) https://www.opennet.ru/docs/RUS/gobject_api/howto-interface-properties.html

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
