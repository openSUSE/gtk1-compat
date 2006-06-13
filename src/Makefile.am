lib_LIBRARIES = libgtk1-compat.a

INCLUDES = $(GTK2_CFLAGS)

libgtk1_compat_a_SOURCES = \
	gtkaccelgroup.c \
	gtkmenu.c \
	gtktoolbar.c

install-exec-local:
	$(mkdir_p) $(DESTDIR)$(libdir)
	$(LN_S) libgtk-x11-2.0.so $(DESTDIR)$(libdir)/libgtk.so
	$(LN_S) libgtk-x11-2.0.la $(DESTDIR)$(libdir)/libgtk.la
	$(LN_S) libgtk-x11-2.0.so $(DESTDIR)$(libdir)/libgdk-pixbuf.so
	$(LN_S) libgtk-x11-2.0.la $(DESTDIR)$(libdir)/libgdk-pixbuf.la
	$(LN_S) libglade-2.0.so $(DESTDIR)$(libdir)/libglade.so
	$(LN_S) libglade-2.0.la $(DESTDIR)$(libdir)/libglade.la
	$(LN_S) libglade-2.0.a $(DESTDIR)$(libdir)/libglade.a
	$(LN_S) libxml2.so $(DESTDIR)$(libdir)/libxml.so
	$(LN_S) libxml2.la $(DESTDIR)$(libdir)/libxml.la
	$(LN_S) libxml2.a $(DESTDIR)$(libdir)/libxml.a

uninstall-local:
	rm $(DESTDIR)$(libdir)/libgtk.so
	rm $(DESTDIR)$(libdir)/libgtk.la
	rm $(DESTDIR)$(libdir)/libgdk-pixbuf.so
	rm $(DESTDIR)$(libdir)/libgdk-pixbuf.la
	rm $(DESTDIR)$(libdir)/libglade.so
	rm $(DESTDIR)$(libdir)/libglade.la
	rm $(DESTDIR)$(libdir)/libglade.a
	rm $(DESTDIR)$(libdir)/libxml.so
	rm $(DESTDIR)$(libdir)/libxml.la
	rm $(DESTDIR)$(libdir)/libxml.a
