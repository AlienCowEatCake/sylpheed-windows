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

#ifndef WebKitDOMWebKitPoint_h
#define WebKitDOMWebKitPoint_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_WEBKIT_POINT            (webkit_dom_webkit_point_get_type())
#define WEBKIT_DOM_WEBKIT_POINT(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_WEBKIT_POINT, WebKitDOMWebKitPoint))
#define WEBKIT_DOM_WEBKIT_POINT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_WEBKIT_POINT, WebKitDOMWebKitPointClass)
#define WEBKIT_DOM_IS_WEBKIT_POINT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_WEBKIT_POINT))
#define WEBKIT_DOM_IS_WEBKIT_POINT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_WEBKIT_POINT))
#define WEBKIT_DOM_WEBKIT_POINT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_WEBKIT_POINT, WebKitDOMWebKitPointClass))

struct _WebKitDOMWebKitPoint {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMWebKitPointClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_webkit_point_get_type (void);

/**
 * webkit_dom_webkit_point_get_x:
 * @self: A #WebKitDOMWebKitPoint
 *
 * Returns: A #gfloat
**/
WEBKIT_API gfloat
webkit_dom_webkit_point_get_x(WebKitDOMWebKitPoint* self);

/**
 * webkit_dom_webkit_point_set_x:
 * @self: A #WebKitDOMWebKitPoint
 * @value: A #gfloat
 *
**/
WEBKIT_API void
webkit_dom_webkit_point_set_x(WebKitDOMWebKitPoint* self, gfloat value);

/**
 * webkit_dom_webkit_point_get_y:
 * @self: A #WebKitDOMWebKitPoint
 *
 * Returns: A #gfloat
**/
WEBKIT_API gfloat
webkit_dom_webkit_point_get_y(WebKitDOMWebKitPoint* self);

/**
 * webkit_dom_webkit_point_set_y:
 * @self: A #WebKitDOMWebKitPoint
 * @value: A #gfloat
 *
**/
WEBKIT_API void
webkit_dom_webkit_point_set_y(WebKitDOMWebKitPoint* self, gfloat value);

G_END_DECLS

#endif /* WebKitDOMWebKitPoint_h */
