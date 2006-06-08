#include <gtk/gtk.h>

/* These functions are no more public in gtk-2.8.10 */

static guint		 quark_acceleratable_groups = 0;

static void
accel_group_weak_ref_detach (GSList  *free_list,
			     GObject *stale_object)
{
  GSList *slist;
  
  for (slist = free_list; slist; slist = slist->next)
    {
      GtkAccelGroup *accel_group;
      
      accel_group = slist->data;
      accel_group->acceleratables = g_slist_remove (accel_group->acceleratables, stale_object);
      g_object_unref (accel_group);
    }
  g_slist_free (free_list);
  g_object_set_qdata (stale_object, quark_acceleratable_groups, NULL);
}

void
gtk_accel_group_attach_2 (GtkAccelGroup *accel_group,
			 GObject       *object)
{
  GSList *slist;
  
  g_return_if_fail (GTK_IS_ACCEL_GROUP (accel_group));
  g_return_if_fail (G_IS_OBJECT (object));
  g_return_if_fail (g_slist_find (accel_group->acceleratables, object) == NULL);
  
  g_object_ref (accel_group);
  accel_group->acceleratables = g_slist_prepend (accel_group->acceleratables, object);
  slist = g_object_get_qdata (object, quark_acceleratable_groups);
  if (slist)
    g_object_weak_unref (object,
			 (GWeakNotify) accel_group_weak_ref_detach,
			 slist);
  slist = g_slist_prepend (slist, accel_group);
  g_object_set_qdata (object, quark_acceleratable_groups, slist);
  g_object_weak_ref (object,
		     (GWeakNotify) accel_group_weak_ref_detach,
		     slist);
}

void
gtk_accel_group_detach_2 (GtkAccelGroup *accel_group,
			 GObject       *object)
{
  GSList *slist;
  
  g_return_if_fail (GTK_IS_ACCEL_GROUP (accel_group));
  g_return_if_fail (G_IS_OBJECT (object));
  g_return_if_fail (g_slist_find (accel_group->acceleratables, object) != NULL);
  
  accel_group->acceleratables = g_slist_remove (accel_group->acceleratables, object);
  slist = g_object_get_qdata (object, quark_acceleratable_groups);
  g_object_weak_unref (object,
		       (GWeakNotify) accel_group_weak_ref_detach,
		       slist);
  slist = g_slist_remove (slist, accel_group);
  g_object_set_qdata (object, quark_acceleratable_groups, slist);
  if (slist)
    g_object_weak_ref (object,
		       (GWeakNotify) accel_group_weak_ref_detach,
		       slist);
  g_object_unref (accel_group);
}

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

/* reimplementation of gtk1 behavior using gtk2 functions */

GtkWidget*
gtk_toolbar_new_1 (GtkOrientation   orientation,
		   GtkToolbarStyle  style) {
    GtkWidget *toolbar;
    toolbar = gtk_toolbar_new ();
    if (toolbar) {
	gtk_toolbar_set_orientation (GTK_TOOLBAR (toolbar), orientation);
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), style);
    }
    return toolbar;
}
