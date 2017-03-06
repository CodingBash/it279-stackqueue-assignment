#ifndef GUARD_STACK_H
#define GUARD_STACK_H
#include "NodeStack.h"
#include <cstdlib>
#include <cstddef>

namespace StackNS {
	/*
	*	Class for the Stack ADT
	*/
	class Stack {
	public:
		StackNS::Node* head;
		std::size_t length;
		void push(StackNS::NodeStackData data);
		StackNS::NodeStackData pop();
		StackNS::NodeStackData top();
		Stack();
		~Stack();
	};
}
#endif
