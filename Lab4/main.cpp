//Code by Jacob Duncan
//Salisbury University
//COSC-220 Joseph Anderson

/*
	* This program is a linked list of employees and their data
	* The functionality is to read employee names, payrate, and hours from a text file
	* and insert that data into a linked list
	* the user can select which insert function they wish to use for the insertion
	* into the linked list. Once you select which insert function you wish to use
	* you will see an example of each of the new functions of the program being used
	* First we will copy the original linked list by using a copy constructor
	* Then we will assign a new employee to the copied list and essentially over-write
	* the employee in the place of the one we are assigning.
	* Next we will remove a node from the list, in our program we removed the 3rd index
	* of the linked list which was Becky.
	* After using the remove function we can see the insert function in use when the program
	* inserts Timothy and Justin into the list at the specific index.
	* Then the program prints the length of the linked lists, the first linked list that was read
	* from the file had 5 nodes and the copied list that we modified by removing 1 employee and adding
	* two more totalled to 6 nodes (employees).
	* Following the length function in use, the program uses the overloaded [] operator to find the
	* information of the employee in a certain index in the linked list. In our case, the program
	* looks at the 3rd index in the copied list and find Grants and then looks for the 2nd index
	* in the copied list and finds Timothy which are both correct.
*/

#include <iostream>
#include <fstream>
#include "payroll.h"
#include "payroll_list.h"

int main (){

	std::string empName;
	double payRate;
	double hr;

	PayRollList r; //object of PayRollList

	std::ifstream file("db.txt"); //opens db text file to read in names, pay rates, and hours worked
	std:: string fileName; //assigned
	std::cout << "=============================================================" << std::endl;
	std::cout << "If you would like to use the first insert function press [1] "<< std::endl;
	std::cout << "If you would like to use the second insert function press [2]" << std::endl;
	std::cout << "=============================================================" << std::endl;
	int userInput;
	std::cin >> userInput; //user Input to see if which insert function they would like to use
	std::cout << "=======================================" << std::endl;
	while (userInput != 1 && userInput != 2){ //input validation
		std::cout << "That is not a valid input, please try again: ";
		std::cin >> userInput;
	}
	while (file >> fileName){ //while the file has a name to read in
		double a;
		double b;
		file >> a >> b; //read in a and b which are the double values of payRate and hours in the file
		if (userInput == 1){
			r.insert(fileName, a, b); //uses first insert function
		}
		PayRoll p(fileName, a, b); //assigns input into a payroll object p
		if (userInput == 2){
			r.insert(p); //uses second insert function
		}
	}
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "        *ORIGINAL LINKED LIST*           " << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "=======================================" << std::endl;
		r.printPayChecks(); //calls the print function to print the name and total pay
		PayRollList l(r); //uses copy constructor to copy the original linked list
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "         *COPIED LINKED LIST*           " << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "=======================================" << std::endl;
		l.printPayChecks(); // prints the copied link list which will mirror the original
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "    *COPIED LINKED LIST USING ASSIGN*     " << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "==========================================" << std::endl;
		PayRoll x ("Joseph", 22.50, 40); // creates new PayRoll object named x
		l.assign(4,x); // calls assign function and over-writes the current employee in index 4 and puts the information of PayRoll x in the 4th index
		l.printPayChecks(); // calls the print function to print the name and total pay
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "    *COPIED LINKED LIST USING REMOVE*     " << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "==========================================" << std::endl;
		l.remove(3); // calls the remove function and removes the node at the 3rd index of the list
		l.printPayChecks(); // calls the print function to print the name and total pay
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "COPIED LINKED LIST USING NEW INSERT FUNCTION" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "============================================" << std::endl;
		PayRoll g ("Timothy", 43, 10); // creates new PayRoll object named g
		PayRoll z ("Justin", 23, 43); // creates new PayRoll object named z
		l.insert(2,g); // calls insert function which inserts a new node with the specified PayRoll object at a specific index
		l.insert(4,z); // calls insert function which inserts a new node with the specified PayRoll object at a specific index
		l.printPayChecks(); // calls the print function to print the name and total pay
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "           *LENGTH OF LISTS*           " << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "=======================================" << std::endl;
		std::cout << "Original linked list = " << r.length() << " Nodes" << std::endl; // calls the length function to find the length of the original linked list
		std::cout << "Copied (updated) linked list = " << l.length() << " Nodes" << std::endl; // calls the length function to find the length of the copied (modified) linked list
		std::cout << "=======================================" << std::endl;
		std::cout << "=======================================" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "     *OVERLOADED [] OPERATOR USED *    " << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "=======================================" << std::endl;
		std::cout << "Fetching information for the 3rd index " << std::endl;
		std::cout << "of the original linked list:           " << std::endl;
		std::cout << "=======================================" << std::endl;
		PayRoll* q = l[3]; // uses the overloaded [] operator to fetch the information from the specified index
		q -> printInfo(); // prints info of the node at the specified index
		std::cout << "Fetching information for the 2nd index " << std::endl;
		std::cout << "of the copied linked list:           " << std::endl;
		std::cout << "=======================================" << std::endl;
		PayRoll* s = l[2]; // uses the overloaded [] operator to fetch the information from the specified index
		s -> printInfo(); // prints info of the node at the specified index
		return 0;
	}
