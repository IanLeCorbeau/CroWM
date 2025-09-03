# Edit to fit your distro

PROG		= crowm
VERSION		= 0.1

# Used in the 'dist' target.
PKG		= ${PROG}-${VERSION}

PREFIX		= /usr
MANPREFIX	= ${PREFIX}/share/man

X11INC		= /usr/X11R6/include
X11LIBS		= /usr/X11R6/lib

# freetype
FREETYPEINC	= /usr/include/freetype2
# uncomment on OpenBSD
#FREETYPEINC	= ${X11INC}/freetype2
#MANPREFIX	= ${PREFIX}/man

CPPFLAGS	+= -I${X11INC} -I${FREETYPEINC}

CFLAGS		+= -Wall -O2 -D_GNU_SOURCE

LDFLAGS		+= -L${X11LIBS} -lXft -lX11 -lXau -lXdmcp \
		   -lfontconfig -lexpat -lfreetype -lz -lXrandr -lXext

# Change to whatever yacc implementation is installed.
YACC		= /usr/bin/oyacc

#CC		= cc
