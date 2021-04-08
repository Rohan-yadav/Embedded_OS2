CC=gcc

CFLAGS=-c -Wall

all:gol

gol:gol.o cells.o display.o
        $(CC) gol.o cells.o display.o -o gol -lncurses -lpthread

gol.o: gol.c
        $(CC) $(CFLAGS) gol.c

cells.o: cells.c
        $(CC) $(CFLAGS) cells.c

display.o: display.c
        $(CC) $(CFLAGS) display.c

clean:
        rm -rf *o gol
        

