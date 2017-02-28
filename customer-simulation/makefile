CC=g++
CFLAGS=-std=c++11 -g -Wall

all: main

main: NodeQueue.o Queue.o Input.o Output.o Main.o
	${CC} ${CFLAGS} -o main NodeQueue.o Queue.o Main.o Input.o Output.o

Node.o: NodeQueue.cpp NodeQueue.h
	${CC} ${CFLAGS} -c NodeQueue.cpp

Queue.o: Queue.cpp Queue.h
	${CC} ${CFLAGS} -c Queue.cpp

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
