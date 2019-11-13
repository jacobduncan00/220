#include <iostream>
#include "sulist.h"

template <class DataType>
SUList<DataType>::SUList(){
  head = nullptr;
  tail = nullptr;
}

template <class DataType>
SUList<DataType>::SUList(const SUList& obj){
  if (obj.head == nullptr){
    head = nullptr;
  }
  else {
    ListNode *currentPtr = obj.head;
    while (currentPtr){
      putBack(currentPtr -> data);
      currentPtr = currentPtr -> next;
    }
  }
}

template <class DataType>
SUList<DataType>::~SUList(){
  if (head == nullptr){
    ListNode *currentPtr = head;
    ListNode *tempPtr;

    while (currentPtr){
      tempPtr = currentPtr;
      currentPtr = currentPtr -> next;
      delete tempPtr;
    }
  }
}

template <class DataType>
DataType SUList<DataType>::getFront(){
  ListNode *tempPtr = head;
  delete head;
  head = tempPtr -> next;
  return tempPtr -> data;
}

template <class DataType>
DataType SUList<DataType>::getBack(){
  ListNode *currentPtr = head;
  ListNode *tempPtr = tail;
  delete tail;
  tail = nullptr;
  return tempPtr -> data;
  while (currentPtr){ // TESTS TRAVERSAL AFTER DELETION
    currentPtr = currentPtr -> next;
  }
}

template <class DataType>
void SUList<DataType>::putFront(const DataType& obj){
  ListNode *tempPtr = new ListNode;
  tempPtr -> data = obj;
  tempPtr -> next = head;
  head = tempPtr;
}

template <class DataType>
void SUList<DataType>::putBack(const DataType& obj){
  ListNode *tempPtr = new ListNode;
  ListNode *traverse = head;
  tempPtr -> data = obj;
  while (traverse -> next){
    traverse = traverse -> next;
  }
  tail = traverse;
  tail -> next = tempPtr; // problem
  tempPtr = tail;
}

template <class DataType>
int SUList<DataType>::size() const{
  int counter = 0;
  ListNode *currentPtr = head;
  while (currentPtr){
    counter++;
    currentPtr = currentPtr -> next;
  }
  return counter;
}

template <class DataType>
void SUList<DataType>::print(){
  ListNode *currentPtr = head;
  while (currentPtr){
    std::cout << currentPtr->data << " ";
    currentPtr = currentPtr -> next;
  }
  std::cout << std::endl;
}
