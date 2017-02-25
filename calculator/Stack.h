#ifndef GUARD_STACK_H
#define GUARD_STACK_H
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>

class Stack {
public:
	Node* head;
	std::size_t length;
	void push(NodeData data);
	NodeData pop();
	NodeData top();
	Stack();
	~Stack();
};


Stack::Stack() {
	this->head = NULL;
	this->length = 0;
}

Stack::~Stack() {
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

void Stack::push(NodeData data) {
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

NodeData Stack::pop() {
	if (!this->head) {
		return NodeData();
	}
	else {
		NodeData data = head->getData();
		Node* current = head;
		head = head->getNext();
		delete current;
		--length;
		return data;
	}
}

NodeData Stack::top() {
	if (!this->head) {
		return NodeData();
	}
	else {
		return head->getData();
	}
}

void Stack::push(NodeData data){
  if(!this->head){
    this->head = new Node(data);
  } else {
    Node** current = &head;
    while((*current)->getNext()){
      current = &(*current)->getNext();
    }
    (*current)->setNext(new Node(data));
  }
  ++length;
}

#endif
