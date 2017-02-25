#include "LinkedList.h"
#include "Input.h"
#include "Output.h"
#include <iostream>

int main() {
	/*
		Problem 1 of Homework 3
	*/
	Input input;
	std::vector<int> entryList = input.retrieveInput();
	LinkedList<int> list;
	for (int entry : entryList) {
		list.add(entry);
	}
	Output output;
	output.printVector(list.to_vec());
	std::cout << "SUM: " << list.sum() << std::endl;
	std::cout << "AVERAGE: " << list.average() << std::endl;

	/*
		Problem 2 extra credit of Homework 3
	*/
	std::cout << "\n\n\nEnter second list to concatenate" << std::endl;
	std::vector<int> entryList_2 = input.retrieveInput();
	LinkedList<int> list_2;
	for (int entry : entryList_2) {
		list_2.add(entry);
	}

	// Synonymous to #concatenate()
	LinkedList<int> list_new;
	list_new = list_new.concatenate(list, list_2);
	output.printVector(list_new.to_vec());
	std::cout << "CONCATENATE SUM: " << list_new.sum() << std::endl;
	std::cout << "CONCATENATE AVERAGE: " << list_new.average() << std::endl;
}
