#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <iostream>

int main() {
	/*
	* Test Stack
	*/
	StackNS::Stack stack = StackNS::Stack();
	auto createStackData = [](int one, int two, char c) -> StackNS::NodeStackData {
		StackNS::NodeStackData data = StackNS::NodeStackData();
		data.integer_one = one;
		data.integer_two = two;
		data.character = c;
		return data;
	};
	stack.push(createStackData(1, 2, 'c'));
	stack.push(createStackData(2, 4, 'c'));
	stack.push(createStackData(3, 2, 'c'));
	/*
	while (stack.length != 0) {
		StackNS::NodeStackData result = stack.pop();
		std::cout << result.integer_one << std::endl;
	}
	*/

	/*
	* Test Queue
	*/
	QueueNS::Queue queue = QueueNS::Queue();
	auto createQueueData = [](std::string name) -> QueueNS::NodeQueueData {
		QueueNS::NodeQueueData data = QueueNS::NodeQueueData();
		data.name = name;
		return data;
	};
	queue.queue(createQueueData("customer 1"));
	queue.queue(createQueueData("customer 2"));
	queue.queue(createQueueData("customer 3"));
	/*
	while (queue.length != 0) {
		QueueNS::NodeQueueData result = queue.dequeue();
		std::cout << result.name << std::endl;
	}
	*/
	system("PAUSE");
}
