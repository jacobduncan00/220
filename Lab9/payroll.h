#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>

class PayRoll{ //class in which we use to calculate wages and print employee information

public:

  PayRoll(); //default constructor
  PayRoll(std::string, double, double); //constructor that takes in data
  void setHours(double); //setter function
  void setName(std::string); //setter function
  void setPay(double); //setter function
  std::string getName(); //getter function
  double getPay(); //getter function
  double getHours(); //getter function
  double calcWage(); //only function that returns data
  void printInfo(); //prints info
  friend std::ostream& operator<<(std::ostream &out, PayRoll&);

private:

  std::string name; //name of each employee
  double pay; //pay rate of each employee
  double hours; //hours worked by each employee

};

#endif
