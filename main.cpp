//Lainey Schrag //

#include <iostream>
#include "AddressBook.hpp"

int main()
{
    AddressBook<std::string> myAddressBook;
    myAddressBook.addEntries("Bruce", "Wayne", "x@y.com");
    myAddressBook.addEntries("Barry", "Allen", "p@q.com");
    myAddressBook.addEntries("Clark", "Kent", "r@g.com");
    myAddressBook.addEntries("MJ", "Parker", "a@t.com");
    myAddressBook.addEntries("Wally", "West", "c@o.com");
    myAddressBook.addEntries("Peter", "Parker", "s@m.com");

    std::cout << std::endl << "Number of entries in the address book: " << myAddressBook.numEntries();
    myAddressBook.displayBook();

    std::cout << std::endl << "Searching for Hanks...";

    myAddressBook.searchLast("Hanks");

    myAddressBook.removeEntry("Barry", "Allen", "p@q.com");
    myAddressBook.removeEntry("Peter", "Parker", "s@m.com");
    myAddressBook.updateEntry("Wally", "West", "c@o.com", "Wally", "Barker");

    std::cout << std::endl << "Number of entries in the address book: " << myAddressBook.numEntries();
    
    myAddressBook.displayBook();
    myAddressBook.clearBook();

    std::cout << "Is the book empty?: ";

    std::cout << myAddressBook.isEmpty();

    return(0);
}