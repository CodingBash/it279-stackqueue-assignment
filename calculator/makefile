CC=g++
CFLAGS=-std=c++11 -g -Wall

all: main

main: Node.o LinkedList.o Main.o Input.o Output.o
	${CC} ${CFLAGS} -o main Node.o LinkedList.o Main.o Input.o Output.o

Node.o: Node.cpp Node.h
	${CC} ${CFLAGS} -c Node.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	${CC} ${CFLAGS} -c LinkedList.cpp

Main.o: Main.cpp
	${CC} ${CFLAGS} -c Main.cpp

Input.o: Input.cpp Input.h
	${CC} ${CFLAGS} -c Input.cpp

Output.o: Output.cpp Output.h
	${CC} ${CFLAGS} -c Output.cpp

clean:
	rm -f *.o *.out main

run: clean main
	./main
