main: main.o payroll.o payroll_list.o
		g++ -o main main.o payroll.o payroll_list.o -std=c++11

main.o: main.cpp payroll.cpp payroll_list.cpp payroll.h payroll_list.h
		g++ -c main.cpp payroll.cpp payroll_list.cpp -std=c++11

payroll.o: payroll.cpp payroll.h
		g++ -c payroll.cpp -std=c++11

payroll_list.o: payroll_list.cpp payroll_list.h
		g++ -c payroll_list.cpp -std=c++11
		
