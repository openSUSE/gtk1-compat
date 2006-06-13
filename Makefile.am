SUBDIRS = include m4macros scripts src

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gtk1-compat.pc
$(pkgconfig_DATA): config.status

install-data-local:
	$(mkdir_p) $(DESTDIR)$(libdir)/pkgconfig
	$(LN_S) libxml-2.0.pc $(DESTDIR)$(libdir)/pkgconfig/libxml.pc

uninstall-local:
	rm $(DESTDIR)$(libdir)/pkgconfig/libxml.pc
