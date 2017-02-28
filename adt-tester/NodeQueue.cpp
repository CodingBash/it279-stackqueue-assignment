#include "NodeQueue.h"

QueueNS::Node::Node(QueueNS::NodeQueueData data) {
	this->data = data;
}

QueueNS::NodeQueueData QueueNS::Node::getData() {
	return this->data;
}

QueueNS::Node*& QueueNS::Node::getNext() {
	return this->next;
}

void QueueNS::Node::setData(QueueNS::NodeQueueData data) {
	this->data = data;
}

void QueueNS::Node::setNext(QueueNS::Node* next) {
	this->next = next;
}