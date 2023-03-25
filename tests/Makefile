CC=gcc
CFLAGS=-g3


debug_tests: CFLAGS += -DDEBUG -g
debug_tests: test

run_tests: test
	./test_linear
	./test_array

test: test_linear test_array

test_linear: test_linear.o ../modules/linear/linear.o  ../modules/shared/array.o
	$(CC) $(CFLAGS) ../modules/linear/linear.o  ../modules/shared/array.o -o test_linear test_linear.o

test_array: shared/test_array.o ../modules/shared/array.o
	$(CC) $(CFLAGS) ../modules/shared/array.o -o test_array shared/test_array.o

test_linear.o: test_linear.c
	$(CC) $(CFLAGS) -c test_linear.c -o test_linear.o

shared/test_array.o: shared/test_array.c
	$(CC) $(CFLAGS)  -c shared/test_array.c -o shared/test_array.o

../modules/linear/linear.o: ../modules/linear/linear.c
	$(CC) $(CFLAGS) -c ../modules/linear/linear.c -o ../modules/linear/linear.o

../modules/shared/array.o: ../modules/shared/array.c
	$(CC) $(CFLAGS) -c ../modules/shared/array.c -o ../modules/shared/array.o

clean:
	rm -f tests/*.o
	rm -f ../modules/linear/*.o
	rm -f ../modules/shared/*.o
	rm -f test_linear
	rm -f test_array