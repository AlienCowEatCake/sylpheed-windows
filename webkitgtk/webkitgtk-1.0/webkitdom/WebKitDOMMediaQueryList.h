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

#ifndef WebKitDOMMediaQueryList_h
#define WebKitDOMMediaQueryList_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_MEDIA_QUERY_LIST            (webkit_dom_media_query_list_get_type())
#define WEBKIT_DOM_MEDIA_QUERY_LIST(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_MEDIA_QUERY_LIST, WebKitDOMMediaQueryList))
#define WEBKIT_DOM_MEDIA_QUERY_LIST_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_MEDIA_QUERY_LIST, WebKitDOMMediaQueryListClass)
#define WEBKIT_DOM_IS_MEDIA_QUERY_LIST(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_MEDIA_QUERY_LIST))
#define WEBKIT_DOM_IS_MEDIA_QUERY_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_MEDIA_QUERY_LIST))
#define WEBKIT_DOM_MEDIA_QUERY_LIST_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_MEDIA_QUERY_LIST, WebKitDOMMediaQueryListClass))

struct _WebKitDOMMediaQueryList {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMMediaQueryListClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_media_query_list_get_type (void);

/**
 * webkit_dom_media_query_list_get_media:
 * @self: A #WebKitDOMMediaQueryList
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_media_query_list_get_media(WebKitDOMMediaQueryList* self);

/**
 * webkit_dom_media_query_list_get_matches:
 * @self: A #WebKitDOMMediaQueryList
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_media_query_list_get_matches(WebKitDOMMediaQueryList* self);

G_END_DECLS

#endif /* WebKitDOMMediaQueryList_h */
