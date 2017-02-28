#ifndef GUARD_QUEUE_H
#define GUARD_QUEUE_H
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>

class Queue {
public:
	Node* head;
	std::size_t length;
	void queue(NodeData data);
	NodeData dequeue();
	Queue();
	~Queue();
};


Queue::Queue() {
	this->head = NULL;
	this->length = 0;
}

Queue::~Queue() {
	if (this->head) {
		Node* current = head;
		Node* next = current->getNext();
		delete current;
		while (next) {
			current = next;
			next = current->getNext();
			delete current;
		}
		head = NULL;
		this->length = 0;
	}
}

void Queue::queue(NodeData data) {
	if (!this->head) {
		this->head = new Node(data);
	}
	else {
		Node* newNode = new Node(data);
		newNode->setNext(head);
		head = newNode;
	}
	++length;
}


NodeData Queue::dequeue() {
	if (!this->head) {
		return NodeData();
	}
	else {
		Node* current = head;
		while (current->getNext()) {
			current = current->getNext();
		}
		NodeData data = current->getData();
		delete current;
		--length;
		return data;
	}
}

#endif
