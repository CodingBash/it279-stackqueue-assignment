#ifndef GUARD_NODESTACK_H
#define GUARD_NODESTACK_H

namespace StackNS {
	struct NodeStackData {
	public:
		char character;
		int integer_one;
		int integer_two;
	};

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

	Node::Node(NodeStackData data) {
		this->data = data;
	}

	NodeStackData Node::getData() {
		return this->data;
	}

	Node*& Node::getNext() {
		return this->next;
	}

	void Node::setData(NodeStackData data) {
		this->data = data;
	}

	void Node::setNext(Node* next) {
		this->next = next;
	}
}
#endif
