main: main.o payroll.o 
	g++ -o main main.o payroll.o -std=c++11 

main.o: main.cpp mystack.h payroll.cpp payroll.h
	g++ -c main.cpp payroll.cpp -std=c++11

payroll.o: payroll.cpp payroll.h
	g++ -c payroll.cpp -std=c++11

clean:
	rm *.o