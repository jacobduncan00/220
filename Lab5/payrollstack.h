#ifndef PAYROLLSTACK_H
#define PAYROLLSTACK_H
#include "payroll.h"

class PayRollStack{
private:
  struct StackNode{
    PayRoll p;
    StackNode *next;
  };
  StackNode* head;

public:
  PayRollStack();
  ~PayRollStack();
  PayRollStack(const PayRollStack&);
  PayRollStack operator=(const PayRollStack&);
  void push(PayRoll p);
  PayRoll pop();
  void pop(PayRoll&);
  int size();
  void print();
};

#endif
