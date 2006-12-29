AC_INIT([gtk1-compat],[0.10],[http://bugzilla.novell.com/])
AM_INIT_AUTOMAKE([dist-bzip2 no-dist-gzip])

AC_PROG_CC
AC_PROG_LIBTOOL

PKG_CHECK_MODULES([GTK2],[gtk+-2.0])
AC_CONFIG_FILES([
gtk1-compat.pc
Makefile
include/Makefile
m4macros/Makefile
scripts/Makefile
src/Makefile
])
AC_OUTPUT
