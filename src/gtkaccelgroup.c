#include <gtk/gtk.h>

/* These functions are no more public in gtk-2.8.10 */

/* Note that gtk2 uses GObject for its internal functions.
   It requires some additional type casts. */

static guint		 quark_acceleratable_groups = 0;

static void
accel_group_weak_ref_detach (GSList    *free_list,
			     GtkObject *stale_object)
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
  g_object_set_qdata (G_OBJECT(stale_object), quark_acceleratable_groups, NULL);
}

void
gtk_accel_group_attach_2 (GtkAccelGroup *accel_group,
			  GtkObject     *object)
{
  GSList *slist;
  
  g_return_if_fail (GTK_IS_ACCEL_GROUP (accel_group));
  g_return_if_fail (G_IS_OBJECT (object));
  g_return_if_fail (g_slist_find (accel_group->acceleratables, object) == NULL);
  
  g_object_ref (accel_group);
  accel_group->acceleratables = g_slist_prepend (accel_group->acceleratables, object);
  slist = g_object_get_qdata (G_OBJECT(object), quark_acceleratable_groups);
  if (slist)
    g_object_weak_unref (G_OBJECT(object),
			 (GWeakNotify) accel_group_weak_ref_detach,
			 slist);
  slist = g_slist_prepend (slist, accel_group);
  g_object_set_qdata (G_OBJECT(object), quark_acceleratable_groups, slist);
  g_object_weak_ref (G_OBJECT(object),
		     (GWeakNotify) accel_group_weak_ref_detach,
		     slist);
}

void
gtk_accel_group_detach_2 (GtkAccelGroup *accel_group,
			  GtkObject     *object)
{
  GSList *slist;
  
  g_return_if_fail (GTK_IS_ACCEL_GROUP (accel_group));
  g_return_if_fail (G_IS_OBJECT (object));
  g_return_if_fail (g_slist_find (accel_group->acceleratables, object) != NULL);
  
  accel_group->acceleratables = g_slist_remove (accel_group->acceleratables, object);
  slist = g_object_get_qdata (G_OBJECT(object), quark_acceleratable_groups);
  g_object_weak_unref (G_OBJECT(object),
		       (GWeakNotify) accel_group_weak_ref_detach,
		       slist);
  slist = g_slist_remove (slist, accel_group);
  g_object_set_qdata (G_OBJECT(object), quark_acceleratable_groups, slist);
  if (slist)
    g_object_weak_ref (G_OBJECT(object),
		       (GWeakNotify) accel_group_weak_ref_detach,
		       slist);
  g_object_unref (accel_group);
}
