#!usr\bin\bash
CC = gcc
LD = gcc 
CCFLAGS = -g -Wall -pedantic -std=c99
LDFLAGS =
OBJ = menu.o list.o
.SUFFIXES: .c .o
main: $(OBJ)
	&(LD) $(LDFLAGS) -o menu $(OBJ)
main.o: menu.c list.c
.c.o:
	$(CC) $(CCFLAGS) -c $< -o $@
deque.c: list.h
clean:
	rm -f *.o prog
