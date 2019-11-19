#include <iostream>
#include <algorithm>
#include "sulist.h"

template <class DataType>
SUList<DataType>::SUList(){
  head = nullptr;
  tail = nullptr;
}

template <class DataType>
SUList<DataType>::SUList(const SUList& obj){
  std::cout << " Copy Constructor Called...";
  if (obj.head == nullptr){
    head = nullptr;
  }
  ListNode *headhold = new ListNode;
  ListNode *curr = headhold;
  ListNode *curr2 = obj.head;
  for (; curr2 != nullptr; curr2 = curr2 -> next){
    curr -> next = new ListNode;
    curr = curr -> next;
    curr -> data = curr2 -> data;
    curr -> next = nullptr;
  }
  head = headhold -> next;
  delete headhold;
  std::cout << "Copied Successfully..." << std::endl;
}

template <class DataType>
SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType>& obj){
  SUList<DataType>temp(obj);
  std::swap(temp.head, head);
  return *this;
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
  ListNode *tempPtr = new ListNode;
  tempPtr->data = head->data;
  delete head;
  head = tempPtr->next;
  return tempPtr->data;
}

template <class DataType>
DataType SUList<DataType>::getBack(){
  ListNode *tempPtr = new ListNode;
  ListNode *traverse = head;
  while (traverse -> next != nullptr){
    traverse = traverse -> next;
  }
  tempPtr->data = tail->data;
  delete tail;
  tail = traverse;
  return tempPtr->data;
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
  traverse -> next = tempPtr; // problem
  tail = tempPtr;
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
bool SUList<DataType>::contains(const DataType& obj){
  ListNode *tempPtr = head;
  while (tempPtr){
    if(tempPtr->data == obj){
      std::cout << "Membership Confirmed!" << std::endl;
      return true;
    }
    tempPtr = tempPtr->next;
  }
  std::cout << "Membership Denied!" << std::endl;
  return false;
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
