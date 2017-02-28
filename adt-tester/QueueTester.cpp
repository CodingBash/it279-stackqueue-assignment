#include "Queue.h"
#include "Stack.h"
#include <iostream>

int main() {
	/*
	* Test Queue
	*/
	Stack stack = Stack();
	auto createData = [](int one, int two, char c) -> StackNS::NodeStackData {
		StackNS::NodeStackData data = StackNS::NodeStackData();
		data.integer_one = one;
		data.integer_two = two;
		data.character = c;
		return data;
	};
	stack.push(createData(1, 2, 'c'));
	stack.push(createData(2, 4, 'c'));
	stack.push(createData(3, 2, 'c'));
	while (stack.length != 0) {
		StackNS::NodeStackData result = stack.pop();
		std::cout << result.integer_one << std::endl;
	}
	system("PAUSE");
}
