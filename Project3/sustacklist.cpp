#include "sustacklist.h"

template <class DataType>
SUStackList<DataType>::SUStackList(){ // default constructor -> done by SUList

}

template <class DataType>
SUStackList<DataType>::SUStackList(const SUStackList& obj){ // copy constructor -> done by SUList
  std::cout << "Copy Constructor Called...";
  std::cout << "Stack Copied Successfully!" << std::endl;
}

template <class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType>& obj){ // overloaded assignment operator -> done by SUList
 
}

template <class DataType>
SUStackList<DataType>::~SUStackList(){ // destructor -> done by SUList

}

template <class DataType>
int SUStackList<DataType>::size() const{ // returns the size of the stack
  return list.size();
}

template <class DataType>
bool SUStackList<DataType>::isEmpty() const{ // returns a boolean value whether the stack is empty or not
  if (size() != 0){
    std::cout << "Stack is NOT Empty" << std::endl;
    return false;
  }
  else{
    std::cout << "Stack is Empty" << std::endl;
    return true;
  }
}

template <class DataType>
void SUStackList<DataType>::push(const DataType& obj){ // pushes node onto stack
  list.putBack(obj);
}

template <class DataType>
void SUStackList<DataType>::pop(DataType& obj){ // pops node off stack
  list.getBack();
}

template <class DataType>
void SUStackList<DataType>::printStack() const{ // prints the contents of the stack
  if (size() == 0){
    std::cout << "Stack is Empty!" << std::endl;
    return;
  }
  else{
    list.print();
  }
}
