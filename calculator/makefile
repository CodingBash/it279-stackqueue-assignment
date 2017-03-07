CC=g++
CFLAGS=-std=c++11 -g -Wall

all: calc

calc: NodeStack.o Stack.o Input.o Output.o Calculator.o
	${CC} ${CFLAGS} -o calc NodeStack.o Stack.o Calculator.o Input.o Output.o

Node.o: NodeStack.cpp NodeStack.h
	${CC} ${CFLAGS} -c NodeStack.cpp

LinkedList.o: Stack.cpp Stack.h
	${CC} ${CFLAGS} -c LinkedList.cpp

Calculator.o: Calculator.cpp
	${CC} ${CFLAGS} -c Calculator.cpp

Input.o: Input.cpp Input.h
	${CC} ${CFLAGS} -c Input.cpp

Output.o: Output.cpp Output.h
	${CC} ${CFLAGS} -c Output.cpp

clean:
	rm -f *.o *.out calc

run: clean calc
	./calc
