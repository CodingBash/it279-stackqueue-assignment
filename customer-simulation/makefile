CC=g++
CFLAGS=-std=c++11 -g -Wall

all: main

main: NodeQueue.o SuperMarketLine.o Queue.o
	${CC} ${CFLAGS} -o main NodeQueue.o SuperMarketLine.o Queue.o

NodeQueue.o: NodeQueue.cpp NodeQueue.h
	${CC} ${CFLAGS} -c NodeQueue.cpp

Queue.o: Queue.cpp Queue.h
	${CC} ${CFLAGS} -c Queue.cpp

SuperMarketLine.o: SuperMarketLine.cpp
	${CC} ${CFLAGS} -c SuperMarketLine.cpp

clean:
	rm -f *.o *.out main

run: clean main
	./main
