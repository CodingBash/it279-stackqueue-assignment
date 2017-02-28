CC=g++
CFLAGS=-std=c++11 -g -Wall

all: main

main: NodeQueue.o NodeStack.o AdtTester.o Queue.o Stack.o
	${CC} ${CFLAGS} -o main NodeQueue.o NodeStack.o AdtTester.o Queue.o Stack.o

NodeQueue.o: NodeQueue.cpp NodeQueue.h
	${CC} ${CFLAGS} -c NodeQueue.cpp

NodeStack.o: NodeStack.cpp NodeStack.h
	${CC} ${CFLAGS} -c NodeStack.cpp

AdtTester.o: AdtTester.cpp
	${CC} ${CFLAGS} -c AdtTester.cpp

Queue.o: Queue.cpp Queue.h
	${CC} ${CFLAGS} -c Queue.cpp

Stack.o: Stack.cpp Stack.h
	${CC} ${CFLAGS} -c Stack.cpp

clean:
	rm -f *.o *.out main

run: clean main
	./main
