//Code by Jacob Duncan
//Salisbury University
//COSC-220 Joseph Anderson

/*
	This program is an object oriented program that simulates a payroll
	with 7 employees however, when finished there will be 14 total objects
	You will enter the hours for the employees worked and their name and payrate 
	are both hardcoded per instructions. 
*/

#include <iostream> //cin, cout
#include "payroll.h" //includes class definition in order to make PayRoll objects

int main (){

	std::string empName;
	double payRate;
	double hr;
	const int employees = 7; //hardcoded 7 objects based off instructions

	PayRoll p1 ("Bob", 14.35);
	PayRoll p2 ("Jack", 18);
	PayRoll p3 ("Bill", 12.25);
	PayRoll p4 ("Kim", 8.50);
	PayRoll p5 ("Tommy", 10);
	PayRoll p6 ("Jacob", 20);
	PayRoll p7 ("Ryan", 22);

	PayRoll p[employees] = {p1,p2,p3,p4,p5,p6,p7}; //array of PayRoll objects
	PayRoll *ptr = new PayRoll[employees]; //array of pointers of PayRoll objects, used to create 7 new objects dynamically

	for (int i = 0; i < 7; i++){ //for loop that initizializes new dyamic memory to create 7 new objects
		ptr[i].setName(p[i].getName());
		ptr[i].setPay(p[i].getPay());
	}

	//for loop that asks for the hours worked by each employees
	for (int i = 0; i < 7; i++){
		std::cout << "Enter the hours worked by Employee #" << (i+1) << ": ";
		std::cin >> hr;
			while ((hr > 60) || (hr <= 0)){ //input validation to not allow hours under or equal to zero or over sixty
				std::cout << "Please input a valid amount of hours: ";
				std::cin >> hr;
			}
		std::cout << "=========================================" << std::endl;
		p[i].setHours(hr); //calls the set hour function to set hours of each PayRoll object
	}

	for (int i = 0; i < 7; i++){
		p[i].printInfo(); //calls the printinfo function to print information of each PayRoll object
	}

	//for loop that does the same function as the for loop above however assigns to pointer array instead
	for (int i = 0; i < 7; i++){
		std::cout << "Enter the hours worked by Employee #" << (i+8) << ": ";
		std::cin >> hr;
			while ((hr > 60) || (hr <= 0)){
				std::cout << "Please input a valid amount of hours: ";
				std::cin >> hr;
			}
		std::cout << "=========================================" << std::endl;
		ptr[i].setHours(hr);
	}

	for (int i = 0; i < 7; i++){
		ptr[i].printInfo(); //calls the printinfo function to print information from the array of pointers
	}


	std::cout << "=============================" << std::endl;
	std::cout << "Size of arrays:             " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "Size of array of objects: " << sizeof(p) << std::endl;
	std::cout << "Size of array of pointer: " << sizeof(ptr) << std::endl;

	/*
	The array of objects has a size of 336 where as the  array of pointers has a size of 56
	This makes sense due to the fact that pointers are much smaller than the actual
	object because all they do is point to the objects

	The size of the array of pointers is 8 and there are 8 bits in a byte so if we multiply
	8 by 7 we get 56. Therefore there are 8 pointers each 1 byte in size

	The size of the array of objects is 336 and there are 8 bits in a byte and from the
	addresses we can see that each object is 3 bytes apart so if we do 8 x 3 we get 24 and
	24 x 14 gives us 336 which is the amount of bytes in our array of objects.
	*/


	//prints the addresses of each of PayRoll objects
	std::cout << "=============================" << std::endl;
	std::cout << "Addresses of objects:        " << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << &p1 << std::endl; //140732562273264 <-- Decimal Values from Hexidecimal in Terminal
	std::cout << &p2 << std::endl; //140732562273232
	std::cout << &p3 << std::endl; //140732562273200
	std::cout << &p4 << std::endl; //140732562273168
	std::cout << &p5 << std::endl; //140732562273136
	std::cout << &p6 << std::endl; //140732562273104
	std::cout << &p7 << std::endl; //140732562273072
	//prints the addresses of each of the pointers of PayRoll objects
	std::cout << "=================================" << std::endl;
	std::cout << "Addresses of pointers to objects:" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << &ptr[1] << std::endl; //140732562272840 <-- Decimal Values from Hexidecimal in Terminal
	std::cout << &ptr[2] << std::endl; //140732562272848
	std::cout << &ptr[3] << std::endl; //140732562272856
	std::cout << &ptr[4] << std::endl; //140732562272864
	std::cout << &ptr[5] << std::endl; //140732562272872
	std::cout << &ptr[6] << std::endl; //140732562272880
	std::cout << &ptr[7] << std::endl; //140732562272888

	delete [] ptr;

	/*
	After viewing the addresses of the objects that are created in both the
	array of objects and the array of pointers and converting them to decimals.

	In the array of objects I was able to see that each object was 32 bits apart meaning
	that they are all 4 bytes apart. This means that each of PayRoll object takes
	up 4 bytes of memory in the stack.

	In the array of pointers I was able to see that each pointer was exactly 8 bits apart
	meaning that they are each 1 byte away which would be correct
	*/

	return 0;
}
