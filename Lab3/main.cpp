//Code by Jacob Duncan
//Salisbury University
//COSC-220 Joseph Anderson

/*
	* This program is a linked list of employees and their data
	* The functionality is to read employee names, payrate, and hours from a text file
	* and insert that data into a linked list
	* the user can select which insert function they wish to use for the insertion 
	* into the linked list
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
		r.printPayChecks(); //calls the print function to print the name and total pay
		std::cout << std::endl;
		return 0;
	}
