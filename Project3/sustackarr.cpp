#include <iostream>
#include "sustackarr.h"


template <class DataType>
SUStackArr<DataType>::SUStackArr(){ 
  capacity = 3;
  top = -1;
  arr = new DataType[capacity];
}

template <class DataType>
SUStackArr<DataType>::SUStackArr(const SUStackArr& right){ 
  std::cout << "Copy Constructor Called...";
  capacity = right.capacity;
  top = right.top;
  for(int i = 0; i < capacity; i++){
    arr[i] = right.arr[i];
  }
  std::cout << "Copied Successfully!" << std::endl;
}

template <class DataType>
SUStackArr<DataType>::~SUStackArr(){ 
  delete[] arr;
}

template <class DataType>
int SUStackArr<DataType>::size() const{ 
  return top + 1;
}

template <class DataType>
bool SUStackArr<DataType>::isEmpty() const{ 
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
void SUStackArr<DataType>::push(const DataType& d){ 
  if(top == capacity - 1){
    capacity++;
    arr = copyArr(arr, capacity, top);
    top++;
    arr[top] = d;
  }else{
    top++;
    arr[top] = d;
  }
}

template <class DataType>
void SUStackArr<DataType>::pop(DataType& d){ 
  d = arr[top];
  top--;
  capacity--;
  arr = copyArr(arr, capacity, top);
}

template <class DataType>
void SUStackArr<DataType>::printStack() const{ 
  for(int i = capacity -1; i > -1; i--){
    std::cout << arr[i] << " ";
  }
}

template <class DataType>
SUStackArr<DataType>& SUStackArr<DataType>::operator=(const SUStackArr<DataType>&){ 
  
}

template <class DataType>
DataType* SUStackArr<DataType>::copyArr(DataType* arr, int cap, int t){
  DataType* newArr;
  newArr = new DataType[cap];
  //std::cout << cap << std::endl;
  for(int i = 0; i <= t; i++){
    newArr[i] = arr[i];
  }
  return newArr;
}