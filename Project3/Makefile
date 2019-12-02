all: run

run: driver.o payroll.o
	g++ -std=c++11 -o run driver.o payroll.o

driver.o: driver.cpp sulist.cpp sulist.h suqueue.cpp suqueue.h sustack.cpp sustack.h payroll.cpp payroll.h
	g++ -std=c++11 -c driver.cpp

sulist.o: sustack.h sustack.cpp
	g++ -std=c++11 -c sustack.h sustack.cpp

payroll.o: payroll.cpp 
	g++ -std=c++11 -c payroll.cpp 

sustack.o: sustack.h sustack.cpp
	g++ -std=c++11 -c sustack.h sustack.cpp

suqueue.o: suqueue.h suqueue.cpp
	g++ -std=c++11 -c suqueue.h suqueue.cpp

clean:
	rm *.o
