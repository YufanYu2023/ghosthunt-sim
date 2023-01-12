CFLAGS = -g -std=c99
CC = gcc

all: building.c defs.h Evidence.c ghost.c hunter.c room.c
	$(CC) -o final $(CFLAGS) defs.h room.c building.c main.c ghost.c hunter.c Evidence.c


clean:
	rm -f *.o *.d a.out all




