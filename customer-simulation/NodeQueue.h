#ifndef GUARD_NODEQUEUE_H
#define GUARD_NODEQUEUE_H
#include <string>

namespace QueueNS {
  /*
  *	Class for the Queue Node Data
  */
	struct NodeQueueData {
	public:
		int customerNumber;
		int arrivalTime;
	};

  /*
  *	Class for the Queue Node
  */
	class Node {
	private:
		NodeQueueData data;
		Node* next;
	public:
		NodeQueueData getData();
		void setData(NodeQueueData data);
		Node*& getNext();
		void setNext(Node* next);
		Node(NodeQueueData data);
	};
}
#endif
