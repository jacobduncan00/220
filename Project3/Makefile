all: run

run: driver.o payroll.o
	g++ -std=c++11 -o run driver.o payroll.o

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp

payroll.o: payroll.cpp 
	g++ -std=c++11 -c payroll.cpp 

clean:
	rm *.o
