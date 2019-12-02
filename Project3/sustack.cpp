#include "sustack.h"
#include <iostream>

template <class DataType>
SUStackArr<DataType>::SUStackArr(){ // default constructor, does not take any arguments, sets the capacity of the array to 3 (Testing Purposes), the top to -1 and creates the array
	capacity = 3;
	top = -1;
	arr = new DataType[capacity];
}

template <class DataType>
SUStackArr<DataType>::SUStackArr(const SUStackArr& right){ // copy constructor, takes in an SUStackArr by reference and copies to the left hand side
	std::cout << "Copy Constructor Called...";
	capacity = right.capacity;
	top = right.top;
	arr = new DataType[capacity];
	for(int i = 0; i < capacity; i++){ // copies each element in the right hand side to the left hand side
		arr[i] = right.arr[i];
	}
	std::cout << "Copied Successfully!" << std::endl;
}

template <class DataType>
SUStackArr<DataType>& SUStackArr<DataType>::operator=(const SUStackArr<DataType>& right){ // assignment operator, has a left and right hand side, allows for overwriting SUStackArr's
	std::cout << "Overloaded Assignment Operator Called...";
	delete[] this->arr;
	capacity = right.capacity;
	top = right.top;
	this->arr = new DataType[capacity];
	for (int i = 0; i < capacity; i++){ // takes the left hand side and set's it equal to the value of the right hand side (assigning right to left)
		this->arr[i] = right.arr[i];
	}
	std::cout << "Stack Successfully Overwritten...";
	return *this;
}

template <class DataType>
SUStackArr<DataType>::~SUStackArr(){ // destructor, takes in no arguments, deletes the array (Stack)
	delete[] arr;
}

template <class DataType>
int SUStackArr<DataType>::size() const{ // returns the size of the stack, no argument just outputs the number of elements
	return top + 1;
}

template <class DataType>
bool SUStackArr<DataType>::isEmpty() const{ // returns a boolean value based off if the stack is empty or not, no input, just a boolean output
	if (size() == 0){ // if the size of the SUStackArr is 0, then the stack is empty
		std::cout << "Stack is Empty..." << std::endl;
		return true; // if it is empty, return true
	}
	else{ // if it is not empty return false
		std::cout << "Stack is NOT Empty..." << std::endl;
		return false;
	}
}

template <class DataType>
void SUStackArr<DataType>::push(const DataType& obj){ // pushes onto the top of the stack, takes a datatype by reference
	if(top == capacity - 1){ // if array is too small, increase the capacity
		capacity++;
		arr = copyArr(arr, capacity, top); // copy the contents of the old array to the new array with bigger capacity
		top++;
		arr[top] = obj;
	}else{ // else, if it can fit, push on top of stack
		top++;
		arr[top] = obj;
	}
}

template <class DataType>
void SUStackArr<DataType>::pop(DataType& obj){ // pops a node off the stack, takes a datatype by reference 
	obj = arr[top]; // top of the array is what is being poppe
	top--; // decreases top to the previous
	capacity--; // decreases capacity as one element is now gone
	arr = copyArr(arr, capacity, top); // copies onto new array as capacity and top have changed
}

template <class DataType>
void SUStackArr<DataType>::printStack() const{ // prints the elements in the Stack, simple for loop that prints every index of the array
	for(int i = 0; i < capacity; i++){
		std::cout << arr[i] << " ";
	}
}

template <class DataType>
DataType* SUStackArr<DataType>::copyArr(DataType* arr, int c, int t){ // copy arr function that is used to update the array as it is pushed or popped
	DataType* newArr;
	newArr = new DataType[c]; // creates new array with new capacity "c"
	for(int i = 0; i <= t; i++){ // makes sure that it fills to the top
		newArr[i] = arr[i]; // sets the contents of the new array to the same as the old, considering the changes
	}
	return newArr; // returns the new array
}

template <class DataType>
SUStackList<DataType>::SUStackList(){ // default constructor -> done by SUList

}

template <class DataType>
SUStackList<DataType>::SUStackList(const SUStackList& obj){ // copy constructor -> done by SUList
	std::cout << "Copy Constructor Called...";
	std::cout << "Stack Copied Successfully!" << std::endl;
}

/*
template <class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType>& obj){ // overloaded assignment operator -> done by SUList
 
}
*/

template <class DataType>
SUStackList<DataType>::~SUStackList(){ // destructor -> done by SUList

}

template <class DataType>
int SUStackList<DataType>::size() const{ // returns the size of the stack, no input, called on an SUStackList and returns an integer value 
	return list.size();
}

template <class DataType>
bool SUStackList<DataType>::isEmpty() const{ // returns a boolean value whether the stack is empty or not
	if (size() != 0){
		std::cout << "Stack is NOT Empty" << std::endl;
		return false; // if stack is not empty return false
	}
	else{
		std::cout << "Stack is Empty" << std::endl;
		return true; // if stack is empty return true
	}
}

template <class DataType>
void SUStackList<DataType>::push(const DataType& obj){ // pushes node onto stack
	list.putBack(obj); // uses SUList implementation to do stack functionality
}

template <class DataType>
void SUStackList<DataType>::pop(DataType& obj){ // pops node off stack
	list.getBack(); // uses SUList implementation to do stack functionality
}

template <class DataType>
void SUStackList<DataType>::printStack() const{ // prints the contents of the stack
	if (size() == 0){ // if size is 0, then the stack is empty and cannot be printed
		std::cout << "Stack is Empty!" << std::endl;
		return;
	}
	else{
		list.print(); // uses SUList implementation to print the contents of the stack 
	}
}