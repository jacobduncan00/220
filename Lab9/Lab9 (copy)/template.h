#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>

template <class T>
class MyStack{
private:
  struct Node{
    T data;
    Node* next;
  };
  Node* top;
public:
  MyStack();
  ~MyStack();
  MyStack<T>(const MyStack&);
  MyStack<T>& operator=(const MyStack<T>&);
  void push(T);
  void pop(T&);
  T peek();
  void print();
};

template <class T>
MyStack<T>::MyStack(){
  top = nullptr;
}

template <class T>
MyStack<T>::~MyStack(){
  Node* cursor = top;
  while(cursor){
    Node* temp = cursor -> next;
    delete cursor;
    cursor = temp;
  }
}

template <class T>
MyStack<T>::MyStack(const MyStack& obj){
  Node* cursor = obj.top;
  int counter = 0;
  while(cursor){
    counter++;
    cursor = cursor -> next;
  }
  cursor = obj.top;
  top = nullptr;
}

template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& obj){
  Node* cursor = this -> top;
  while(cursor){
    Node* temp = cursor -> next;
    delete cursor;
    cursor = temp;
  }
  cursor = obj.top;
  while(cursor){
    push(cursor -> data);
    cursor = cursor -> next;
  }
  return *this;
}

template <class T>
void MyStack<T>::push(T obj){
  Node* newNode = new Node;
  newNode -> data = obj;
  newNode -> next = nullptr;
  if (top == nullptr){
    top = newNode;
    return;
  }
  else{
    newNode -> next = top;
    top = newNode;
  }
}

template <class T>
void MyStack<T>::pop(T& obj){
  if (top == nullptr){
    std::cout << "Stack Empty" << std::endl;
    return;
  }
  else{
    Node* temp = top;
    obj = top->data;
    top = top -> next;
    delete temp;
  }
}

template <class T>
T MyStack<T>::peek(){
  if (top){
    return top -> data;
  }
  else{
    std::cout << "Stack is Empty" << std::endl;
  }
}

template <class T>
void MyStack<T>::print(){
  std::cout << "=============" << std::endl;
  for (Node* cursor = top; cursor; cursor = cursor -> next){
    std::cout << cursor -> data;
    std::cout << std::endl;
  }
  std::cout << "=============" << std::endl;
}

#endif
