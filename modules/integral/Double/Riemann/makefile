main: main.o integral.o
	gcc integral.o main.o -o main -lm

integral.o: integral.c
	gcc -c integral.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o