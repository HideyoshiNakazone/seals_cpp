CC=g++
CFLAGS=-g3
LDLIBS=-lm

INCLUDES=-I../modules/linear -I../modules/root -I../modules/integral -I../modules/shared

debug_tests: CFLAGS += -DDEBUG -g
debug_tests: test

run_tests: test
	./test_linear
	./test_root
	./test_integral
	./test_array

test: test_linear test_array test_root test_integral

test_linear: linear/test_linear.o ../modules/linear/linear.o
	$(CC) $(CFLAGS) $(INCLUDES) ../modules/linear/linear.o  $(LDLIBS) -o test_linear linear/test_linear.o

test_root: root/test_root.o ../modules/root/root.o
	$(CC) $(CFLAGS) $(INCLUDES) ../modules/root/root.o $(LDLIBS) -o test_root root/test_root.o

test_integral: integral/test_integral.o ../modules/integral/integral.o
	$(CC) $(CFLAGS) $(INCLUDES) ../modules/integral/integral.o $(LDLIBS) -o test_integral integral/test_integral.o

test_array: shared/test_array.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LDLIBS) -o test_array shared/test_array.o

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ $(LDLIBS) -o $@

clean:
	rm -f **/*.o

	rm -f ../modules/linear/*.o
	rm -f ../modules/integral/*.o
	rm -f ../modules/root/*.o
	rm -f ../modules/shared/*.o

	rm -f test_linear
	rm -f test_root
	rm -f test_integral
	rm -f test_array