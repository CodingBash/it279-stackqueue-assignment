#ifndef GUARD_QUEUE_H
#define GUARD_QUEUE_H
#include "NodeQueue.h"
#include <cstdlib>
#include <cstddef>


class Queue {
public:
	QueueNS::Node* head;
	std::size_t length;
	void queue(QueueNS::NodeQueueData data);
	QueueNS::NodeQueueData dequeue();
	Queue();
	~Queue();
};


Queue::Queue() {
	this->head = NULL;
	this->length = 0;
}

Queue::~Queue() {
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

void Queue::queue(QueueNS::NodeQueueData data) {
	if (!this->head) {
		this->head = new QueueNS::Node(data);
	}
	else {
		QueueNS::Node* newNode = new QueueNS::Node(data);
		newNode->setNext(head);
		head = newNode;
	}
	++length;
}


QueueNS::NodeQueueData Queue::dequeue() {
	if (!this->head) {
		return QueueNS::NodeQueueData();
	}
	else {
		QueueNS::Node* current = head;
		while (current->getNext()) {
			current = current->getNext();
		}
		QueueNS::NodeQueueData data = current->getData();
		delete current;
		--length;
		return data;
	}
}

#endif
