all: run

run: driver.o
	g++ -std=c++11 -o run driver.o

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp

clean:
	rm *.gch
	rm *.o
