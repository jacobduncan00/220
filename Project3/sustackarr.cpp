#include <iostream>
#include "sustackarr.h"


template <class DataType>
SUStackArr<DataType>::SUStackArr(){ // default constructor
  capacity = 3;
  top = -1;
  arr = new DataType[capacity];
}

template <class DataType>
SUStackArr<DataType>::SUStackArr(const SUStackArr& right){ // copy constructor
  std::cout << "Copy Constructor Called...";
  capacity = right.capacity;
  top = right.top;
  arr = new DataType[capacity];
  for(int i = 0; i < capacity; i++){
    arr[i] = right.arr[i];
  }
  std::cout << "Copied Successfully!" << std::endl;
}

template <class DataType>
SUStackArr<DataType>& SUStackArr<DataType>::operator=(const SUStackArr<DataType>& right){ // assignment operator
  std::cout << "Overloaded Assignment Operator Called...";
  delete[] this->arr;
  capacity = right.capacity;
  top = right.top;
  this->arr = new DataType[capacity];
  for (int i = 0; i < capacity; i++){
    this->arr[i] = right.arr[i];
  }
  std::cout << "Stack Successfully Overwritten...";
  return *this;
}

template <class DataType>
SUStackArr<DataType>::~SUStackArr(){ // destructor
  delete[] arr;
}

template <class DataType>
int SUStackArr<DataType>::size() const{ // returns the size of the stack
  return top + 1;
}

template <class DataType>
bool SUStackArr<DataType>::isEmpty() const{ // returns a boolean value based off if the stack is empty or not
  if (size() == 0){
  	std::cout << "Stack is Empty..." << std::endl;
  	return true;
  }
  else{
  	std::cout << "Stack is NOT Empty..." << std::endl;
  	return false;
  }
}

template <class DataType>
void SUStackArr<DataType>::push(const DataType& obj){ // pushes onto the top of the stack 
  if(top == capacity - 1){
    capacity++;
    arr = copyArr(arr, capacity, top);
    top++;
    arr[top] = obj;
  }else{
    top++;
    arr[top] = obj;
  }
}

template <class DataType>
void SUStackArr<DataType>::pop(DataType& obj){ // pops a node off the stack
  obj = arr[top];
  top--;
  capacity--;
  arr = copyArr(arr, capacity, top);
}

template <class DataType>
void SUStackArr<DataType>::printStack() const{ 
  for(int i = 0; i < capacity; i++){
    std::cout << arr[i] << " ";
  }
}

template <class DataType>
DataType* SUStackArr<DataType>::copyArr(DataType* arr, int c, int t){ // copy arr function used by pop 
  DataType* newArr;
  newArr = new DataType[c];
  for(int i = 0; i <= t; i++){
    newArr[i] = arr[i];
  }
  return newArr;
}