# Edit to fit your distro

PROG		= cwm
VERSION		= 

PREFIX		= /usr
MANPREFIX	= ${PREFIX}/share/man

X11BASE		= /usr

CPPFLAGS	+= -I${X11BASE}/include -I${X11BASE}/include/freetype2

CFLAGS		+= -Wall -O2 -D_GNU_SOURCE

LDFLAGS		+= -L${X11BASE}/lib -lXft -lfreetype -lX11-xcb -lX11 -lxcb \
		   -lXau -lXdmcp -lfontconfig -lexpat -lfreetype -lz -lXrandr -lXext

#CC		= cc
