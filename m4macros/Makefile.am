m4_STATIC_FILES = \
	glib.m4 \
	gdk-pixbuf.m4 \
	libglade.m4

m4_GENERATED_FILES = \
	gtk.m4

m4datadir = $(datadir)/aclocal
m4data_DATA = \
	$(m4_STATIC_FILES) \
	$(m4_GENERATED_FILES)

gtk.m4: gtk_m4.patch
	for DIR in $$ACLOCAL_PATH $$(</usr/share/aclocal/dirlist) ; do \
	if test $$DIR/gtk-2.0.m4 ; then \
	cp -a $$DIR/gtk-2.0.m4 gtk.m4 ;\
	break ;\
	fi ;\
	done
	patch <$(srcdir)/gtk_m4.patch

EXTRA_DIST = \
	$(m4_STATIC_FILES) \
	gtk_m4.patch

DISTCLEANFILES = \
	$(m4_GENERATED_FILES)
