//Code by Jacob Duncan
//Salisbury University
//COSC-220 Joseph Anderson

/*
	This program is a linked list stack in which 7 employees are read from
	a file and put into a linked list Stack. From there, they are copied into
	another linked list Stack via the copy constructor as well as the =
	assignment operator overload. This program shows the functions pop (both),
	push, size, print all at work to display data of a linked list stack.
*/

#include <iostream>
#include <fstream>
#include "payroll.h"
#include "payroll_list.h"
#include "payrollstack.h"

int main (){

	std::string empName;
	double payRate;
	double hr;

	PayRollList r;
	PayRollStack y;

	std::ifstream file("db.txt"); // file implementation, reading 7 employees
	while (file >> empName){
		file >> payRate >> hr;
		r.insert(empName, payRate, hr);
		PayRoll p(empName, payRate, hr);
		y.push(p); // pushing the payroll objects onto the stack
	}
	std::cout << "==========================================\n";
	std::cout << "Printing the Stack" << std::endl;
	y.print();
	std::cout << "Printing the copied Stack" << std::endl;
	PayRollStack z(y); // copy constructor in use to copy y's list to z
	z.print();
	std::cout << "Popping the original Stack" << std::endl;
	y.pop();
	y.print();
	std::cout << "Popping the coppied Stack twice" << std::endl;
	std::cout << "Once using the first pop function" << std::endl;
	std::cout << "and then using the second pop function" << std::endl;
	z.pop();
	PayRoll i;
	z.pop(i);
	z.print();
	std::cout << "Printing the information of the popped node" << std::endl;
	std::cout << "==========================================\n";
	i.printInfo();
	std::cout << "Pushing a node onto the original Stack" << std::endl;
	PayRoll e ("Richard", 43, 23);
	y.push(e); // pushing a specific payroll object onto stack
	y.print();
	std::cout << "Size of the Stacks:" << std::endl;
	std::cout << "==========================================\n";
	std::cout << "Nodes in original Stack: " << y.size() << std::endl;
	std::cout << "Nodes in copied Stack: " << z.size() << std::endl;
	std::cout << "==========================================\n";
	std::cout << "Popping all nodes from original Stack" << std::endl;
	std::cout << "==========================================\n";
	for (int i = 0; i < 6; i++){ // for loop to pop all contents of the original stack
		y.pop();
		y.print();
	}
	std::cout << "Using the Overloaded = Operator" << std::endl;
	std::cout << "==========================================\n";
	PayRoll h ("Tim", 19, 32);
	PayRoll j ("Kim", 21, 13);
	PayRoll k ("Mike", 32, 12);
	PayRoll l ("Anderson", 42, 23);
	PayRoll n ("Trey", 22, 11);
	PayRollStack temp;
	temp.push(h);
	temp.push(j);
	std::cout << "1st PayRollStack" << std::endl;
	temp.print();
	PayRollStack temp2;
	temp2.push(k);
	temp2.push(l);
	temp2.push(n);
	std::cout << "2nd PayRollStack" << std::endl;
	temp2.print();
	temp = temp2;
	std::cout << "Assigning the 2nd PayRollStack to the 1st" << std::endl;
	temp.print();
	return 0;
}
