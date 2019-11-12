#include "mystack.h"
#include "payroll.h"

// By Jacob Duncan @ Salisbury University
// This is a templated stack that can take PayRoll Objects, strings, and ints

int main(){

  MyStack<int> test;                                              // INT VERSION OF MYSTACK
  std::cout << std::endl;
  std::cout << "******************" << std::endl;
  std::cout << "Pushing 5, 2, 7..." << std::endl;
  std::cout << "******************" << std::endl;
  std::cout << std::endl;
  test.push(5);
  test.push(2);  // pushing values
  test.push(7);
  std::cout << "Printing Stack" << std::endl;
  test.print(); // printing
  std::cout << "Making Copy of Stack..." << std::endl;
  MyStack<int> testCopy(test); // using copy constructor
  std::cout << "Printing Copy of Stack" << std::endl;
  testCopy.print(); // printing copy
  std::cout << "Creating New Stack..." << std::endl;
  MyStack<int> equalTest; // making new stack
  equalTest.push(4);
  equalTest.push(2);    // pushing to new stack
  equalTest.push(3);
  std::cout << "Printing New Stack" << std::endl;
  equalTest.print(); // printing new stack
  std::cout << "Overwriting Original Stack with New Stack..." << std::endl;
  test = equalTest; // using assignment operator 
  std::cout << "Printing Original Stack" << std::endl;
  test.print(); // printing original stack which is now overwritten
  int i = test.peek(); // peeking stack and assigning to i
  std::cout << "Peeking Stack: " << i<< std::endl;
  std::cout << "=============" << std::endl;
  int hold = 0;
  std::cout << "Popping Stack..." << std::endl;
  test.pop(hold); // popping stack
  std::cout << "Contents of Popped Node: " << hold << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  std::cout << "Popping Stack..." << std::endl;
  test.pop(hold);
  std::cout << "Contents of Popped Node: " << hold << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  std::cout << "Popping Stack..." << std::endl;
  test.pop(hold);
  std::cout << "Contents of Popped Node: " << hold << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  std::cout << std::endl;

  MyStack<std::string> test1;                                          // STRING VERSION OF MYSTACK ^^ does the same operations as above besides assignement operator
  std::cout << "******************************" << std::endl;
  std::cout << "Pushing Blaine, Ryan, Jacob..." << std::endl;
  std::cout << "******************************" << std::endl;
  std::cout << std::endl;
  test1.push("Blaine");
  test1.push("Ryan");
  test1.push("Jacob");
  std::cout << "Printing Stack" << std::endl;
  test1.print();
  std::cout << "Making Copy of Stack..." << std::endl;
  MyStack<std::string> test1Copy(test1);
  std::cout << "Printing Copy of Stack" << std::endl;
  test1Copy.print();
  std::string j = test1.peek();
  std::cout << "Peeking Stack: " << j << std::endl;
  std::cout << "=============" << std::endl;
  std::cout << std::endl;
  std::string temp = " ";
  std::cout << "Popping Stack..." << std::endl;
  test1.pop(temp);
  std::cout << "Contents of Popped Node: " << temp << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test1.print();
  std::cout << "Popping Stack..." << std::endl;
  test1.pop(temp);
  std::cout << "Contents of Popped Node: " << temp << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test1.print();
  std::cout << "Popping Stack..." << std::endl;
  test1.pop(temp);
  std::cout << "Contents of Popped Node: " << temp << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test1.print();

  MyStack<PayRoll> test2;                                                   // PayRoll VERSION OF MYSTACK
  PayRoll Rob("Rob", 10, 12.50);
  PayRoll Jacob("Jacob", 11, 19.25);
  PayRoll Ryan("Ryan", 4, 13);
  std::cout << std::endl;
  std::cout << "*******************************************" << std::endl;
  std::cout << "Pushing 3 PayRoll Objects: Rob, Jacob, Ryan" << std::endl;
  std::cout << "*******************************************" << std::endl;
  test2.push(Rob);
  test2.push(Jacob);
  test2.push(Ryan);
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test2.print();
  std::cout << "Making Copy of Stack..." << std::endl;
  MyStack<PayRoll> test2Copy(test2);
  std::cout << "Printing Copy of Stack" << std::endl;
  test2Copy.print();
  PayRoll k = test2.peek();
  std::cout << "Peeking Stack: " << std::endl;
  std::cout << k << std::endl;
  std::cout << "=============" << std::endl;
  PayRoll temp1("", 0, 0);
  std::cout << "Popping Stack..." << std::endl;
  test2.pop(temp1);
  std::cout << "Contents of Popped Node: " << std::endl;
  std::cout << "======================== " << std::endl;
  std::cout << temp1 << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test2.print();
  std::cout << "Popping Stack..." << std::endl;
  test2.pop(temp1);
  std::cout << "Contents of Popped Node: " << std::endl;
  std::cout << "======================== " << std::endl;
  std::cout << temp1 << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test2.print();
  std::cout << "Popping Stack..." << std::endl;
  test2.pop(temp1);
  std::cout << "Contents of Popped Node: " << std::endl;
  std::cout << "======================== " << std::endl;
  std::cout << temp1 << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test2.print();

  return 0;
}
