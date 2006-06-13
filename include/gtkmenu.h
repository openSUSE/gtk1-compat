#ifndef __GTK1_COMPAT_GTKMENU_H__
#define __GTK1_COMPAT_GTKMENU_H__
#include_next <gtk/gtkmenu.h>

G_BEGIN_DECLS
GtkAccelGroup* gtk_menu_get_uline_accel_group    (GtkMenu         *menu);
GtkAccelGroup* gtk_menu_ensure_uline_accel_group (GtkMenu         *menu);
G_END_DECLS

#endif
