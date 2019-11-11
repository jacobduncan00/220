#include "payroll_list.h"
#include "payroll.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

PayRollList::PayRollList(){ // default constructor
  head = nullptr; //initializes head to nullptr
}

PayRollList::PayRollList(PayRollList &obj){ // copy constructor
  if(obj.head == nullptr){ // if the new "copied" list is empty
    head = nullptr; // set head equal to nullptr
  }
  else {
    ListNode *curr = obj.head; // creates a pointer named curr and points to the head of the new "copied" list
    while(curr){ // while curr != NULL
      insert(curr -> p); // uses insert function to insert the contents of the original linked list into the new "copied" list
      curr = curr -> next; // moves to next node in the list
    }
  }
}

PayRollList::~PayRollList(){ // deconstructor
  ListNode *cursor = head;
  while (cursor){ //walks though the list
    cursor = cursor -> next;
    delete head; //deletes head
    head = cursor;
  }
}

int PayRollList::length(){
  int count = 0; // initilizaes a integer counter
  ListNode* curr = head; // creates a pointer named curr and points to head
  while (curr){ // while curr != NULL
    count++; // increment count
    curr = curr -> next; // moves to next node in the list
  }
  return count;
}

void PayRollList::assign(int target, PayRoll x){
  if (target > length() || target < 0){ // if target index is not in the list, print error message
    std::cout << "The node you are looking for is not in this linked list" << std::endl;
    std::cout << "Reprinting the list" << std::endl;
    std::cout << "=====================" << std::endl;
  }
  ListNode *curr = head;
  for (int i = 0; i < target; i++){ // goes through the linked list until at the target index
    curr = curr -> next; // moves to next node in the list
    if (curr -> next == NULL){ // if at the end of the list
      break; // break out of the loop
    }
  }
  curr -> p = x; // overwrite the object in the node currently with the new object being passed in
}

  void PayRollList::remove(int target){
    ListNode* previous = head; // creates a pointer named previous and points to head
    ListNode* current = head; // creates a pointer named current and points to head
    if (target > length() || target < 0){ // if target index is not in the list, print error message
      std::cout << "The node you are looking for is not in this linked list" << std::endl;
      std::cout << "Reprinting the list: " << std::endl;
      std::cout << "=====================" << std::endl;
      return;
    }
    if (target == 0){ // if the index you are trying to remove is the head of the linked list
      head = head -> next; // assign head to the next in the list
      delete current; // remove head by deleting curr which is still pointing to head
      return;
    }
    for (int i = 0; i < target; i++){ // goes through the linked list until at the target index
      previous = current; // previous is equal to the node before the current
      current = current -> next; // moves current to the next node in the list
    }
    previous -> next = current -> next; // previous node next points to the current nodes next (essentially skipping over the node that will be deleted)
    delete current; // deletes the node which current is pointing to
  }

PayRoll* PayRollList::operator[](int target){
  if (target > length() || target < 0){ // if target index is not in the list, return a null pointer
    std::cout << "The node you are trying to fetch is not in the linked list" << std::endl;
    return nullptr;
  }
  int index = 0; // initializes a integer index
  ListNode *curr = head; // creates a pointer named curr and points to head
  while(curr){ // while curr != NULL
    if (index == target){ // if the index counter is equal to the target index which the user is searching for
      PayRoll *ref = &(curr -> p); // dereference the object which curr is pointing to
      return ref; // return a reference of the object at the specified index
    }
      curr = curr -> next; // moves current to the next node in the list
      index++; // increments index
    }
  }

void PayRollList::insert(int target, PayRoll p){
  ListNode *curr = head; // creates a pointer curr and points to head
  ListNode *previous = head; // creates a pointer previous and points to head
  ListNode *newNode = new ListNode; // creates a new node that will be inserted into the linked list at a given position
  newNode -> p = p; // the data in the new Node is set to the PayRoll object passed in from main
  newNode -> next = NULL;
  if (target > length() || target < 0){ // if target index is not in the list, print an error message
    std::cout << "You are trying to insert at an invalid index" << std::endl;
  }
    for (int i = 0; i < target; i++){ // goes through the linked list until at the target index
      previous = curr; // previous is equal to the node before current
      curr = curr -> next; // moves current to the next node in the list
    }
    previous -> next = newNode; // previous' next is set to the node being inserted
    newNode -> next = curr; // the new node that is inserted has its next pointing to curr
    // this essentially pushes a new node into the linked list between previous and current
  }


void PayRollList::insert(std::string empName, double payRate, double hr){
  ListNode *newNode = new ListNode; //allocating 20 bytes, heap object and local variable
  newNode-> p = PayRoll(empName, payRate, hr); //data within a node is a payroll object
  newNode-> next = NULL;
  ListNode *curr = head; //pointer to hold current position in list
  ListNode *previous = head; //pointer to hold previous position in list

  if (head == NULL){ //edge case where list is empty
    head = newNode;
    return;
  }
  else {
    if(head -> p.getPay() > newNode -> p.getPay()){ //edge case where only a head is in the list
      newNode -> next = head;
      head = newNode;
    }
    else{
      while(curr -> next != NULL){ //while the list is not ended
        previous = curr;
        curr = curr -> next;
      }
        if (curr -> p.getPay() < newNode -> p.getPay()){ //edge case where the current is less than the new node
          curr -> next = newNode;
          return;
        }
          else{ //edge case where the current is greater than the new node
            previous -> next = newNode;
            newNode -> next = curr;
            return;
          }

    }
  }
}

void PayRollList::insert(PayRoll p){ //overloaded function that calls the first insert function
  insert(p.getName(), p.getPay(), p.getHours());
}

void PayRollList::printPayChecks(){ //function that prints employee name and total pay and shows their payrate as well
  ListNode *cursor = head;
    while (cursor){
      std::cout << cursor -> p.getName() << " (payrate: $" << cursor -> p.getPay() << "/per hour)" << ": $" << cursor -> p.calcWage();
      std::cout << std::endl;
      cursor = cursor -> next;
    }
    std::cout << "=======================================" << std::endl;
  }
