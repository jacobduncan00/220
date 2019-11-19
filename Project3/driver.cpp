#include <iostream>
#include "sulist.h"

int main(){
  SUList<int> test;
  std::cout << std::endl;
  std::cout << "| TESTING PUT FRONT           | Inserting 5 in front" << std::endl;
  test.putFront(5);
  std::cout << "| TESTING PUT BACK            | Inserting 2 and 3 on the back" << std::endl;
  test.putBack(2);
  test.putBack(3);
  std::cout << "| TESTING PRINT FUNCTION      | Printing List: ";
  test.print();
  //std::cout << "=============" << std::endl;
  //test.print();
  int i = test.size();
  //std::cout << std::endl;
  std::cout << "| TESTING SIZE FUNCTION       | Number of Elements in List: " << i << std::endl;
  //std::cout << std::endl;
  std::cout << "| TESTING COPY CONSTRUCTOR    |";
  SUList<int> copyTest(test);
  //std::cout << "| TESTING PRINT FUNCTION     | Printing Copied List: ";
  //copyTest.print();
  int j = test.getFront();
  std::cout << "| TESTING GET FRONT FUNCTION  | Front of List: " << j << std::endl;
  int h = test.getBack();
  std::cout << "| TESTING GET BACK FUNCTION   | Back of List: " << h << std::endl;
  SUList <int> tester;
  tester.putFront(7);
  tester.putFront(2);
  tester.putBack(5);
  std::cout << "| TESTING ASSIGNMENT OPERATOR | Overwriting List:";
  test = tester;
  //test.print();
  std::cout << "| TESTING CONTAINS FUNCTION   | Testing if 5 is a member of the list: ";
  bool flag = test.contains(5);
  std::cout << std::endl;
  return 0;
}
