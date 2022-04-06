CC=gcc
CFLAGS=-Wall -ansi

Prog: mybmp.o test.o
	$(CC) $(CFLAGS) -o prog mybmp.o test.o

mybmp.o: mybmp.c
	$(CC) $(CFLAGS) -c mybmp.c

test.o: test.c mybmp.h
	$(CC) $(CFLAGS) -c test.c

CLEAN: 
	rm *.o *.*~ prog