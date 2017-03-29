PREFIX =
BINDIR = ${PREFIX}/bin
DESTDIR =

CC = gcc
CFLAGS = -g -std=gnu99 -Os -Wall -Wextra

SUIDROOT = ipmitoolsellist ipmitoollanprint

all: ${SUIDROOT}

ipmitoolsellist: ipmitoolsellist.o

ipmitoollanprint: ipmitoollanprint.o

clean:
	rm -f -- ${SUIDROOT} tags *.o

install: ${SUIDROOT}
	mkdir -p ${DESTDIR}${BINDIR}
	install -g root -m 4755 -o root -s ${SUIDROOT} ${DESTDIR}${BINDIR}

tags:
	ctags -R

.PHONY: all clean install tags
