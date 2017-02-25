#ifndef GUARD_NODE_H
#define GUARD_NODE_H

struct NodeData {
public:
	char character;
	int integer_one;
	int integer_two;
};

class Node{
private:
	NodeData data;
    Node* next;
public:
  NodeData getData();
  void setData(NodeData data);
  Node*& getNext();
  void setNext(Node* next);
  Node(NodeData data);
};

Node::Node(NodeData data){
  this->data = data;
}

template <class T>
T Node<T>::getData(){
  return this->data;
}

Node*& Node::getNext(){
  return this->next;
}

void Node::setData(NodeData data){
  this->data = data;
}

void Node::setNext(Node* next){
  this->next = next;
}

#endif
