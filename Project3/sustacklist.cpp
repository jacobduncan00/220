#include "sustacklist.h"

template <class DataType>
SUStackList<DataType>::SUStackList(){

}

template <class DataType>
SUStackList<DataType>::SUStackList(const SUStackList& obj){

}

template <class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType>& obj){
 
}

template <class DataType>
SUStackList<DataType>::~SUStackList(){

}

template <class DataType>
int SUStackList<DataType>::size() const{
  return list.size();
}

template <class DataType>
bool SUStackList<DataType>::isEmpty() const{
  if (list.size() != 0){
    return false;
  }
  else{
    return true;
  }
}

template <class DataType>
void SUStackList<DataType>::push(const DataType& obj){
  list.putBack(obj);
}

template <class DataType>
void SUStackList<DataType>::pop(DataType& obj){
  list.getFront();
}

template <class DataType>
void SUStackList<DataType>::printStack() const{
  list.print();
}
