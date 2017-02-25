#ifndef GUARD_NODE_H
#define GUARD_NODE_H

template <class T>
class Node{
private:
    T data;
    Node<T>* next;
public:
  T getData();
  void setData(T data);
  Node<T>*& getNext();
  void setNext(Node<T>* next);
  Node(T data);
  ~Node();
};

template <class T>
Node<T>::Node(T data){
  this->data = data;
}

template <class T>
Node<T>::~Node(){

}
template <class T>
T Node<T>::getData(){
  return this->data;
}

template <class T>
Node<T>*& Node<T>::getNext(){
  return this->next;
}

template <class T>
void Node<T>::setData(T data){
  this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next){
  this->next = next;
}

template class Node<int>;
#endif
