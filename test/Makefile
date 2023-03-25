CC=gcc
CFLAGS=-g3

all: test

test: test_seals test_array

test_seals: test_seals.o ../modules/seals.o  ../modules/shared/array.o
	$(CC) $(CFLAGS) ../modules/seals.o  ../modules/shared/array.o -o test_seals test_seals.o

test_array: shared/test_array.o ../modules/shared/array.o
	$(CC) $(CFLAGS) ../modules/shared/array.o -o test_array shared/test_array.o

test_seals.o: test_seals.c
	$(CC) $(CFLAGS) -c test_seals.c -o test_seals.o

shared/test_array.o: shared/test_array.c
	$(CC) $(CFLAGS)  -c shared/test_array.c -o shared/test_array.o

../modules/seals.o: ../modules/seals.c
	$(CC) $(CFLAGS) -c ../modules/seals.c -o ../modules/seals.o

../modules/shared/array.o: ../modules/shared/array.c
	$(CC) $(CFLAGS) -c ../modules/shared/array.c -o ../modules/shared/array.o