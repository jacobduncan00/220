#ifndef SUSTACKLIST_H
#define SUSTACKLIST_H
#include "sustacklist.cpp"

template <class DataType>
class SUStackList{
private:
  SUList<DataType> list;
public:
  SUStackList();                   // Constructor
  SUStackList(const SUStackList &); // Copy Constructor
  ~SUStackList();                  // Destructor
  int size() const;               // get the number of elements in the stack
  bool isEmpty() const;           // Check if the stack is empty
  void push(const DataType&);     // Pushes an object onto the stack
  void pop(DataType&);            // Pop an object off the stack and store it
  void printStack() const;        // Prints the stack from the top, down
  SUStackList<DataType>& operator=(const SUStackList<DataType>&); // Assignment operator
};

#endif
