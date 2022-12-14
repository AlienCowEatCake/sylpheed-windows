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

#ifndef WebKitDOMLocation_h
#define WebKitDOMLocation_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_LOCATION            (webkit_dom_location_get_type())
#define WEBKIT_DOM_LOCATION(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_LOCATION, WebKitDOMLocation))
#define WEBKIT_DOM_LOCATION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_LOCATION, WebKitDOMLocationClass)
#define WEBKIT_DOM_IS_LOCATION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_LOCATION))
#define WEBKIT_DOM_IS_LOCATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_LOCATION))
#define WEBKIT_DOM_LOCATION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_LOCATION, WebKitDOMLocationClass))

struct _WebKitDOMLocation {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMLocationClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_location_get_type (void);

/**
 * webkit_dom_location_get_href:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_href(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_protocol:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_protocol(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_host:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_host(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_hostname:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_hostname(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_port:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_port(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_pathname:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_pathname(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_search:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_search(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_hash:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_hash(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_origin:
 * @self: A #WebKitDOMLocation
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_location_get_origin(WebKitDOMLocation* self);

/**
 * webkit_dom_location_get_ancestor_origins:
 * @self: A #WebKitDOMLocation
 *
 * Returns: (transfer full): A #WebKitDOMDOMStringList
**/
WEBKIT_API WebKitDOMDOMStringList*
webkit_dom_location_get_ancestor_origins(WebKitDOMLocation* self);

G_END_DECLS

#endif /* WebKitDOMLocation_h */