#include "suqueue.h"
#include <iostream>

template <class DataType>
SUQueueArr<DataType>::SUQueueArr(){ // Constructor
	capacity = 25; // sets capacity of array to 25
	front = 0;
	rear = 0;
	arr = new DataType[capacity]; // creates new array of size 25
}

template <class DataType>
SUQueueArr<DataType>::SUQueueArr(const SUQueueArr &right){ // Copy Constructor
	std::cout << "Copy Constructor Called...";
	capacity = right.capacity;
	front = right.front;
	rear = right.rear;
	arr = new DataType[capacity];
	for(int i = 0; i < capacity; i++){ // matches each element of the new "copied" array to the original array
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
	for(int i = 0; i < capacity; i++){ // sets each element of the new array to the elements of the original, assigning the right hand side to the left
		arr[i] = right.arr[i];
	}
	std::cout << "Stack Successfully Overwritten!" << std::endl;
	return *this;
}

template <class DataType>
SUQueueArr<DataType>::~SUQueueArr(){ // Destructor, deletes the dynamically allocated array in construction
	delete[] arr;
}

template <class DataType>
int SUQueueArr<DataType>::size() const{ // returns the size of the queue, no input, only an integer output
	return rear;
}

template <class DataType>
bool SUQueueArr<DataType>::isEmpty() const{ // checks to see if queue is empty, not input, only a boolean output
	if (size() == 0){ // if stack is empty
		std::cout << "Stack is Empty..." << std::endl;
		return true; // return true
	}
	else{
		std::cout << "Stack is NOT Empty..." << std::endl;
		return false; // if stack is not empty, return false
	}
}

template <class DataType>
void SUQueueArr<DataType>::enqueue(const DataType& add){ // adds data to queue, takes in datatype by reference 
	if(rear > capacity){ // if the queue is at capacity, we cannot add anymore 
		std::cout << "Queue is Full" << std::endl;
		return;
	}else{
		arr[rear] = add; // if queue is not full, we can enqueue more data
		rear++; // increases the rear by one
	}
	return;
}

template <class DataType>
void SUQueueArr<DataType>::dequeue(DataType& del){ // Gets the front element in the queue and store it, takes in a datatype by reference
	if(rear > 0){ // if stack is not empty
		del = arr[front];
		for(int i = 0; i < rear - 1; i++){ // traverses to rear of the array 
			arr[i] = arr[i + 1];
		}
		rear--; // decreases the rear by one
	}
	return;
}

template <class DataType>
void SUQueueArr<DataType>::printQueue() const{ // Prints the queue from the front to the rear
	if(size() == 0){ // if array is empty
		std::cout << "Queue is Empty" << std::endl;
		return;
	}else{
		for(int i = 0; i < rear; i++){ // if array is not empty, go through each index and print
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
	if (list.size() != 0){ // if queue is not empty
		std::cout << "Queue is NOT Empty" << std::endl;
		return false; // return false
	}
	else{
		std::cout << "Queue is Empty" << std::endl;
		return true; // if list is empty, return true
	}
}

template <class DataType>
void SUQueueList<DataType>::enqueue(const DataType& obj){ // adds to the queue 
	list.putBack(obj); // uses list for queue functionality
}

template <class DataType>
void SUQueueList<DataType>::dequeue(DataType& obj){ // removes from the queue (holds and deletes)
	if (size() != 0){ // if queue is not empty
		obj = list.getFront(); // uses list for queue functionality
	}
	return;
}

template <class DataType>
void SUQueueList<DataType>::printQueue() const{ // prints the contents of the queue
	if (size() == 0){ // if queue is empty
		std::cout << "Queue is Empty!";
		return;
	}
	else{
		list.print(); // if queue is not empty, print using list functionality
	}
}

