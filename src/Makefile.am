AM_CFLAGS = $(MCE_CFLAGS) $(OSSO_CFLAGS) $(GLIB_CFLAGS) $(DBUS_CFLAGS) \
	    -I$(top_srcdir) -I$(top_srcdir)/src

AM_CPPFLAGS = \
	-DPREFIX=\"${prefix}\" \
	-DOSSO_CTRLPANELPLUGINDIR=\"${prefix}/lib/hildon-control-panel\"

lib_LTLIBRARIES = libosso.la

libosso_la_LIBADD = -ldl -lc $(MCE_LIBS) $(GTHREAD_LIBS) $(GLIB_LIBS) \
		    $(DBUS_LIBS)
libosso_la_LDFLAGS = -version-info 4:0:3

ossoincludedir=$(includedir)
ossoinclude_HEADERS = libosso.h osso-log.h log-functions.h osso-mem.h muali.h osso-fpu.h

libosso_la_SOURCES = \
	osso-state.c \
	osso-state.h \
	osso-init.c \
	osso-init.h \
	osso-application-top.h \
	osso-application-top.c \
	osso-application-autosave.c \
	osso-hw.c \
	osso-hw.h \
	osso-mime.c \
	osso-system-note.c \
	libosso.h \
	log-functions.h \
	osso-internal.h \
	osso-rpc.c \
	osso-statusbar.c \
	osso-log.h \
	osso-cp-plugin.c \
	osso-cp-plugin.h \
	osso-log.c \
	osso-time.c \
	osso-time.h \
	osso-locale.c \
	osso-locale.h \
	osso-display.c \
	osso-display.h \
	osso-application-init.c \
	osso-mem.h \
	osso-mem.c \
	osso-fpu.h \
	osso-fpu.c \
	muali.h \
        deprecated.c
