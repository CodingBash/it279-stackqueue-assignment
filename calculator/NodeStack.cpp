#include "NodeStack.h"

/*
*	Stack Node constructor
*/
StackNS::Node::Node(StackNS::NodeStackData data) {
	this->data = data;
}

/*
*	Retrieve the node data
*/
StackNS::NodeStackData StackNS::Node::getData() {
	return this->data;
}

/*
*	Retrieve the next node
*/
StackNS::Node*& StackNS::Node::getNext() {
	return this->next;
}

/*
*	Set the node data
*/
void StackNS::Node::setData(StackNS::NodeStackData data) {
	this->data = data;
}

/*
*	Set the next node
*/
void StackNS::Node::setNext(StackNS::Node* next) {
	this->next = next;
}
