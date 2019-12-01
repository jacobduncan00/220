#include <iostream>
#include <algorithm>
#include "sulist.h"

template <class DataType>
SUList<DataType>::SUList(){ // default constructor
  head = nullptr;
  tail = nullptr;
}

template <class DataType>
SUList<DataType>::SUList(const SUList& obj){ //Copy constructor
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
  std::cout << "Copied Successfully!" << std::endl;
}

template <class DataType>
SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType>& obj){ // overloaded assignment operator
  std::cout << "Overloaded Assignment Operator Called...";
  int track = 0;
  if (this == &obj){
    std::cout << "ERROR: Self Assignment!" << std::endl;
    ListNode* tempPtr = nullptr;
    return *this;
  }
  else{
    ListNode* cursor = this->head;
    while (cursor){
      ListNode* nextNode = cursor->next;
      delete cursor;
      cursor = nextNode;
    }
    cursor = obj.head;
    while (cursor){
      track++;
      cursor = cursor -> next;
    }
    cursor = obj.head;
    ListNode* tempPtr = obj.head;
    this->head = nullptr;
    this->tail = nullptr;
    for (cursor = obj.head; cursor; cursor = cursor->next){
      for (int i = 0; i < track - 1; i++){
        tempPtr = tempPtr->next;
      }
      putFront(tempPtr->data);
      tempPtr = obj.head;
      track--;
    } 
    std::cout << "List Successfully Overwritten..." << std::endl;
    return *this;
  }
}


template <class DataType>
SUList<DataType>::~SUList(){ // Destructor
  if (head != nullptr){
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
DataType SUList<DataType>::getFront(){ // removes front and returns it
  ListNode *tempPtr = head;
  DataType hold = head->data;
  head = head->next;
  delete tempPtr;
  return hold;
}

template <class DataType>
DataType SUList<DataType>::getBack(){ // removes back and returns it
  ListNode* tempPtr = tail;
  DataType hold = tail->data;
  if(head && tail){
    tail = tempPtr->prev;
    tail->next = nullptr;
    delete tempPtr;
    return hold;
  }if(!head->next){
    tail = tempPtr->prev;
    head = nullptr;
    delete tempPtr;
    return hold;
  }
}

template <class DataType>
void SUList<DataType>::putFront(const DataType& obj){ // Adds to front of list
 ListNode* newNode = new ListNode;
 newNode->data = obj;
 newNode->next = nullptr;
 newNode->prev = nullptr;
 if(!head && !tail){
  newNode->next = head;
  head = newNode;
  tail = newNode;
}else{
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}
ListNode* cursor = head;
while(cursor->next){
  cursor = cursor->next;
}
tail = cursor;
}

template <class DataType>
void SUList<DataType>::putBack(const DataType& obj){ // Adds to back of list
  ListNode* newNode = new ListNode;
  newNode->data = obj;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  if(!tail && !head){
    newNode->prev = tail;
    head = newNode;
    tail = newNode;
  }else{
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

template <class DataType>
int SUList<DataType>::size() const{ // returns the size of the list
  int counter = 0;
  ListNode *currentPtr = head;
  while (currentPtr){
    counter++;
    currentPtr = currentPtr -> next;
  }
  return counter;
}

template <class DataType>
bool SUList<DataType>::contains(const DataType& obj){ // Tests for membership within list
  ListNode *tempPtr = head;
  while (tempPtr){
    if(tempPtr->data == obj){
      std::cout << "Membership Confirmed!" << std::endl;
      return true;
    }
    else{
      tempPtr = tempPtr->next;
    }
  }
  std::cout << "Membership Denied!" << std::endl;
  return false;
}

template <class DataType>
void SUList<DataType>::print() const{ // prints the contents of the list
  ListNode *currentPtr = head;
  while (currentPtr){
    std::cout << currentPtr->data << " ";
    currentPtr = currentPtr->next;
  }
  std::cout << std::endl;
}
