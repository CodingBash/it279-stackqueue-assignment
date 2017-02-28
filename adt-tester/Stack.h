#ifndef GUARD_STACK_H
#define GUARD_STACK_H
#include "NodeStack.h"
#include <cstdlib>
#include <cstddef>

class Stack {
public:
	StackNS::Node* head;
	std::size_t length;
	void push(StackNS::NodeStackData data);
	StackNS::NodeStackData pop();
	StackNS::NodeStackData top();
	Stack();
	~Stack();
};


Stack::Stack() {
	this->head = NULL;
	this->length = 0;
}

Stack::~Stack() {
	if (this->head) {
		StackNS::Node* current = head;
		StackNS::Node* next = current->getNext();
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

void Stack::push(StackNS::NodeStackData data) {
	if (!this->head) {
		this->head = new StackNS::Node(data);
	}
	else {
		StackNS::Node* newNode = new StackNS::Node(data);
		newNode->setNext(head);
		head = newNode;
	}
	++length;
}

StackNS::NodeStackData Stack::pop() {
	if (!this->head) {
		return StackNS::NodeStackData();
	}
	else {
		StackNS::NodeStackData data = head->getData();
		StackNS::Node* current = head;
		head = head->getNext();
		delete current;
		--length;
		return data;
	}
}

StackNS::NodeStackData Stack::top() {
	if (!this->head) {
		return StackNS::NodeStackData();
	}
	else {
		return head->getData();
	}
}

#endif
