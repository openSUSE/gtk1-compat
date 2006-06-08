AC_DEFUN([AM_PATH_LIBGLADE],
[dnl
  PKG_CHECK_MODULES([LIBGLADE2],[libglade-2.0],[$1],[$2],[$3])
  if test -z "$GTK1_COMPAT_DISABLE_C_SUPPORT" ; then
    LIBGLADE_CFLAGS="-I/opt/gnome/include/gtk1-compat $LIBGLADE2_CFLAGS"
  else
    LIBGLADE_CFLAGS="$LIBGLADE2_CFLAGS"
  fi
  LIBGLADE_LIBS="$LIBGLADE2_LIBS"
])
