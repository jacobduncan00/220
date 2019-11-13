#include <iostream>
#include "sulist.h"

int main(){
  SUList<int> test;
  std::cout << std::endl;
  std::cout << "Inserting 5 in front, then 2 & 3 in back" << std::endl;
  std::cout << std::endl;
  test.putFront(5);
  test.putBack(2);
  test.putBack(3);
  test.print();
  int i = test.size();
  std::cout << std::endl;
  std::cout << "# of Elements in List: " << i << std::endl;
  std::cout << std::endl;
  std::cout << "Printing Copied List" << std::endl;
  SUList<int> copyTest(test); // PROBLEM WITH COPY CONST
  copyTest.print();
  return 0;
}
