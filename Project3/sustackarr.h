#ifndef SUSTACKARR_H
#define SUSTACKARR_H
#include "sustackarr.cpp"

template <class DataType>
class SUStackArr{
private:
  DataType* arr;        // The array of items
  int capacity;   // The size of the current array
  int top;        // The location of the top element
public:
  SUStackArr();                   // Constructor
  SUStackArr(const SUStackArr &); // Copy Constructor
  ~SUStackArr();                  // Destructor
  int size() const;               // get the number of elements in the stack
  bool isEmpty() const;           // Check if the stack is empty
  void push(const DataType&);     // Pushes an object onto the stack
  void pop(DataType&);            // Pop an object off the stack and store it
  void printStack() const;        // Prints the stack from the top, down
  SUStackArr<DataType>& operator=(const SUStackArr<DataType>&); // Assignment operator
};

#endif
