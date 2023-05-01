CC=g++
CFLAGS=-g3
LDLIBS=-lm -Wall -O3 -fPIC

INCLUDES=-Imodules/linear -Imodules/root -Imodules/integral -Imodules/shared

debug_tests: CFLAGS += -DDEBUG -g
debug_tests: test


#############################################################################
#						BUILDING SHARED LIBRARIES							#
#############################################################################

shared: modules/root/root.so modules/linear/linear.so modules/integral/integral.so
	mkdir -p seals/templates
	cp modules/shared/*.tpp seals/templates

	mkdir -p seals/lib
	mv modules/**/*.so seals/lib

	mkdir -p seals/include
	cp modules/**/*.h seals/include

#############################################################################
#							BUILDING TESTS									#
#############################################################################

run_tests: tests
	./tests/test_linear
	./tests/test_root
	./tests/test_integral
	./tests/test_array

tests: tests/test_linear tests/test_array tests/test_root tests/test_integral

tests/test_linear: tests/linear/test_linear.o modules/linear/linear.o
	$(CC) $(CFLAGS) $(INCLUDES) modules/linear/linear.o  $(LDLIBS) -o tests/test_linear tests/linear/test_linear.o

tests/test_root: tests/root/test_root.o modules/root/root.o
	$(CC) $(CFLAGS) $(INCLUDES) modules/root/root.o $(LDLIBS) -o tests/test_root tests/root/test_root.o

tests/test_integral: tests/integral/test_integral.o modules/integral/integral.o
	$(CC) $(CFLAGS) $(INCLUDES) modules/integral/integral.o $(LDLIBS) -o tests/test_integral tests/integral/test_integral.o

tests/test_array: tests/shared/test_array.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LDLIBS) -o tests/test_array tests/shared/test_array.o



#############################################################################
#							GENERIC BUILDS									#
#############################################################################

%.so: %.o
	$(CC) $(CFLAGS) $(INCLUDES) -shared $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ $(LDLIBS) -o $@

clean:
	rm -f modules/**/*.o
	rm -f tests/test_*
	rm -f seals