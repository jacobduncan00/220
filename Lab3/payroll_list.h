#ifndef PAYROLLLIST_H
#define PAYROLLLIST_H
#include "payroll.h"

class PayRollList{

private:
  struct ListNode{ //Linked List
    PayRoll p; //data held in node
    ListNode *next; //pointer to next node
  };

  ListNode *head; //head or beginning of the linked list

public:
  PayRollList(); //constructor
  ~PayRollList(); //destructor
  void insert (std::string, double, double); //first insert function that takes individual arguments
  void insert (PayRoll); //second insert function that takes Payroll object as argument
  void printPayChecks(); //function to print employee name and total pay
};

#endif
