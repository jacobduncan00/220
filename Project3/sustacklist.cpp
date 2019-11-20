#include "sustacklist.h"

template <class DataType>
SUStackList<DataType>::SUStackList(){
  list.head = nullptr;
  list.tail = nullptr;
}

template <class DataType>
SUStackList<DataType>::SUStackList(const SUStackList& obj){
  auto* cursor = obj.head;
  int counter = 0;
  while (cursor){
    counter++;
    cursor = cursor -> next;
  }
  cursor = obj.head;
  auto* temp = obj.head;
  list.head = nullptr;
  for (cursor = obj.head; cursor; cursor = cursor -> next){
    for (int i = 0; i < counter -1; i++){
      temp = temp -> next;
    }
    push(&temp);
    temp = obj.head;
    counter--;
  }
}

template <class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType>& obj){
  int counter = 0;
  auto* cursor = obj.head;
  if (this == &obj){
    std::cout << "The Same Stack!" << std::endl;
  }
  else{
    auto* cursor = this->head;
    while (cursor){
      auto* nextNode = cursor->next;
      delete cursor;
      cursor = nextNode;
    }
    cursor = obj.head;
    while (cursor){
      counter++;
      cursor = cursor->next;
    }
    cursor = obj.head;
    auto* temp = obj.head;
    this->top = nullptr;
    for (cursor = obj.head; cursor; cursor = cursor->next){
      for (int i = 0; i < counter -1; i++){
        temp = temp->next;
      }
      this->push(&temp);
      temp = obj.head;
      counter--;
    }
    return *this;
  }
}

template <class DataType>
SUStackList<DataType>::~SUStackList(){
  auto* cursor = list.head;
  while (cursor){
    auto* temp = cursor->next;
    delete cursor;
    cursor = temp;
  }
}

template <class DataType>
int SUStackList<DataType>::size() const{
  int counter = 0;
  auto* cursor = list.head;
  while (cursor){
    counter++;
    cursor = cursor->next;
  }
  return counter;
}

template <class DataType>
bool SUStackList<DataType>::isEmpty() const{
  if (list.head != nullptr){
    return false;
  }
  else{
    return true;
  }
}

template <class DataType>
void SUStackList<DataType>::push(const DataType& obj){
  auto* newNode = new auto;
  newNode -> data = obj;
  newNode -> next = nullptr;
  if (list.head == nullptr){
    list.head = newNode;
    return;
  }
  else{
    newNode->next = list.head;
    list.head = newNode;
  }
}

template <class DataType>
void SUStackList<DataType>::pop(DataType& obj){
  if (!list.head){
    std::cout << "Stack Empty" << std::endl;
    return;
  }
  else{
    auto* temp = list.head;
    obj = list.head->data;
    list.head = list.head->next;
    delete temp;
  }
}

template <class DataType>
void SUStackList<DataType>::printStack() const{
  std::cout << "==============" << std::endl;
  if (!list.head){
    std::cout << "Stack Empty" << std::endl;
    std::cout << "==============" << std::endl;
    return;
  }
  for (auto* cursor = list.head; cursor; cursor = cursor->next){
    std::cout << cursor -> data;
    std::cout << std::endl;
  }
  std::cout << "==============" << std::endl;
}
