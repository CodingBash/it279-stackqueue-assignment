#ifndef GUARD_NODESTACK_H
#define GUARD_NODESTACK_H

namespace StackNS {
	/*
	*	Class for the Stack Node Data
	*/
	struct NodeStackData {
	public:
		char character;
		int integer_one;
		int integer_two;
	};

  /*
  *	Class for the Stack Node
  */
	class Node {
	private:
		NodeStackData data;
		Node* next;
	public:
		NodeStackData getData();
		void setData(NodeStackData data);
		Node*& getNext();
		void setNext(Node* next);
		Node(NodeStackData data);
	};
}
#endif
