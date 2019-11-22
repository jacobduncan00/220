#include <iostream>
#include "sulist.h"
#include "sustacklist.h"
#include "suqueuearr.h"
#include "sustackarr.h"
#include "suqueuelist.h"

int main(){
  SUList<int> test;
  std::cout << std::endl;
  std::cout << "ＳＵＬｉｓｔ　ＴＥＳＴ" << std::endl;
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




  std::cout << "ＳＵＳｔａｃｋＡｒｒ　ＴＥＳＴ" << std::endl;
  std::cout << std::endl;
  SUStackArr<int> boop;
  std::cout << "| TESTING PUSH FUNCTION       | Pushing 5 9 17" << std::endl;
  boop.push(5);
  boop.push(9);
  boop.push(17);
  std::cout << "| TESTING POP FUNCTION        | Popping Once" << std::endl; 
  int hold = 0;
  boop.pop(hold);
  std::cout << "| TESTING PRINT FUNCTION      | Printing Stack: ";
  boop.printStack();
  std::cout << std::endl;
  std::cout << "| TESTING SIZE FUNCTION       | Number of Elements in Stack: ";
  int k = boop.size();
  std::cout << k << std::endl;
  std::cout << "| TESTING COPY CONSTRUCTOR    | ";
  std::cout << std::endl;
  std::cout << "| TESTING ASSIGNMENT OPERATOR | Overwriting Stack: ";
  //SUStackArr<int> assStack;
  //assStack.push(2);
  //assStack.push(9);
  //boop = assStack;
  //boop.printStack();
  //SUStackArr<int> copyBoop(boop); COPY CONST BROKEN
  std::cout << std::endl;
  std::cout << "| TESTING ISEMPTY FUNCTION    | ";
  bool empty = boop.isEmpty();
  std::cout << std::endl;




  std::cout << "ＳＵＳｔａｃｋＬｉｓｔ　ＴＥＳＴ" << std::endl;
  std::cout << std::endl;
  SUStackList<int> ok;
  std::cout << "| TESTING PUSH FUNCTION       | Pushing 8 3 6" << std::endl;
  ok.push(8);
  ok.push(3);
  ok.push(6);
  std::cout << "| TESTING POP FUNCTION        | Popping Once" << std::endl;
  int holder = 0;
  ok.pop(holder);
  std::cout << "| TESTING PRINT FUNCTION      | Printing Stack: ";
  //ok.printStack();
  std::cout << std::endl;
  std::cout << "| TESTING SIZE FUNCTION       | Number of Elements in Stack: ";
  int r = ok.size();
  std::cout << r << std::endl;
  std::cout << "| TESTING ISEMPTY FUNCTION    | ";
  bool SUStackListEmpty = ok.isEmpty();
  std::cout << std::endl;

  std::cout << "ＳＵＱｕｅｕｅＡｒｒ　ＴＥＳＴ" << std::endl;
  std::cout << std::endl;
  SUQueueArr<int> lol;
  std::cout << "| TESTING ENQUEUE FUNCTION    | Adding 5 2 3 to Queue" << std::endl;
  lol.enqueue(5);
  lol.enqueue(2);
  lol.enqueue(3);
  std::cout << "| TESTING PRINT FUNCTION      | Printing Queue: ";
  lol.printQueue();
  std::cout << std::endl;
  std::cout << "| TESTING DEQUEUE FUNCTION    | Using dequeue once, printing value held: ";
  int deholder = 0;
  lol.dequeue(deholder);
  std::cout << deholder << std::endl;
  std::cout << "| TESTING PRINT FUNCTION      | Printing Queue: ";
  lol.printQueue();
  std::cout << std::endl;
  std::cout << "| TESTING ISEMPTY FUNCTION    | ";
  bool qaempty = lol.isEmpty();
  std::cout << "| TESTING SIZE FUNCTION       | Number of Elements in Queue: ";
  int sizeOfQueue = lol.size();
  std::cout << sizeOfQueue << std::endl;
  std::cout << "| TESTING COPY CONSTRUCTOR    |";
  //SUQueueArr<int> copyLol(lol);   COPY CONST BROKEN
  std::cout << std::endl;


  std::cout << std::endl;
  std::cout << "ＳＵＱｕｅｕｅＬｉｓｔ　ＴＥＳＴ" << std::endl;
  std::cout << std::endl;
  SUQueueList<int> intQueueList;
  std::cout << "| TESTING ENQUEUE FUNCTION    | Adding 9 5 2 to Queue" << std::endl;
  intQueueList.enqueue(9);
  intQueueList.enqueue(5);
  intQueueList.enqueue(2);
  std::cout << "| TESTING PRINT FUNCTION      | Printing Queue: ";
  //intQueueList.printQueue();
  std::cout << std::endl;
  std::cout << "| TESTING DEQUEUE FUNCTION    | Using dequeue once, printing value held: ";
  int deholder2 = 0;
  intQueueList.dequeue(deholder2);
  std::cout << deholder2 << std::endl;
  std::cout << "| TESTING ISEMPTY FUNCTION    | ";
  bool intQueueListEmpty = intQueueList.isEmpty();
  std::cout << "| TESTING SIZE FUNCTION       | Number of Elements in Queue: ";
  int sizeOfintQueue = intQueueList.size();
  std::cout << sizeOfintQueue << std::endl;
  /*

  SUQueueArr<int> beep;
  beep.printQueue();

  */
  return 0;
}
