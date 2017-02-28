#include "NodeStack.h"

StackNS::Node::Node(StackNS::NodeStackData data) {
	this->data = data;
}

StackNS::NodeStackData StackNS::Node::getData() {
	return this->data;
}

StackNS::Node*& StackNS::Node::getNext() {
	return this->next;
}

void StackNS::Node::setData(StackNS::NodeStackData data) {
	this->data = data;
}

void StackNS::Node::setNext(StackNS::Node* next) {
	this->next = next;
}