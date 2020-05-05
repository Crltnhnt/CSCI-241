/***************************************************************************
CSCI 241 - Assignment 7 - Fall 2017

Programmer: 	Carlton Hunt
Section:    	3
TA: 		Bhavana Mallineni
Date Due:	11/17/2017

Purpose: This program creates and implements a class to represent the Stack
	ADT using a singly-linked list.

****************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
#include <ostream>

using namespace std;

template <class T>
class Node;

template <class T>
struct Node
{
    public:

        Node(const T& = T(),Node<T>* = nullptr);

        Node<T>* next;
        T data;
};

/***************************************************************
*********************Node Constructor***************************
 Use: Intializes the data members of the stack Node
***************************************************************/
template <class T>
Node<T>::Node(const T& newData,Node<T>* newNext)
{
    next = newNext;
    data = newData;
}

template <class T>
class Stack;

template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T>
class Stack
{
    friend ostream& operator<< <>(ostream& , const Stack<T>&);

    public:
        Stack();
        ~Stack();

        size_t size() const;
        bool empty() const;
        const T& top() const;

        Stack(const Stack<T>& other);
        Stack<T>& operator=(const Stack<T>& other);

        void push(const T&);
        void pop();
        void copyList(const Stack<T>& other);
        void clear();

    private:
        Node<T>* stkTop = nullptr;
        size_t stkSize;
};

/***************************************************************
***********************Stack Constructor************************
 Use: Intializes the object and sets stkTop & stkSize
***************************************************************/
template <class T>
Stack<T>::Stack()
{
    stkSize = 0;
    stkTop = nullptr;
}

/***************************************************************
***********************Empty Method****************************
 Use: checks if stack is empty (True/False)
***************************************************************/
template <class T>
bool Stack<T>::empty() const
{
    if (stkSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
*************************Stack Destructor***********************
 Use: Deletes stack object
***************************************************************/
template <class T>
Stack<T>::~Stack()
{
    clear();
}

/***************************************************************
***********************Clear Method*****************************
 Use: Clears stack
***************************************************************/
template <class T>
void Stack<T>::clear()
{
    while ( stkSize > 0)
    {
        pop();
    }
}

/***************************************************************
***********************Size Method******************************
 Use: Returns stack size
***************************************************************/
template <class T>
size_t Stack<T>::size() const
{
    return stkSize;
}

/***************************************************************
************************Push method*****************************
 Use: inserts the item at the top of the stack
***************************************************************/
template <class T>
void Stack<T>::push(const T& item)
{

    Node<T>* newNode = new Node<T>(item, stkTop);
    stkTop = newNode;
    stkSize++;
}

/***************************************************************
**************************Pop method****************************
 Use: Removes the node at the top of the stack.
***************************************************************/
template <class T>
void Stack<T>::pop()
{

    if (stkSize == 0)
    {
       throw underflow_error("The stack is empty.");
    }
    Node<T>* DNode = stkTop;
    stkTop = stkTop->next;
    delete DNode;
    stkSize--;
}

/***************************************************************
******************************Top method************************
 Use: Returns the stkTop to the top node in stack.
***************************************************************/
template <class T>
const T& Stack<T>::top() const
{
    if (stkSize == 0)
    {
       throw underflow_error("Stack is empty.");
    }

   return stkTop->data;
}

/***************************************************************
************************Copy Constructor***********************
 Use: Copies one stack into another stack.
***************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    stkTop = nullptr;
    copyList(other);
    stkSize = other.stkSize;
}
/***************************************************************
*******************Stack Assignment Operator********************
 Use: Sets one Stack equal to another stack.
***************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
       copyList(other);
       clear();
       stkSize = other.stkSize;
    }
    return *this;
}

/***************************************************************
*************************Output operator************************
 Use: Makes the entire stack object to be sent to the standard
      output.
***************************************************************/
template <class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
    Node<T>* bin;

    for (bin = rhs.stkTop; bin != nullptr; bin = bin->next)
    {
       lhs << bin->data << ' ';
    }
    return lhs;
}
/***************************************************************
***********************Copylist method**************************
 Use: Makes a copy of the linked list
***************************************************************/
template <class T>
void Stack<T>::copyList(const Stack<T>& other)
{
    Node<T>* ptr, * newNode, * last = nullptr;
    for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
    {
        newNode = new Node<T>(ptr->data);
        if (last == nullptr)
        {
            stkTop = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;
    }
}


#endif
