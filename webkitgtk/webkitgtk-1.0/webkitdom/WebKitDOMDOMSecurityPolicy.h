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

#ifndef WebKitDOMDOMSecurityPolicy_h
#define WebKitDOMDOMSecurityPolicy_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_DOM_SECURITY_POLICY            (webkit_dom_dom_security_policy_get_type())
#define WEBKIT_DOM_DOM_SECURITY_POLICY(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_DOM_SECURITY_POLICY, WebKitDOMDOMSecurityPolicy))
#define WEBKIT_DOM_DOM_SECURITY_POLICY_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_DOM_SECURITY_POLICY, WebKitDOMDOMSecurityPolicyClass)
#define WEBKIT_DOM_IS_DOM_SECURITY_POLICY(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_DOM_SECURITY_POLICY))
#define WEBKIT_DOM_IS_DOM_SECURITY_POLICY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_DOM_SECURITY_POLICY))
#define WEBKIT_DOM_DOM_SECURITY_POLICY_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_DOM_SECURITY_POLICY, WebKitDOMDOMSecurityPolicyClass))

struct _WebKitDOMDOMSecurityPolicy {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMDOMSecurityPolicyClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_dom_security_policy_get_type (void);

/**
 * webkit_dom_dom_security_policy_allows_connection_to:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_connection_to(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_font_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_font_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_form_action:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_form_action(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_frame_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_frame_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_image_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_image_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_media_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_media_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_object_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_object_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_plugin_type:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @type: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_plugin_type(WebKitDOMDOMSecurityPolicy* self, const gchar* type);

/**
 * webkit_dom_dom_security_policy_allows_script_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_script_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_allows_style_from:
 * @self: A #WebKitDOMDOMSecurityPolicy
 * @url: A #gchar
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_allows_style_from(WebKitDOMDOMSecurityPolicy* self, const gchar* url);

/**
 * webkit_dom_dom_security_policy_get_allows_eval:
 * @self: A #WebKitDOMDOMSecurityPolicy
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_get_allows_eval(WebKitDOMDOMSecurityPolicy* self);

/**
 * webkit_dom_dom_security_policy_get_allows_inline_script:
 * @self: A #WebKitDOMDOMSecurityPolicy
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_get_allows_inline_script(WebKitDOMDOMSecurityPolicy* self);

/**
 * webkit_dom_dom_security_policy_get_allows_inline_style:
 * @self: A #WebKitDOMDOMSecurityPolicy
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_get_allows_inline_style(WebKitDOMDOMSecurityPolicy* self);

/**
 * webkit_dom_dom_security_policy_get_is_active:
 * @self: A #WebKitDOMDOMSecurityPolicy
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_dom_security_policy_get_is_active(WebKitDOMDOMSecurityPolicy* self);

/**
 * webkit_dom_dom_security_policy_get_report_ur_is:
 * @self: A #WebKitDOMDOMSecurityPolicy
 *
 * Returns: (transfer full): A #WebKitDOMDOMStringList
**/
WEBKIT_API WebKitDOMDOMStringList*
webkit_dom_dom_security_policy_get_report_ur_is(WebKitDOMDOMSecurityPolicy* self);

G_END_DECLS

#endif /* WebKitDOMDOMSecurityPolicy_h */
