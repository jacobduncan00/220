#include "payroll_list.h"
#include "payroll.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

PayRollList::PayRollList(){ 
  head = nullptr; //initializes head to nullptr
}

PayRollList::~PayRollList(){
  ListNode *cursor = head;
  while (cursor){ //walks though the list
    cursor = cursor -> next;
    delete head; //deletes head 
    head = cursor; //deletes the content of the linked list following head
  }
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
            std::cout << cursor -> p.getName() << " (payrate: $" << cursor -> p.getPay() << "/per hour)" << ": " << cursor -> p.calcWage();
            std::cout << std::endl;
            cursor = cursor -> next;
    }
    std::cout << "========================================" << std::endl;
  }
  

