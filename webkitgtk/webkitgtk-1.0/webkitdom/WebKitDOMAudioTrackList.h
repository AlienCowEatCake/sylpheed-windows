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

#ifndef WebKitDOMAudioTrackList_h
#define WebKitDOMAudioTrackList_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_AUDIO_TRACK_LIST            (webkit_dom_audio_track_list_get_type())
#define WEBKIT_DOM_AUDIO_TRACK_LIST(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_AUDIO_TRACK_LIST, WebKitDOMAudioTrackList))
#define WEBKIT_DOM_AUDIO_TRACK_LIST_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_AUDIO_TRACK_LIST, WebKitDOMAudioTrackListClass)
#define WEBKIT_DOM_IS_AUDIO_TRACK_LIST(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_AUDIO_TRACK_LIST))
#define WEBKIT_DOM_IS_AUDIO_TRACK_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_AUDIO_TRACK_LIST))
#define WEBKIT_DOM_AUDIO_TRACK_LIST_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_AUDIO_TRACK_LIST, WebKitDOMAudioTrackListClass))

struct _WebKitDOMAudioTrackList {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMAudioTrackListClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_audio_track_list_get_type (void);

/**
 * webkit_dom_audio_track_list_item:
 * @self: A #WebKitDOMAudioTrackList
 * @index: A #gulong
 *
 * Returns: (transfer full): A #WebKitDOMAudioTrack
**/
WEBKIT_API WebKitDOMAudioTrack*
webkit_dom_audio_track_list_item(WebKitDOMAudioTrackList* self, gulong index);

/**
 * webkit_dom_audio_track_list_get_track_by_id:
 * @self: A #WebKitDOMAudioTrackList
 * @id: A #gchar
 *
 * Returns: (transfer full): A #WebKitDOMAudioTrack
**/
WEBKIT_API WebKitDOMAudioTrack*
webkit_dom_audio_track_list_get_track_by_id(WebKitDOMAudioTrackList* self, const gchar* id);

#if !defined(WEBKIT_DISABLE_DEPRECATED)
/**
 * webkit_dom_audio_track_list_dispatch_event:
 * @self: A #WebKitDOMAudioTrackList
 * @evt: A #WebKitDOMEvent
 * @error: #GError
 *
 * Returns: A #gboolean
 *
 * Deprecated: 2.4: Use webkit_dom_event_target_dispatch_event() instead.
**/
WEBKIT_DEPRECATED_FOR(webkit_dom_event_target_dispatch_event) gboolean
webkit_dom_audio_track_list_dispatch_event(WebKitDOMAudioTrackList* self, WebKitDOMEvent* evt, GError** error);
#endif /* WEBKIT_DISABLE_DEPRECATED */

/**
 * webkit_dom_audio_track_list_get_length:
 * @self: A #WebKitDOMAudioTrackList
 *
 * Returns: A #gulong
**/
WEBKIT_API gulong
webkit_dom_audio_track_list_get_length(WebKitDOMAudioTrackList* self);

G_END_DECLS

#endif /* WebKitDOMAudioTrackList_h */