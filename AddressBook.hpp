//Lainey Schrag //

#include <iostream>
#include "Node.hpp"

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

template<typename ItemType>
class AddressBook 
{

public:
    AddressBook();
    ~AddressBook();
    bool isEmpty(); //checks if list is empty
    int numEntries(); //returns number of entries
    bool sortAlpha(std::string left, std::string right, int i); //helper function to determine which entry comes first
    void addEntries(std::string firstName, std::string lastName, std::string emailAddress); 
    void removeEntry(std::string firstName, std::string lastName, std::string emailAddress);
    void searchLast(std::string lastName);
    void updateEntry(std::string oldFirstName, std::string oldLastName, std::string emailAddress, std::string newFirstName, std::string newLastName);
    void displayBook();
    void clearBook();

private:
    int itemCount;
    Node <ItemType>* m_front;
};

template<typename ItemType>
AddressBook<ItemType>::AddressBook()
{
    itemCount = 0;
    m_front = nullptr; //initializes to nullptr since list is empty
}

template<typename ItemType>
AddressBook<ItemType>::~AddressBook()
{
    clearBook();
}

template<typename ItemType>
bool AddressBook<ItemType>::isEmpty()
{
    if (m_front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
int AddressBook<ItemType>::numEntries()
{
    return itemCount;
}

template<typename ItemType>
bool AddressBook<ItemType>::sortAlpha(std::string left, std::string right, int i)
{
    if (right.length() < i || left.length() < i) // returns true if function runs out of characters to compare
    {
        return true;
    }
    else 
    {
        if (left[i] < right[i]) // returns true if right name comes after left name
        {
            return true;
        }
        if (left[i] > right[i]) // returns false if right name comes before left name
        {
            return false;
        }
        else // tries with next char in string if previous letters were equal
        {
            sortAlpha(left, right, i+1);
        }
    }
    
}

template<typename ItemType>
void AddressBook<ItemType>::addEntries(std::string firstName, std::string lastName, std::string emailAddress)
{
   std::string num = "0";
   if (itemCount == 0) // adds to front if list is empty
   {
        m_front = new Node<ItemType>(firstName, lastName, emailAddress);
        m_front -> setEntryNumber("1");
        itemCount++;
   } 
   else // adds to anywhere else in list
   {
       int i = 1;
       Node<ItemType>* current = m_front;
       Node<ItemType>* temp = new Node<ItemType>(firstName, lastName, emailAddress);
       while (sortAlpha (current -> getLastName(), lastName, 0) == false && current -> getNext() != nullptr) // determines where in list to add
       {
           current = current -> getNext();
           i++;
       }
       num = std::to_string(i);
       current -> setEntryNumber(num);
       temp -> setNext(current -> getNext());
       current -> setNext(temp);
       itemCount++;
   }
}

template<typename ItemType> 
void AddressBook<ItemType>::removeEntry(std::string firstName, std::string lastName, std::string emailAddress)
{
    Node<ItemType>* current = m_front; 
    Node<ItemType>* jumper = m_front;
    while (current -> getEmailAddress() != emailAddress && current -> getNext() != nullptr) // search using email since no two emails will be the same
    {
        jumper = jumper -> getNext();
        current = current -> getNext();
        
        current -> setNext(jumper -> getNext());
    }
    delete jumper;
    itemCount--;
}

template<typename ItemType>
void AddressBook<ItemType>::searchLast(std::string lastName)
{
    Node<ItemType>* current = m_front;
    int i = 1;
    bool find = false;
    while (current -> getLastName() != lastName && current -> getNext() != nullptr)
    {
        if (current -> getLastName() == lastName)
        {
            std::cout << std::endl << current -> getEntryNumber() << ": " << current -> getFirstName() << " " << current -> getLastName() << ", " << current -> getEmailAddress();
            bool find = true;
        }
        current = current -> getNext();
    }

    if (find == false) // only displays if no match was found
    {
        std::cout << std::endl << "No one with last name " << lastName << " found.";
    }
}

template<typename ItemType>
void AddressBook<ItemType>::updateEntry(std::string oldFirstName, std::string oldLastName, std::string emailAddress, std::string newFirstName, std::string newLastName)
{
    Node<ItemType>* current = m_front; 
    while (current -> getEmailAddress() != emailAddress && current -> getNext() != nullptr) // search using email since no two emails will be the same
    {
        current = current -> getNext();
    }
    current -> setFirstName(newFirstName);
    current -> setLastName(newLastName);
}

template<typename ItemType>
void AddressBook<ItemType>::displayBook()
{
    Node<ItemType>* current = m_front;
    for (int i = 0; i < itemCount; i++) // displays all entries
    {
        std::cout << std::endl << current -> getEntryNumber() << ": " << current -> getFirstName() << " " << current -> getLastName() << ", " << current -> getEmailAddress();
        current = current -> getNext();
    }
}

template<typename ItemType>
void AddressBook<ItemType>::clearBook() //deletes all entries in list
{
    Node<ItemType>* current = m_front; 
    for (int i = 0; i < itemCount; i++)
    {
        if (current -> getNext() != nullptr)
        {
            delete current;
            current = current -> getNext();
        }
    }
    delete current;
}

#endif