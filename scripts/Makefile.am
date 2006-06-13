bin_SCRIPTS = \
	glib-config \
	gtk-config \
	gdk-pixbuf-config \
	libglade-config \
	gtk1-compat-autofix \
	libglade-xgettext

install-exec-local:
	$(mkdir_p) $(DESTDIR)$(bindir)
	$(LN_S) xml2-config $(DESTDIR)$(bindir)/xml-config

uninstall-local:
	rm $(DESTDIR)$(bindir)/xml-config

EXTRA_DIST = $(bin_SCRIPTS)
