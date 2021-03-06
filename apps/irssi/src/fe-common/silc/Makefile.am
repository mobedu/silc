include $(top_srcdir)/Makefile.defines.in

moduledir = @SILC_IRSSIDIR@

IRSSI_INCLUDE=../../..

if SILCPLUGIN
EXTRA_CFLAGS=-DSILC_PLUGIN
NILB=
LTLB= libfe_common_silc.la
LDFLGS= \
	-avoid-version \
	-rpath $(moduledir)
else
EXTRA_CFLAGS=
NILB= libfe_common_silc.la
LTLB=
LDFLGS=
endif


ADD_INCLUDES = \
        $(GLIB_CFLAGS) \
        -DSYSCONFDIR=\""$(silc_etcdir)"\" \
        -I$(IRSSI_INCLUDE) -I$(IRSSI_INCLUDE)/src \
        -I$(IRSSI_INCLUDE)/src/core \
        -I$(IRSSI_INCLUDE)/src/fe-common/core \
        -I$(IRSSI_INCLUDE)/src/silc \
        -I$(IRSSI_INCLUDE)/src/silc/core \
        -I$(SILC_INCLUDE)/includes \
        -I$(SILC_INCLUDE)/lib/silccore \
        -I$(SILC_INCLUDE)/lib/silccrypt \
        -I$(SILC_INCLUDE)/lib/silcmath \
        -I$(SILC_INCLUDE)/lib/silcske \
        -I$(SILC_INCLUDE)/lib/silcsim \
        -I$(SILC_INCLUDE)/lib/silcutil \
        -I$(SILC_INCLUDE)/lib/silcapputil \
        -I$(SILC_INCLUDE)/lib/silcvcard \
        -I$(SILC_INCLUDE)/lib/silcskr \
        -I$(SILC_INCLUDE)/lib/silcsftp \
        -I$(SILC_INCLUDE)/lib/silcasn1 \
        -I$(SILC_INCLUDE)/lib/silchttp \
        -I$(SILC_INCLUDE)/lib/silcclient \
        -I$(SILC_INCLUDE)/lib/silcmath/gmp \
        -I$(SILC_INCLUDE)/lib/trq \
	$(EXTRA_CFLAGS)

noinst_LTLIBRARIES = $(NILB)
module_LTLIBRARIES = $(LTLB)

libfe_common_silc_la_LDFLAGS = \
	$(LDFLGS)

libfe_common_silc_la_SOURCES = \
	fe-silc-channels.c \
	fe-common-silc.c \
	module-formats.c \
	silc-modules.c \
	fe-silc-messages.c \
	fe-silcnet.c \
	fe-silc-queries.c

noinst_HEADERS = \
	module-formats.h \
	fe-silc-channels.h \
	fe-silc-messages.h \
	fe-silc-queries.h \
	fe-silcnet.h \
	fe-common-silc.h \
	module.h

all-local: libfe_common_silc.a

clean-local:
	-rm -f libfe_common_silc.a

libfe_common_silc.a: libfe_common_silc.la
	cp .libs/libfe_common_silc.a .

if SILCPLUGIN
install-data-hook: libfe_common_silc.la
	-ln -s libfe_common_silc.so $(DESTDIR)$(moduledir)/libfe_silc.so
endif
