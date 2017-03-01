#include "Queue.h"

QueueNS::Queue::Queue() {
	this->head = NULL;
	this->length = 0;
}

QueueNS::Queue::~Queue() {
	if (this->head) {
		QueueNS::Node* current = head;
		QueueNS::Node* next = current->getNext();
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

void QueueNS::Queue::queue(QueueNS::NodeQueueData data) {
	if (!this->head) {
		this->head = new QueueNS::Node(data);
		head->setNext(NULL);
	}
	else {
		QueueNS::Node* newNode = new QueueNS::Node(data);
		newNode->setNext(head);
		head = newNode;
	}
	++length;
}

QueueNS::NodeQueueData QueueNS::Queue::dequeue() {
	if (!this->head) {
		return QueueNS::NodeQueueData();
	}
	else {
		QueueNS::Node* current = head;
		QueueNS::Node* previous = NULL;
		while (current->getNext()) {
			previous = current;
			current = current->getNext();
		}
		QueueNS::NodeQueueData data = current->getData();
		if (previous) {
			previous->setNext(0);
		}
		delete current;
		if (current == head) {
			head = NULL;
		}
		current = NULL;
		--length;
		return data;
	}
}

int QueueNS::Queue size()
{
	return length;
}
