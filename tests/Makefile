CC=gcc
CFLAGS=-g3 -lm


debug_tests: CFLAGS += -DDEBUG -g
debug_tests: test

run_tests: test
	./test_linear
	./test_root
	./test_array

test: test_linear test_array test_root

test_linear: linear/test_linear.o ../modules/linear/linear.o  ../modules/shared/array.o
	$(CC) $(CFLAGS) ../modules/linear/linear.o  ../modules/shared/array.o -o test_linear test_linear.o

test_root: root/test_root.o ../modules/root/root.o
	$(CC) $(CFLAGS) ../modules/root/root.o -o test_root root/test_root.o

test_array: shared/test_array.o ../modules/shared/array.o
	$(CC) $(CFLAGS) ../modules/shared/array.o -o test_array shared/test_array.o

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f tests/*.o
	rm -f ../modules/linear/*.o
	rm -f ../modules/root/*.o
	rm -f ../modules/shared/*.o
	rm -f test_linear
	rm -f test_array