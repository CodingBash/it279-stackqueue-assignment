#ifndef GUARD_QUEUE_H
#define GUARD_QUEUE_H
#include "NodeQueue.h"
#include <cstdlib>
#include <cstddef>

namespace QueueNS {
	class Queue {
	public:
		QueueNS::Node* head;
		std::size_t length;
		void queue(QueueNS::NodeQueueData data);
		QueueNS::NodeQueueData dequeue();
		Queue();
		~Queue();
		int size();
	};
}

#endif
