#include "payroll_list.h"
#include "payroll.h"
#include "payrollstack.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

PayRollStack::PayRollStack(){ // default constructor
  head = nullptr;
}

PayRollStack::~PayRollStack(){ // destructor
  for(StackNode* cursor = head; cursor; head = cursor){
    cursor = cursor -> next; // walks through list and deletes
    delete head;
  }
}

PayRollStack::PayRollStack(const PayRollStack& obj){ //copy constructor
  head = nullptr; // base case
  StackNode* objCurr = obj.head; //
  while(objCurr){
    push(objCurr -> p); // pushes payroll objects into new PayRoll List Stack
    objCurr = objCurr -> next; // moves along the new list stack
  }
}

PayRollStack PayRollStack::operator=(const PayRollStack& obj){ // assignment operator overload
  for(StackNode* cursor = head; cursor; head = cursor){
    StackNode* temp = cursor;
    cursor = cursor -> next;
    delete temp; // deallocates memory from the original linked list stack
  }
    if(this == &obj){ // edge case to make sure you are not self assigning
      std::cout << "Cannot be assigned, object is identical" << std::endl;
      return obj; // returns object if self assigned
    }
    StackNode* objCurr = obj.head;
    while(objCurr){
      push(objCurr -> p); // pushes payroll objects into new PayRoll List Stack
      objCurr = objCurr -> next; // moves along the new list stack
    }
    return *this;
}

void PayRollStack::push(PayRoll p){ // pushes new node onto stack
  StackNode* newNode = new StackNode;
  newNode -> p = p;
  newNode -> next = nullptr;

  if (head == nullptr){
    head = newNode;
    return;
  }

  StackNode* curr = head;
  while (curr -> next){ // walks along list and inserts newNodes as you traverse
    curr = curr -> next;
  }
  curr -> next = newNode;
}

PayRoll PayRollStack::pop(){ // pops the top of the stack
  PayRoll temp;
  if (head == nullptr){ // base case if list is empty, cannot be popped
    printf("Stack is empty, cannot Pop!\n");
    return temp;
  }
  StackNode* curr = head;
  StackNode* prev = head;
  while (curr -> next){ // progresses the prev and curr through the linked list
    prev = curr;
    curr = curr -> next;
  }
  prev -> next = nullptr;
  PayRoll returnObj = curr -> p; // sets the node to a payroll object that can be returned
  delete curr;
  return returnObj;
}

void PayRollStack::pop(PayRoll& obj){ // second pop function that calls the first
  obj = pop();
}

int PayRollStack::size(){ // function that determines the size of the linked list
  if(head == nullptr){ // base case if list is empty
    printf("Cannot get size of an empty Stack!\n");
    return 0;
  }
  StackNode* cursor = head;
  int counter = 0; // counter for how many nodes in list
  while (cursor){
    counter++; // increments as list progresses
    cursor = cursor -> next; // walks through list
  }
  return counter;
}

void PayRollStack::print(){ // prints information of each employee in the linked list
  std::cout << "==========================================\n";
  StackNode* curr = head;
  while(curr){
    std::cout << curr -> p.getName() << " $" << curr -> p.calcWage();
    if (curr == head){
      std::cout << " <--- First In";
    }
    else if(curr -> next == nullptr){
      std::cout << " <--- Top";
    }
    std::cout << std::endl;
    curr = curr -> next;
  }
  std::cout << "==========================================\n";
}
