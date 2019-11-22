#include "suqueuelist.h"

template <class DataType>
SUQueueList<DataType>::SUQueueList(){

}

template <class DataType>
SUQueueList<DataType>::SUQueueList(const SUQueueList& obj){

}

template <class DataType>
SUQueueList<DataType>& SUQueueList<DataType>::operator=(const SUQueueList<DataType>& obj){
 
}

template <class DataType>
SUQueueList<DataType>::~SUQueueList(){

}

template <class DataType>
int SUQueueList<DataType>::size() const{
  return list.size();
}

template <class DataType>
bool SUQueueList<DataType>::isEmpty() const{
  if (list.size() != 0){
  	std::cout << "Queue is NOT Empty" << std::endl;
    return false;
  }
  else{
  	std::cout << "Queue is Empty" << std::endl;
    return true;
  }
}

template <class DataType>
void SUQueueList<DataType>::enqueue(const DataType& obj){
  list.putBack(obj);
}

template <class DataType>
void SUQueueList<DataType>::dequeue(DataType& obj){
  if (size() != 0){
  	obj = list.getFront();
  }
  return;
}

template <class DataType>
void SUQueueList<DataType>::printQueue() const{
	if (isEmpty()){
		std::cout << "Queue is Empty!";
		return;
	}
	else{
		list.print();
	}
}
