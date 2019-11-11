#include "template.h"
#include "payroll.h"

int main(){
  MyStack<int> test;
  MyStack<std::string> test1;
  std::cout << std::endl;
  std::cout << "Pushing 5, 2, 7..." << std::endl;
  test.push(5);
  test.push(2);
  test.push(7);
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  int hold = 0;
  std::cout << "Popping Node..." << std::endl;
  test.pop(hold);
  std::cout << "Contents of Popped Node: " << hold << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  std::cout << "Popping Node..." << std::endl;
  test.pop(hold);
  std::cout << "Contents of Popped Node: " << hold << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  std::cout << "Popping Node..." << std::endl;
  test.pop(hold);
  std::cout << "Contents of Popped Node: " << hold << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test.print();
  std::cout << std::endl;
  std::cout << "Pushing Blaine, Ryan, Jacob..." << std::endl;
  test1.push("Blaine");
  test1.push("Ryan");
  test1.push("Jacob");
  std::cout << "Printing Stack" << std::endl;
  test1.print();
  std::string temp = " ";
  test1.pop(temp);
  std::cout << "Printing Stack" << std::endl;
  test1.print();
  std::cout << "Contents of Popped Node: " << temp << std::endl;

  MyStack<PayRoll> test2;
  PayRoll Rob("Rob", 10, 12.50);
  test2.push(Rob);
  std::cout << std::endl;
  std::cout << "Printing Stack" << std::endl;
  test2.print();

  return 0;
}
