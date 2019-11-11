#include <iostream>
#include "payroll.h"

PayRoll::PayRoll(){ //default constructor

}

//constructor that calls the setName and setPay function to automatically
//take in the name and pay every time a new PayRoll objects is created
PayRoll::PayRoll(std::string empName, double payRate, double hr){
  setName(empName);
  setPay(payRate);
  setHours(hr);
}

//function that sets the hours input by the user to the private data member in
//PayRoll class
void PayRoll::setHours(double hr){
  hours = hr;
}

//function that sets the name of the employee in each object
//function also called to the constructor
void PayRoll::setName(std::string empName){
  name = empName;
}

//function that sets the pay rate of the employee in each object
//function also called to the constructor
void PayRoll::setPay(double payRate){
  pay = payRate;
}

//function that fetches the name of employee in each object
//function called on by the printinfo function
std::string PayRoll::getName(){
  return name;
}

double PayRoll::getPay(){
  return pay;
}

double PayRoll::getHours(){
  return hours;
}

//function that calculates the wages of the employee in each object
//function takes the payrate and hours of each object and multiplies
//them together to give the gross income of each employee
double PayRoll::calcWage(){
  double grossIncome = 0;
  grossIncome = pay * hours;
  return grossIncome;
}

//function that prints the information of the employee in each object
void PayRoll::printInfo(){
  std::cout << "Name:         ";
  std::cout << this->getName() << std::endl;
  std::cout << "Pay Rate:     " << pay << std::endl;
  std::cout << "Hours Worked: " << hours << std::endl;
  std::cout << "Total Income: $" << calcWage() << std::endl;
  std::cout << "==========================================" << std::endl;
}
