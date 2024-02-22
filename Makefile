CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = -rcs



all: StrList 

StrList: Main.o StrList.a
	$(CC) $(CFLAGS) -o StrList Main.o StrList.a

StrList.a: StrList.o
	$(AR) $(AFLAGS) StrList.a StrList.o

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c



.PHONY: clean all


clean:
		rm -f *.o *.a StrList

