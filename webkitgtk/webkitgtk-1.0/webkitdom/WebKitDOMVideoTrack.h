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

#ifndef WebKitDOMVideoTrack_h
#define WebKitDOMVideoTrack_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_TYPE_DOM_VIDEO_TRACK            (webkit_dom_video_track_get_type())
#define WEBKIT_DOM_VIDEO_TRACK(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_VIDEO_TRACK, WebKitDOMVideoTrack))
#define WEBKIT_DOM_VIDEO_TRACK_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_VIDEO_TRACK, WebKitDOMVideoTrackClass)
#define WEBKIT_DOM_IS_VIDEO_TRACK(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_VIDEO_TRACK))
#define WEBKIT_DOM_IS_VIDEO_TRACK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_VIDEO_TRACK))
#define WEBKIT_DOM_VIDEO_TRACK_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_VIDEO_TRACK, WebKitDOMVideoTrackClass))

struct _WebKitDOMVideoTrack {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMVideoTrackClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_video_track_get_type (void);

/**
 * webkit_dom_video_track_get_id:
 * @self: A #WebKitDOMVideoTrack
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_video_track_get_id(WebKitDOMVideoTrack* self);

/**
 * webkit_dom_video_track_get_kind:
 * @self: A #WebKitDOMVideoTrack
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_video_track_get_kind(WebKitDOMVideoTrack* self);

/**
 * webkit_dom_video_track_get_label:
 * @self: A #WebKitDOMVideoTrack
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_video_track_get_label(WebKitDOMVideoTrack* self);

/**
 * webkit_dom_video_track_get_language:
 * @self: A #WebKitDOMVideoTrack
 *
 * Returns: A #gchar
**/
WEBKIT_API gchar*
webkit_dom_video_track_get_language(WebKitDOMVideoTrack* self);

/**
 * webkit_dom_video_track_get_selected:
 * @self: A #WebKitDOMVideoTrack
 *
 * Returns: A #gboolean
**/
WEBKIT_API gboolean
webkit_dom_video_track_get_selected(WebKitDOMVideoTrack* self);

/**
 * webkit_dom_video_track_set_selected:
 * @self: A #WebKitDOMVideoTrack
 * @value: A #gboolean
 *
**/
WEBKIT_API void
webkit_dom_video_track_set_selected(WebKitDOMVideoTrack* self, gboolean value);

G_END_DECLS

#endif /* WebKitDOMVideoTrack_h */
