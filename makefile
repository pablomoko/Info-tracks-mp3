CFLAGS=-pedantic -Wall -std=c89 
CC=gcc

all: mp3explorer clear

mp3explorer: main.o ADT_Track.o ADT_Vector.o process.o common.o status.o
	$(CC) $(CFLAGS) -o mp3explorer main.o ADT_Track.o ADT_Vector.o process.o common.o status.o

main.o: main.c ADT_Vector.h ADT_Track.h status.h consts.h
	$(CC) $(CFLAGS) -o main.o -c main.c

ADT_Vector.o: ADT_Vector.c  ADT_Vector.h
	$(CC) $(CFLAGS) -o ADT_Vector.o -c ADT_Vector.c

ADT_Track.o: ADT_Track.c  ADT_Track.h
	$(CC) $(CFLAGS) -o ADT_Track.o -c ADT_Track.c

process.o: process.c  process.h
	$(CC) $(CFLAGS) -o process.o -c process.c

common.o: common.c  common.h
	$(CC) $(CFLAGS) -o common.o -c common.c

status.o: status.c  status.h
	$(CC) $(CFLAGS) -o status.o -c status.c


clear:
	rm *.o

install:
	cp mp3explorer ../mp3explorer
