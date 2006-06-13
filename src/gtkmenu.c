#include <gtk/gtk.h>

/* Cut and Paste from gtk-1.2.10 */

static GQuark             quark_uline_accel_group = 0;

GtkAccelGroup*
gtk_menu_ensure_uline_accel_group (GtkMenu *menu)
{
  GtkAccelGroup *accel_group;

  g_return_val_if_fail (GTK_IS_MENU (menu), NULL);

  if (!quark_uline_accel_group)
    quark_uline_accel_group = g_quark_from_static_string ("GtkMenu-uline-accel-group");

  accel_group = gtk_object_get_data_by_id (GTK_OBJECT (menu), quark_uline_accel_group);
  if (!accel_group)
    {
      accel_group = gtk_accel_group_new ();
      /* Changed to conform internal GTK+2 function */
      gtk_accel_group_attach_2 (accel_group, G_OBJECT(menu));
      gtk_object_set_data_by_id_full (GTK_OBJECT (menu),
				      quark_uline_accel_group,
				      accel_group,
				      (GtkDestroyNotify) gtk_accel_group_unref);
    }

  return accel_group;
}

GtkAccelGroup*
gtk_menu_get_uline_accel_group (GtkMenu *menu)
{
  g_return_val_if_fail (GTK_IS_MENU (menu), NULL);

  return gtk_object_get_data_by_id (GTK_OBJECT (menu), quark_uline_accel_group);
}
