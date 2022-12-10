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

#ifndef WebKitDOMDOMMimeTypeArray_h
#define WebKitDOMDOMMimeTypeArray_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_DOM_MIME_TYPE_ARRAY            (webkit_dom_dom_mime_type_array_get_type())
#define WEBKIT_DOM_DOM_MIME_TYPE_ARRAY(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_DOM_MIME_TYPE_ARRAY, WebKitDOMDOMMimeTypeArray))
#define WEBKIT_DOM_DOM_MIME_TYPE_ARRAY_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_DOM_MIME_TYPE_ARRAY, WebKitDOMDOMMimeTypeArrayClass)
#define WEBKIT_DOM_IS_DOM_MIME_TYPE_ARRAY(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_DOM_MIME_TYPE_ARRAY))
#define WEBKIT_DOM_IS_DOM_MIME_TYPE_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_DOM_MIME_TYPE_ARRAY))
#define WEBKIT_DOM_DOM_MIME_TYPE_ARRAY_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_DOM_MIME_TYPE_ARRAY, WebKitDOMDOMMimeTypeArrayClass))

struct _WebKitDOMDOMMimeTypeArray {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMDOMMimeTypeArrayClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_dom_mime_type_array_get_type (void);

/**
 * webkit_dom_dom_mime_type_array_item:
 * @self: A #WebKitDOMDOMMimeTypeArray
 * @index: A #gulong
 *
 * Returns: (transfer full): A #WebKitDOMDOMMimeType
**/
WEBKIT_API WebKitDOMDOMMimeType*
webkit_dom_dom_mime_type_array_item(WebKitDOMDOMMimeTypeArray* self, gulong index);

/**
 * webkit_dom_dom_mime_type_array_named_item:
 * @self: A #WebKitDOMDOMMimeTypeArray
 * @name: A #gchar
 *
 * Returns: (transfer full): A #WebKitDOMDOMMimeType
**/
WEBKIT_API WebKitDOMDOMMimeType*
webkit_dom_dom_mime_type_array_named_item(WebKitDOMDOMMimeTypeArray* self, const gchar* name);

/**
 * webkit_dom_dom_mime_type_array_get_length:
 * @self: A #WebKitDOMDOMMimeTypeArray
 *
 * Returns: A #gulong
**/
WEBKIT_API gulong
webkit_dom_dom_mime_type_array_get_length(WebKitDOMDOMMimeTypeArray* self);

G_END_DECLS

#endif /* WebKitDOMDOMMimeTypeArray_h */
