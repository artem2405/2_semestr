#!usr\bin\bash
CC = gcc
LD = gcc 
CCFLAGS = -g -Wall -pedantic -std=c99
LDFLAGS =
OBJ = main.o deque.o
.SUFFIXES: .c .o
main: $(OBJ)
	&(LD) $(LDFLAGS) -o main $(OBJ)
main.o: main.c deque.c
.c.o:
	$(CC) $(CCFLAGS) -c $< -o $@
deque.c: deque.h
clean:
	rm -f *.o prog
