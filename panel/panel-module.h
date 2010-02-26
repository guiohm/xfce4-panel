/* $Id$ */
/*
 * Copyright (C) 2008 Nick Schermer <nick@xfce.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __PANEL_MODULE_H__
#define __PANEL_MODULE_H__

#include <gtk/gtk.h>
#include <libxfce4panel/libxfce4panel.h>
#include <libxfce4panel/xfce-panel-plugin-provider.h>

G_BEGIN_DECLS

typedef struct _PanelModuleClass PanelModuleClass;
typedef struct _PanelModule      PanelModule;

#define PANEL_TYPE_MODULE            (panel_module_get_type ())
#define PANEL_MODULE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), PANEL_TYPE_MODULE, PanelModule))
#define PANEL_MODULE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), PANEL_TYPE_MODULE, PanelModuleClass))
#define PANEL_IS_MODULE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PANEL_TYPE_MODULE))
#define PANEL_IS_MODULE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PANEL_TYPE_MODULE))
#define PANEL_MODULE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), PANEL_TYPE_MODULE, PanelModuleClass))



GType                    panel_module_get_type              (void) G_GNUC_CONST;

PanelModule             *panel_module_new_from_desktop_file (const gchar  *filename,
                                                             const gchar  *name);

XfcePanelPluginProvider *panel_module_create_plugin         (PanelModule  *module,
                                                             GdkScreen    *screen,
                                                             const gchar  *name,
                                                             const gchar  *id,
                                                             gchar       **arguments);

const gchar             *panel_module_get_internal_name     (PanelModule  *module);

const gchar             *panel_module_get_library_filename  (PanelModule  *module);

const gchar             *panel_module_get_name              (PanelModule  *module);

const gchar             *panel_module_get_comment           (PanelModule  *module);

const gchar             *panel_module_get_icon_name         (PanelModule  *module);

gboolean                 panel_module_is_valid              (PanelModule  *module);

gboolean                 panel_module_is_usable             (PanelModule  *module);

G_END_DECLS

#endif /* !__PANEL_MODULE_H__ */
