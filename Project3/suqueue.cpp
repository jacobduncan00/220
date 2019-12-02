#include "suqueue.h"
#include <iostream>

template <class DataType>
SUQueueArr<DataType>::SUQueueArr(){ // Constructor
	capacity = 25;
	front = 0;
	rear = 0;
	arr = new DataType[capacity];
}

template <class DataType>
SUQueueArr<DataType>::SUQueueArr(const SUQueueArr &right){ // Copy Constructor
	std::cout << "Copy Constructor Called...";
	capacity = right.capacity;
	front = right.front;
	rear = right.rear;
	arr = new DataType[capacity];
	for(int i = 0; i < capacity; i++){
		arr[i] = right.arr[i];
	}
	std::cout << "Queue Copied Successfully..." << std::endl;
}

template <class DataType>
SUQueueArr<DataType>& SUQueueArr<DataType>::operator=(const SUQueueArr<DataType>& right){ // Overloaded assignment operator
	std::cout << "Overloaded Assignment Operator Called...";
	delete[] arr;
	capacity = right.capacity;
	arr = new DataType[capacity];
	front = right.front;
	rear = right.rear;
	for(int i = 0; i < capacity; i++){
		arr[i] = right.arr[i];
	}
	std::cout << "Stack Successfully Overwritten!" << std::endl;
	return *this;
}

template <class DataType>
SUQueueArr<DataType>::~SUQueueArr(){ // Destructor
	delete[] arr;
}

template <class DataType>
int SUQueueArr<DataType>::size() const{ // returns the size of the queue
	return rear;
}

template <class DataType>
bool SUQueueArr<DataType>::isEmpty() const{ // checks to see if queue is empty
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
void SUQueueArr<DataType>::enqueue(const DataType& add){ // adds data to queue
	if(rear > capacity){
		std::cout << "Queue is Full" << std::endl;
		return;
	}else{
		arr[rear] = add;
		rear++;
	}
	return;
}

template <class DataType>
void SUQueueArr<DataType>::dequeue(DataType& del){ // Gets the front element in the queue and store it
	if(rear > 0){
		del = arr[front];
		for(int i = 0; i < rear - 1; i++){
			arr[i] = arr[i + 1];
		}
		rear--;
	}
	return;
}

template <class DataType>
void SUQueueArr<DataType>::printQueue() const{ // Prints the queue from the front to the rear
	if(front == rear){
		std::cout << "Queue is Empty" << std::endl;
		return;
	}else{
		for(int i = 0; i < rear; i++){
			std::cout << arr[i] << " ";
		}
		return;
	}
}


template <class DataType>
SUQueueList<DataType>::SUQueueList(){ // default constructor -> already done by SUList

}

template <class DataType>
SUQueueList<DataType>::SUQueueList(const SUQueueList& obj){ 
	*this = obj;
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

