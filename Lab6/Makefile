main: main.o sort.o
	g++ -o main main.o sort.o -std=c++11
	
main.o: main.cpp sort.cpp sort.h
	g++ -c main.cpp sort.cpp -std=c++11

sort.o: sort.cpp sort.h
	g++ -c sort.cpp -std=c++11
clean:
	rm *.o main
