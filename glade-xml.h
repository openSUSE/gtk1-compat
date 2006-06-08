#ifndef __GTK1_COMPAT_GLADE_XML_H__
#define __GTK1_COMPAT_GLADE_XML_H__
#include_next <glade/glade-xml.h>
#define glade_xml_new_1 glade_xml_new
#define glade_xml_new(fname,root) glade_xml_new_1 (fname, root, NULL)
#endif
