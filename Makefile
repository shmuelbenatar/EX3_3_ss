CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs



all: StrList 

StrList: Main.o libmystring.a
	$(CC) $(CFLAGS) libmystring.a Main.o -o StrList

libmystring.a: StrList.o
	$(AR) $(AFLAGS) libmystring.a StrList.o

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c



clean:
		rm -f *.o *.a StrList

