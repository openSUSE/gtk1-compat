#ifndef __GTK1_COMPAT_GTKACCELGROUP_H__
#define __GTK1_COMPAT_GTKACCELGROUP_H__
#include_next <gtk/gtkaccelgroup.h>
#include <gtk/gtktypeutils.h>

/* note that gtk2 uses GObject for its internal functions */
G_BEGIN_DECLS
void		gtk_accel_group_attach_2	(GtkAccelGroup	*accel_group,
						 GtkObject	*object);
void		gtk_accel_group_detach_2	(GtkAccelGroup	*accel_group,
						 GtkObject	*object);
G_END_DECLS
#define gtk_accel_group_attach gtk_accel_group_attach_2
#define _gtk_accel_group_attach gtk_accel_group_attach_2
#define gtk_accel_group_detach gtk_accel_group_detach_2
#define _gtk_accel_group_detach gtk_accel_group_detach_2

#endif
