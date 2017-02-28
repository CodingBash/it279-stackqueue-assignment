CC=g++
CFLAGS=-std=c++11 -g -Wall

all: main

main: NodeStack.o Stack.o Input.o Output.o Main.o
	${CC} ${CFLAGS} -o main NodeStack.o Stack.o Main.o Input.o Output.o

Node.o: NodeStack.cpp NodeStack.h
	${CC} ${CFLAGS} -c NodeStack.cpp

LinkedList.o: Stack.cpp Stack.h
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
