#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

template <class T>
class MyStack{ // my stack class that is templated for the data
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
  MyStack<T>& operator=(const MyStack<T>&);            // prototypes
  void push(T);
  void pop(T&);
  T peek();
  void print();
};

template <class T>
MyStack<T>::MyStack(){  // templated constructor
  top = nullptr;
}

template <class T> 
MyStack<T>::~MyStack(){ // templated deconstructor
  Node* cursor = top;
  while(cursor){
    Node* temp = cursor -> next;
    delete cursor;
    cursor = temp;
  }
}

template <class T>
MyStack<T>::MyStack(const MyStack& obj){ // templated copy constructor
  Node* cursor = obj.top;
  int counter = 0;
  while(cursor){
    counter++;
    cursor = cursor -> next;
  }
  cursor = obj.top;
  Node* temp = obj.top;
  top = nullptr;
  for (cursor = obj.top; cursor; cursor = cursor -> next){
    for (int h = 0; h < counter - 1; h++){
      temp = temp -> next;
    }
    push(temp -> data);
    temp = obj.top;
    counter--;
  }
}

template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& obj){ // templated assignment operator
  int counter = 0;
  Node* cursor = obj.top;
  if (this == &obj){
    std::cout << "The Same Stack!" << std::endl;
  }
  else{
    Node* cursor = this->top; 
    while(cursor){
      Node* nextNode = cursor-> next;
      delete cursor;
      cursor = nextNode;
    }
    cursor = obj.top;
    while (cursor){
      counter++;
      cursor = cursor -> next;
    }
    cursor = obj.top;
    Node* temp = obj.top;
    this->top = nullptr;
    for (cursor = obj.top; cursor; cursor = cursor->next){
      for (int h = 0; h < counter - 1; h++){
        temp = temp->next;
      }
      this->push(temp->data);
      temp = obj.top;
      counter--;
    }
    return *this;
  }
}

template <class T>
void MyStack<T>::push(T obj){ // templated push function for stack
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
void MyStack<T>::pop(T& obj){ // templated pop function for stack
  if (!top){
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
T MyStack<T>::peek(){ // templated peek function for stack
  if (top){
    return top -> data;
  }
  else{
    std::cout << "Stack is Empty" << std::endl;
  }
}

template <class T>
void MyStack<T>::print(){ // templated print function for stack
  std::cout << "=============" << std::endl;
   if (!top){
    std::cout << "Stack Empty" << std::endl;
    std::cout << "=============" << std::endl;
    return;
  }
  for (Node* cursor = top; cursor; cursor = cursor -> next){
    std::cout << cursor -> data;
    std::cout << std::endl;
  }
  std::cout << "=============" << std::endl;
}

#endif
