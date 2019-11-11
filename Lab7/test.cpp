#include <iostream>
#include <cstdlib>

// By Jacob Duncan @ Salisbury University
// 
// This program will allow the user to choose
// What functions they want to test
// All functions are done recurisvely
// As per instructions on Dr. Andersons
// Lab instructions
// Enjoy

struct Node{ // Node for linked list
  int value;
  Node* next;

  Node(){ // default constructor
    value = 0;
    next = nullptr;
  }

  Node(int n){ // constructor with parameters
    value = n;
    next = nullptr;
  }
};

int length(Node* head){ // function to get the length of the linked list
  if (head == nullptr){
    return 0;
  }
  int count = 1 + length(head -> next);
  return count;
}

void print(Node* head){ // function to print the contents of the linked list
  if(head == nullptr){
    std::cout << "List is Empty" << std::endl;
    return;
  }
  else{
    std::cout << head -> value << std::endl;
    if (head -> next != nullptr){
      print(head -> next);
    }
  }
}

void reversePrint(Node* head){ // function to print the contents of the linked list in reverse
  if(head == nullptr){
    std::cout << "List is Empty" << std::endl;
    return;
  }
  else {
    if (head -> next != nullptr){
      reversePrint(head -> next);
    }
    std::cout << head -> value << " " << std::endl;
  }
}

Node* insertSorted(Node* head, int insertVal){ // function to insert a value into a linked list that is already sorted
  if (head == nullptr){
    head = new Node(insertVal);
    return head;
  }
  if (insertVal < head -> value){
    head = new Node(insertVal);
    return head;
  }
  head -> next = insertSorted(head -> next, insertVal);
  return head;
}

Node* remove(Node* head, int removeVal){ // function to remove a value from a linked list
  if (removeVal < 1){
    return head;
  }
  if (head == nullptr){
    return nullptr;
  }
  if (head -> value == removeVal){
    Node* prev;
    Node* temp;
    prev = temp;
    temp = head -> next;
    delete head;
    return temp;
  }
  head -> next = remove(head -> next, removeVal);
  return head;
}

Node* appendList(Node* head1, Node* head2){  // function to append a linked list to the end of another linked list
  if (head1 -> next != nullptr){
    head1 -> next = appendList(head1 -> next, head2);
  }
  else {
    head1 -> next = head2;
  }
  return head1;
}

Node* Reverse(Node* head) // function to reverse the pointers in a linked list 
{
  if (head -> next == nullptr){
    return head;
  }
  Node* temp = Reverse(head -> next);
  head -> next -> next = head;
  head -> next = NULL;
  return temp;
}

int main (){
  std::cout << "--------------------------------------------------" << std::endl;
  std::cout << "1) Tests length, print, and reverse print function" << std::endl;
  std::cout << "2) Tests inserted sort function" << std::endl;
  std::cout << "3) Tests append list function" << std::endl;
  std::cout << "4) Tests reverse list function" << std::endl;
  std::cout << "5) Tests remove function" << std::endl;
  std::cout << "--------------------------------------------------" << std::endl;
  int num;
  do{
    std::cout << "Enter a valid number: ";
    std::cin >> num;
  }while (num < 1 || num > 5);
  std::cout << "----------------------" << std::endl;

  if (num == 1){
    int n = rand() % 10;
    Node* head = new Node(n);
    Node* curr = head;
    for (int i = 1; i < 6; i++){ // creating a linked list of random numbers
      int n = rand() % 10;
      curr -> next = new Node(n);
      curr = curr -> next;
    }
    int len = length(head); // gets length of linked list
    std::cout << "The length is: " << len << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Printing List" << std::endl;
    std::cout << "----------------" << std::endl;
    print(head); // prints linked list
    std::cout << "------------------------" << std::endl;
    std::cout << "Printing List in Reverse" << std::endl;
    std::cout << "------------------------" << std::endl;
    reversePrint(head); // prints linked list in reverse
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Run program again and try another option to test!" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }
  if (num == 2){
    Node* head = new Node(0);
    Node* curr = head;
    for (int i = 1; i < 10; i++){ // creates sorted linked list from 0-9
      curr -> next = new Node(i);
      curr = curr -> next;
    }
    std::cout << "Printing Linked List" << std::endl;
    std::cout << "--------------------" << std::endl;
    print(head); // prints linked list
    head = insertSorted(head, 6); // inserts 6 into the already ordered linked list
    std::cout << "--------------------" << std::endl;
    std::cout << "Printing Linked List with Inserted value" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    print(head); // prints linked list
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Run program again and try another option to test!" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }
  if (num == 3){
    std::cout << "Taking two Linked Lists" << std::endl;
    std::cout << "and appending one list to" << std::endl;
    std::cout << "the end of another list" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    Node* head1 = new Node(0);
    Node* curr1 = head1;
    for (int i = 1; i < 10; i++){ // creates sorted linked list from 0-9
      curr1 -> next = new Node(i);
      curr1 = curr1 -> next;
    }
    std::cout << "Printing Linked List #1" << std::endl;
    std::cout << "-----------------------" << std::endl;
    print(head1); // prints linked list
    std::cout << "-----------------------" << std::endl;
    Node* head2 = new Node(10);
    Node* curr2 = head2;
    for (int i = 11; i < 21; i++){ // creates sorted linked list from 10-20
      curr2 -> next = new Node(i);
      curr2 = curr2 -> next;
    }
    std::cout << "Printing Linked List #2" << std::endl;
    std::cout << "-----------------------" << std::endl;
    print(head2); // prints linked list #2
    std::cout << "-----------------------" << std::endl;
    std::cout << "Printing Linked List #2 appended to Linked List #1" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    head1 = appendList(head1, head2); // appends the second linked list to the end of the first linked list
    print(head1); // prints the entire linked list
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Run program again and try another option to test!" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }
  if (num == 4){
    Node* head = new Node(0);
    Node* curr = head;
    for (int i = 1; i < 10; i++){ // creats a linked list of random numbers
      int n = rand() % 10;
      curr -> next = new Node(n);
      curr = curr -> next;
    }
    std::cout << "Original List" << std::endl;
    std::cout << "-------------" << std::endl;
    print(head); // prints linked list
    std::cout << "-------------" << std::endl;
    std::cout << "Reversed List" << std::endl;
    std::cout << "-------------" << std::endl;
    head = Reverse(head); // reverses the linked list
    print(head); // prints the linked list
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Run program again and try another option to test!" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }
  if (num == 5){
    Node* head = new Node(0);
    Node* curr = head;
    for (int i = 1; i < 10; i++){ // creates a sorted linked list from 0-9
      curr -> next = new Node(i);
      curr = curr -> next;
    }
    std::cout << "Printing Linked List" << std::endl;
    std::cout << "--------------------" << std::endl;
    print(head); // prints the linked list
    std::cout << "---------------------" << std::endl;
    std::cout << "Removing the number 3" << std::endl;
    std::cout << "---------------------" << std::endl;
    Node* removedNode = remove(head, 3); // removes the first node with value 3 
    print(head); // prints the linked list
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Run program again and try another option to test!" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }
  return 0;
}
