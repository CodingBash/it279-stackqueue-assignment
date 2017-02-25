#ifndef GUARD_LINKEDLIST_H
#define GUARD_LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>

template <class T>
class LinkedList {
public:
	Node<T>* head;
	std::size_t length;
	void add(T data);
	void add(LinkedList<T> &target);
	LinkedList<T>& concatenate(LinkedList<T> &list_1, LinkedList<T> &list_2);
	std::vector<T> to_vec();
	int sum();
	float average();
	LinkedList();
	~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList() {
	this->head = NULL;
	this->length = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	if (this->head) {
		Node<T>* current = head;
		Node<T>* next = current->getNext();
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

template <class T>
void LinkedList<T>::add(T data){
  if(!this->head){
    this->head = new Node<T>(data);
  } else {
    Node<T>** current = &head;
    while((*current)->getNext()){
      current = &(*current)->getNext();
    }
    (*current)->setNext(new Node<T>(data));
  }
  ++length;
}

template <class T>
void LinkedList<T>::add(LinkedList<T> &target) {
	if (!this->head) {
		// Nothing to base, steal target
		this->head = target.head;
		this->length += target.length;
	}
	else if (!target.head) {
		// Nothing to add
	} else {
		/*
		*Get this tail
		*/
		Node<T>* tail = NULL;
		Node<T>** current = &head;
		while ((*current)->getNext()) {
			current = &(*current)->getNext();
		}
		tail = (*current);

		/*
		* Add target head to this tail
		*/
		tail->setNext(target.head);
		tail = NULL;
		this->length += target.length;
	}
}

template <class T>
std::vector<T> LinkedList<T>::to_vec(){
	std::vector<T> vec;
	if(this->head){
		Node<T>** current = &head;
		vec.push_back((*current)->getData());
		while((*current)->getNext()){
			current = &(*current)->getNext();
			vec.push_back((*current)->getData());
		}
	}
	return vec;
}

template <class T>
LinkedList<T>& LinkedList<T>::concatenate(LinkedList<T> &list_1, LinkedList<T> &list_2) {
	list_1.add(list_2);
	return list_1;
}

template class LinkedList<int>;
#endif
