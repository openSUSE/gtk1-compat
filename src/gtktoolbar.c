#include <gtk/gtk.h>

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
