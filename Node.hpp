//Lainey Schrag //
#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename ItemType>
class Node 
{
    public:
        Node(std::string firstName, std::string lastName, std::string emailAddress);

        void setNext(Node<ItemType>* nextPtr); //sets next node
        Node<ItemType>* getNext(); //gets next node

        void setFirstName(std::string firstName); 
        ItemType getFirstName();
        void setLastName(std::string lastName); 
        ItemType getLastName();
        void setEmailAddress(std::string emailAddress); 
        ItemType getEmailAddress();
        void setEntryNumber(std::string entryNumber); 
        ItemType getEntryNumber();

    private:
        ItemType m_firstName;
        ItemType m_lastName;
        ItemType m_emailAddress;
        ItemType m_entryNumber; 
        Node<ItemType>* next; // pointer to next node   

};

template<typename ItemType>
Node<ItemType>::Node(std::string firstName, std::string lastName, std::string emailAddress) 
{
    m_firstName = firstName;
    m_lastName = lastName;
    m_emailAddress = emailAddress;
}

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextPtr)
{
   next = nextPtr;
}

template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext()
{
   return next;
} 

template<typename ItemType>
void Node<ItemType>::setFirstName(std::string firstName)
{
    m_firstName = firstName;
}

template<typename ItemType>
ItemType Node<ItemType>::getFirstName()
{
    return m_firstName; 
}

template<typename ItemType>
void Node<ItemType>::setLastName(std::string lastName)
{
    m_lastName = lastName;
}

template<typename ItemType>
ItemType Node<ItemType>::getLastName()
{
    return m_lastName;  
}

template<typename ItemType>
void Node<ItemType>::setEmailAddress(std::string emailAddress)
{
    m_emailAddress = emailAddress;
}

template<typename ItemType>   
ItemType Node<ItemType>::getEmailAddress()
{
    return m_emailAddress;
}

template<typename ItemType>
void Node<ItemType>::setEntryNumber(std::string entryNumber)
{
    m_entryNumber = entryNumber;
}

template<typename ItemType>
ItemType Node<ItemType>::getEntryNumber()
{
    return m_entryNumber;
}

#endif 