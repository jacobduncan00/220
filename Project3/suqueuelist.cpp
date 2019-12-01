#include "suqueuelist.h"

template <class DataType>
SUQueueList<DataType>::SUQueueList(){ // default constructor -> already done by SUList

}

template <class DataType>
SUQueueList<DataType>::SUQueueList(const SUQueueList& obj){ 

}

/*
template <class DataType>
SUQueueList<DataType>& SUQueueList<DataType>::operator=(const SUQueueList<DataType>& obj){
 
}
*/

template <class DataType>
SUQueueList<DataType>::~SUQueueList(){ // destructor -> already done by SUList

}

template <class DataType>
int SUQueueList<DataType>::size() const{ // returns the size of the queue (# of elements in queue)
  return list.size();
}

template <class DataType>
bool SUQueueList<DataType>::isEmpty() const{ // checks to see if the queue is empty
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
void SUQueueList<DataType>::enqueue(const DataType& obj){ // adds to the queue 
  list.putBack(obj);
}

template <class DataType>
void SUQueueList<DataType>::dequeue(DataType& obj){ // removes from the queue (holds and deletes)
  if (size() != 0){
  	obj = list.getFront();
  }
  return;
}

template <class DataType>
void SUQueueList<DataType>::printQueue() const{ // prints the contents of the queue
	if (size() == 0){
		std::cout << "Queue is Empty!";
		return;
	}
	else{
		list.print();
	}
}
