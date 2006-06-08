#ifndef __GTK1_COMPAT_GDK_PIXBUF_CORE_H__
#define __GTK1_COMPAT_GDK_PIXBUF_CORE_H__
#include_next <gdk-pixbuf/gdk-pixbuf-core.h>
#define gdk_pixbuf_new_from_file_1 gdk_pixbuf_new_from_file
#define gdk_pixbuf_new_from_file(filename) gdk_pixbuf_new_from_file_1 (filename, NULL)
#endif
