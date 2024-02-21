CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean

all: StrList 

StrList: StrList.o main.o 
	$(CC) $(CFLAGS) StrList.o Main.o -o StrList


Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c


clean:
	rm -f *.o *.a StrList

