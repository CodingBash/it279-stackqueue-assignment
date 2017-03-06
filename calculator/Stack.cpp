#include "Stack.h"

/*
*	Stack constructor
*/
StackNS::Stack::Stack() {
	this->head = NULL;
	this->length = 0;
}

/*
*	Stack destructor
*/
StackNS::Stack::~Stack() {
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

/*
*	Push data to the Stack
*/
void StackNS::Stack::push(StackNS::NodeStackData data) {
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

/*
*	Pop data from the stack
*/
StackNS::NodeStackData StackNS::Stack::pop() {
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

/*
*	Retrieve the top data from the stack
*/
StackNS::NodeStackData StackNS::Stack::top() {
	if (!this->head) {
		return StackNS::NodeStackData();
	}
	else {
		return head->getData();
	}
}
