#!/bin/sh
# Run this to generate all initial makefiles, etc.
aclocal
libtoolize
automake --add-missing
autoconf
