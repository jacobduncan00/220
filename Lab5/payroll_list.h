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
  ListNode *current = nullptr;

public:
  PayRollList(); //constructor
  PayRollList(PayRollList&);
  ~PayRollList(); //destructor
  int length(); // function to find the length of the linked list
  void assign(int, PayRoll); // function to assign a PayRoll object to a specific index
  void remove(int); // function to remove a specified node from the linked list
  PayRoll* operator[](int); // overloaded operator to fetch information from a specific node
  void insert (int, PayRoll); // insert function that allows a node to be inserted at a specific location in the list
  void insert (std::string, double, double); //first insert function that takes individual arguments
  void insert (PayRoll); //second insert function that takes Payroll object as argument
  void printPayChecks(); //function to print employee name and total pay
};

#endif
