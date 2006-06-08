#ifndef __GTK1_COMPAT_GDK_PIXBUF_LOADER_H__
#define __GTK1_COMPAT_GDK_PIXBUF_LOADER_H__
#include_next <gdk-pixbuf/gdk-pixbuf-loader.h>
#define gdk_pixbuf_loader_write_1 gdk_pixbuf_loader_write
#define gdk_pixbuf_loader_write(loader,buf,count) gdk_pixbuf_loader_write_1 (loader, buf, count, NULL)
#define gdk_pixbuf_loader_close_1 gdk_pixbuf_loader_close
#define gdk_pixbuf_loader_close(loader) gdk_pixbuf_loader_close_1 (loader, NULL)
#endif
