main: main.o payroll.o payrollstack.o payroll_list.o
		g++ -o main main.o payroll.o payrollstack.o payroll_list.o -std=c++11

main.o: main.cpp payroll.cpp payroll.h payrollstack.cpp payrollstack.h payroll_list.cpp payroll_list.h
		g++ -c main.cpp payroll.cpp payrollstack.cpp payroll_list.cpp -std=c++11

payroll.o: payroll.cpp payroll.h
		g++ -c payroll.cpp -std=c++11

payrolllist.o: payroll_list.cpp payroll_list.h
		g++ -c payroll_list.cpp -std=c++11

payrollstack.o: payrollstack.cpp payrollstack.h
		g++ -c payrollstack.cpp -std=c++1

clean:
		rn *.o main