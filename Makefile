Project5: main.o
	g++ -g -std=c++11 -Wall main.o -o Project5

main.o: main.cpp AddressBook.hpp Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean: 
	rm *.o Project5