# Makefile for cwm
# $Ragnarok$

include config.mk

SRCS=		calmwm.c screen.c xmalloc.c client.c menu.c \
		search.c util.c xutil.c conf.c xevents.c group.c \
		kbfunc.c parse.y

OBJS=		calmwm.o screen.o xmalloc.o client.o menu.o \
		search.o util.o xutil.o conf.o xevents.o group.o \
		kbfunc.o strlcpy.o strlcat.o parse.o \
		strtonum.o reallocarray.o

all: ${PROG}

clean:
	rm -f ${OBJS} ${PROG} parse.c

${PROG}: ${OBJS}
	${CC} ${OBJS} ${LDFLAGS} -o ${PROG}

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

install: ${PROG}
	install -d ${DESTDIR}${PREFIX}/bin ${DESTDIR}${MANPREFIX}/man1 ${DESTDIR}${MANPREFIX}/man5
	install -m 755 cwm ${DESTDIR}${PREFIX}/bin
	install -m 644 cwm.1 ${DESTDIR}${MANPREFIX}/man1
	install -m 644 cwmrc.5 ${DESTDIR}${MANPREFIX}/man5

deb: all
	/usr/bin/equivs-build cwm.pkg

.PRECIOUS: parse.c
