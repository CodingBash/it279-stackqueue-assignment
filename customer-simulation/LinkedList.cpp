#include "LinkedList.h"

/*
* Specialized template functions
*/
template <>
int LinkedList<int>::sum() {
	int sum = 0;
	if (this->head) {
		Node<int>** current = &head;
		sum += (*current)->getData();
		while ((*current)->getNext()) {
			current = &(*current)->getNext();
			sum += (*current)->getData();
		}
	}
	return sum;
}

template <>
float LinkedList<int>::average() {
	return (float) this->sum() / (float) this->length;
}