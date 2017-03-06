#include "NodeQueue.h"

/*
*	Queue Node constructor
*/
QueueNS::Node::Node(QueueNS::NodeQueueData data) {
	this->data = data;
}

/*
*	Retrieve data from Node
*/
QueueNS::NodeQueueData QueueNS::Node::getData() {
	return this->data;
}

/*
*	Retrieve the next Node
*/
QueueNS::Node*& QueueNS::Node::getNext() {
	return this->next;
}

/*
*	Set the node's data
*/
void QueueNS::Node::setData(QueueNS::NodeQueueData data) {
	this->data = data;
}

/*
*	Set the next node
*/
void QueueNS::Node::setNext(QueueNS::Node* next) {
	this->next = next;
}
