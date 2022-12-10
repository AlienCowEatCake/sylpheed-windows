/*
 *  This file is part of the WebKit open source project.
 *  This file has been generated by generate-bindings.pl. DO NOT MODIFY!
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#if !defined(__WEBKITDOM_H_INSIDE__) && !defined(BUILDING_WEBKIT)
#error "Only <webkitdom/webkitdom.h> can be included directly."
#endif

#ifndef WebKitDOMDOMWindow_h
#define WebKitDOMDOMWindow_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_DOM_WINDOW            (webkit_dom_dom_window_get_type())
#define WEBKIT_DOM_DOM_WINDOW(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_DOM_WINDOW, WebKitDOMDOMWindow))
#define WEBKIT_DOM_DOM_WINDOW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_DOM_WINDOW, WebKitDOMDOMWindowClass)
#define WEBKIT_DOM_IS_DOM_WINDOW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_DOM_WINDOW))
#define WEBKIT_DOM_IS_DOM_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_DOM_WINDOW))
#define WEBKIT_DOM_DOM_WINDOW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_DOM_WINDOW, WebKitDOMDOMWindowClass))

struct _WebKitDOMDOMWindow {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMDOMWindowClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_dom_window_get_type (void);

/**
 * webkit_dom_dom_window_get_selection:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMSelection
**/
WEBKIT_API WebKitDOMDOMSelection*
webkit_dom_dom_window_get_selection(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_focus:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_focus(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_blur:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_blur(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_close:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_close(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_print:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_print(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_stop:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_stop(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_alert:
 * @self: A #WebKitDOMDOMWindow
 * @message: A #gchar
 *
**/
WEBKIT_API void
webkit_dom_dom_window_alert(WebKitDOMDOMWindow* self, const gchar* message);

/**
 * webkit_dom_dom_window_confirm:
 * @self: A #WebKitDOMDOMWindow
 * @message: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_window_confirm(WebKitDOMDOMWindow* self, const gchar* message);

/**
 * webkit_dom_dom_window_prompt:
 * @self: A #WebKitDOMDOMWindow
 * @message: A #gchar
 * @defaultValue: A #gchar
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_dom_window_prompt(WebKitDOMDOMWindow* self, const gchar* message, const gchar* defaultValue);

/**
 * webkit_dom_dom_window_find:
 * @self: A #WebKitDOMDOMWindow
 * @string: A #gchar
 * @caseSensitive: A #gboolean
 * @backwards: A #gboolean
 * @wrap: A #gboolean
 * @wholeWord: A #gboolean
 * @searchInFrames: A #gboolean
 * @showDialog: A #gboolean
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_window_find(WebKitDOMDOMWindow* self, const gchar* string, gboolean caseSensitive, gboolean backwards, gboolean wrap, gboolean wholeWord, gboolean searchInFrames, gboolean showDialog);

/**
 * webkit_dom_dom_window_scroll_by:
 * @self: A #WebKitDOMDOMWindow
 * @x: A #glong
 * @y: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_scroll_by(WebKitDOMDOMWindow* self, glong x, glong y);

/**
 * webkit_dom_dom_window_scroll_to:
 * @self: A #WebKitDOMDOMWindow
 * @x: A #glong
 * @y: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_scroll_to(WebKitDOMDOMWindow* self, glong x, glong y);

/**
 * webkit_dom_dom_window_scroll:
 * @self: A #WebKitDOMDOMWindow
 * @x: A #glong
 * @y: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_scroll(WebKitDOMDOMWindow* self, glong x, glong y);

/**
 * webkit_dom_dom_window_move_by:
 * @self: A #WebKitDOMDOMWindow
 * @x: A #gfloat
 * @y: A #gfloat
 *
**/
WEBKIT_API void
webkit_dom_dom_window_move_by(WebKitDOMDOMWindow* self, gfloat x, gfloat y);

/**
 * webkit_dom_dom_window_move_to:
 * @self: A #WebKitDOMDOMWindow
 * @x: A #gfloat
 * @y: A #gfloat
 *
**/
WEBKIT_API void
webkit_dom_dom_window_move_to(WebKitDOMDOMWindow* self, gfloat x, gfloat y);

/**
 * webkit_dom_dom_window_resize_by:
 * @self: A #WebKitDOMDOMWindow
 * @x: A #gfloat
 * @y: A #gfloat
 *
**/
WEBKIT_API void
webkit_dom_dom_window_resize_by(WebKitDOMDOMWindow* self, gfloat x, gfloat y);

/**
 * webkit_dom_dom_window_resize_to:
 * @self: A #WebKitDOMDOMWindow
 * @width: A #gfloat
 * @height: A #gfloat
 *
**/
WEBKIT_API void
webkit_dom_dom_window_resize_to(WebKitDOMDOMWindow* self, gfloat width, gfloat height);

/**
 * webkit_dom_dom_window_match_media:
 * @self: A #WebKitDOMDOMWindow
 * @query: A #gchar
 *
 * Returns: (transfer full): A #WebKitDOMMediaQueryList
**/
WEBKIT_API WebKitDOMMediaQueryList*
webkit_dom_dom_window_match_media(WebKitDOMDOMWindow* self, const gchar* query);

/**
 * webkit_dom_dom_window_get_computed_style:
 * @self: A #WebKitDOMDOMWindow
 * @element: A #WebKitDOMElement
 * @pseudoElement: (allow-none): A #gchar
 *
 * Returns: (transfer full): A #WebKitDOMCSSStyleDeclaration
**/
WEBKIT_API WebKitDOMCSSStyleDeclaration*
webkit_dom_dom_window_get_computed_style(WebKitDOMDOMWindow* self, WebKitDOMElement* element, const gchar* pseudoElement);

/**
 * webkit_dom_dom_window_webkit_convert_point_from_page_to_node:
 * @self: A #WebKitDOMDOMWindow
 * @node: A #WebKitDOMNode
 * @p: A #WebKitDOMWebKitPoint
 *
 * Returns: (transfer full): A #WebKitDOMWebKitPoint
**/
WEBKIT_API WebKitDOMWebKitPoint*
webkit_dom_dom_window_webkit_convert_point_from_page_to_node(WebKitDOMDOMWindow* self, WebKitDOMNode* node, WebKitDOMWebKitPoint* p);

/**
 * webkit_dom_dom_window_webkit_convert_point_from_node_to_page:
 * @self: A #WebKitDOMDOMWindow
 * @node: A #WebKitDOMNode
 * @p: A #WebKitDOMWebKitPoint
 *
 * Returns: (transfer full): A #WebKitDOMWebKitPoint
**/
WEBKIT_API WebKitDOMWebKitPoint*
webkit_dom_dom_window_webkit_convert_point_from_node_to_page(WebKitDOMDOMWindow* self, WebKitDOMNode* node, WebKitDOMWebKitPoint* p);

/**
 * webkit_dom_dom_window_cancel_animation_frame:
 * @self: A #WebKitDOMDOMWindow
 * @id: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_cancel_animation_frame(WebKitDOMDOMWindow* self, glong id);

/**
 * webkit_dom_dom_window_webkit_cancel_animation_frame:
 * @self: A #WebKitDOMDOMWindow
 * @id: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_webkit_cancel_animation_frame(WebKitDOMDOMWindow* self, glong id);

/**
 * webkit_dom_dom_window_webkit_cancel_request_animation_frame:
 * @self: A #WebKitDOMDOMWindow
 * @id: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_webkit_cancel_request_animation_frame(WebKitDOMDOMWindow* self, glong id);

#if !defined(WEBKIT_DISABLE_DEPRECATED)
/**
 * webkit_dom_dom_window_dispatch_event:
 * @self: A #WebKitDOMDOMWindow
 * @evt: A #WebKitDOMEvent
 * @error: #GError
 *
 * Returns: A #gboolean
 *
 * Deprecated: 2.4: Use webkit_dom_event_target_dispatch_event() instead.
**/
WEBKIT_DEPRECATED_FOR(webkit_dom_event_target_dispatch_event) gboolean
webkit_dom_dom_window_dispatch_event(WebKitDOMDOMWindow* self, WebKitDOMEvent* evt, GError** error);
#endif /* WEBKIT_DISABLE_DEPRECATED */

/**
 * webkit_dom_dom_window_capture_events:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_capture_events(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_release_events:
 * @self: A #WebKitDOMDOMWindow
 *
**/
WEBKIT_API void
webkit_dom_dom_window_release_events(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_atob:
 * @self: A #WebKitDOMDOMWindow
 * @string: A #gchar
 * @error: #GError
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_dom_window_atob(WebKitDOMDOMWindow* self, const gchar* string, GError** error);

/**
 * webkit_dom_dom_window_btoa:
 * @self: A #WebKitDOMDOMWindow
 * @string: A #gchar
 * @error: #GError
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_dom_window_btoa(WebKitDOMDOMWindow* self, const gchar* string, GError** error);

/**
 * webkit_dom_dom_window_clear_timeout:
 * @self: A #WebKitDOMDOMWindow
 * @handle: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_clear_timeout(WebKitDOMDOMWindow* self, glong handle);

/**
 * webkit_dom_dom_window_clear_interval:
 * @self: A #WebKitDOMDOMWindow
 * @handle: A #glong
 *
**/
WEBKIT_API void
webkit_dom_dom_window_clear_interval(WebKitDOMDOMWindow* self, glong handle);

/**
 * webkit_dom_dom_window_get_screen:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMScreen
**/
WEBKIT_API WebKitDOMScreen*
webkit_dom_dom_window_get_screen(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_history:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMHistory
**/
WEBKIT_API WebKitDOMHistory*
webkit_dom_dom_window_get_history(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_locationbar:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMBarProp
**/
WEBKIT_API WebKitDOMBarProp*
webkit_dom_dom_window_get_locationbar(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_menubar:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMBarProp
**/
WEBKIT_API WebKitDOMBarProp*
webkit_dom_dom_window_get_menubar(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_personalbar:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMBarProp
**/
WEBKIT_API WebKitDOMBarProp*
webkit_dom_dom_window_get_personalbar(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_scrollbars:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMBarProp
**/
WEBKIT_API WebKitDOMBarProp*
webkit_dom_dom_window_get_scrollbars(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_statusbar:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMBarProp
**/
WEBKIT_API WebKitDOMBarProp*
webkit_dom_dom_window_get_statusbar(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_toolbar:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMBarProp
**/
WEBKIT_API WebKitDOMBarProp*
webkit_dom_dom_window_get_toolbar(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_navigator:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMNavigator
**/
WEBKIT_API WebKitDOMNavigator*
webkit_dom_dom_window_get_navigator(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_client_information:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMNavigator
**/
WEBKIT_API WebKitDOMNavigator*
webkit_dom_dom_window_get_client_information(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_frame_element:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer none): A #WebKitDOMElement
**/
WEBKIT_API WebKitDOMElement*
webkit_dom_dom_window_get_frame_element(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_offscreen_buffering:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_window_get_offscreen_buffering(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_outer_height:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_outer_height(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_outer_width:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_outer_width(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_inner_height:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_inner_height(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_inner_width:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_inner_width(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_screen_x:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_screen_x(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_screen_y:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_screen_y(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_screen_left:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_screen_left(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_screen_top:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_screen_top(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_scroll_x:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_scroll_x(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_scroll_y:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_scroll_y(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_page_x_offset:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_page_x_offset(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_page_y_offset:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #glong
**/
WEBKIT_API glong
webkit_dom_dom_window_get_page_y_offset(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_closed:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_window_get_closed(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_length:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gulong
**/
WEBKIT_API gulong
webkit_dom_dom_window_get_length(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_name:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_dom_window_get_name(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_set_name:
 * @self: A #WebKitDOMDOMWindow
 * @value: A #gchar
 *
**/
WEBKIT_API void
webkit_dom_dom_window_set_name(WebKitDOMDOMWindow* self, const gchar* value);

/**
 * webkit_dom_dom_window_get_status:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_dom_window_get_status(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_set_status:
 * @self: A #WebKitDOMDOMWindow
 * @value: A #gchar
 *
**/
WEBKIT_API void
webkit_dom_dom_window_set_status(WebKitDOMDOMWindow* self, const gchar* value);

/**
 * webkit_dom_dom_window_get_default_status:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_dom_window_get_default_status(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_set_default_status:
 * @self: A #WebKitDOMDOMWindow
 * @value: A #gchar
 *
**/
WEBKIT_API void
webkit_dom_dom_window_set_default_status(WebKitDOMDOMWindow* self, const gchar* value);

/**
 * webkit_dom_dom_window_get_self:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindow
**/
WEBKIT_API WebKitDOMDOMWindow*
webkit_dom_dom_window_get_self(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_window:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindow
**/
WEBKIT_API WebKitDOMDOMWindow*
webkit_dom_dom_window_get_window(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_frames:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindow
**/
WEBKIT_API WebKitDOMDOMWindow*
webkit_dom_dom_window_get_frames(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_opener:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindow
**/
WEBKIT_API WebKitDOMDOMWindow*
webkit_dom_dom_window_get_opener(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_parent:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindow
**/
WEBKIT_API WebKitDOMDOMWindow*
webkit_dom_dom_window_get_parent(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_top:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindow
**/
WEBKIT_API WebKitDOMDOMWindow*
webkit_dom_dom_window_get_top(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_document:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer none): A #WebKitDOMDocument
**/
WEBKIT_API WebKitDOMDocument*
webkit_dom_dom_window_get_document(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_style_media:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMStyleMedia
**/
WEBKIT_API WebKitDOMStyleMedia*
webkit_dom_dom_window_get_style_media(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_device_pixel_ratio:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: A #gdouble
**/
WEBKIT_API gdouble
webkit_dom_dom_window_get_device_pixel_ratio(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_application_cache:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMApplicationCache
**/
WEBKIT_API WebKitDOMDOMApplicationCache*
webkit_dom_dom_window_get_application_cache(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_session_storage:
 * @self: A #WebKitDOMDOMWindow
 * @error: #GError
 *
 * Returns: (transfer full): A #WebKitDOMStorage
**/
WEBKIT_API WebKitDOMStorage*
webkit_dom_dom_window_get_session_storage(WebKitDOMDOMWindow* self, GError** error);

/**
 * webkit_dom_dom_window_get_local_storage:
 * @self: A #WebKitDOMDOMWindow
 * @error: #GError
 *
 * Returns: (transfer full): A #WebKitDOMStorage
**/
WEBKIT_API WebKitDOMStorage*
webkit_dom_dom_window_get_local_storage(WebKitDOMDOMWindow* self, GError** error);

/**
 * webkit_dom_dom_window_get_console:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer none): A #WebKitDOMConsole
**/
WEBKIT_API WebKitDOMConsole*
webkit_dom_dom_window_get_console(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_performance:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMPerformance
**/
WEBKIT_API WebKitDOMPerformance*
webkit_dom_dom_window_get_performance(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_css:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer full): A #WebKitDOMDOMWindowCSS
**/
WEBKIT_API WebKitDOMDOMWindowCSS*
webkit_dom_dom_window_get_css(WebKitDOMDOMWindow* self);

/**
 * webkit_dom_dom_window_get_webkit_storage_info:
 * @self: A #WebKitDOMDOMWindow
 *
 * Returns: (transfer none): A #WebKitDOMStorageInfo
**/
WEBKIT_API WebKitDOMStorageInfo*
webkit_dom_dom_window_get_webkit_storage_info(WebKitDOMDOMWindow* self);

G_END_DECLS

#endif /* WebKitDOMDOMWindow_h */
