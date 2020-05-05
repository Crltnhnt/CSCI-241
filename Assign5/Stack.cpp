/*************************************************************************
FILE:           Stack.cpp
AUTHOR:         Carlton Hunt
DUE DATE:       October 31st, 2017

PURPOSE:	This assignment is an exercise implementing the stack
		ADT using a dynamically-allocated array, as well as 
		techniques for managing dynamically-allocated storage in
		C++..

**************************************************************************/

#include "Stack.h"

/*******************************************************************
Stack Constructor

Use: Sets stack_size and stack_capacity = 0
     and stack array pointer to nullptr

Paramaters: No parameters

Returns: Nothing
********************************************************************/
Stack::Stack()
{
   stack_size = 0;
   stack_capacity = 0;
   stack_array = nullptr;
}

/**********************************************************************
Stack Destructor

Use: Makes it possible to delete a stack object to save memory.

Paramaters: No parameters

Returns: nothing
***********************************************************************/
Stack::~Stack()
{
   delete[] stack_array;
}


/*********************************************************************
Copy Constructor

Use: Copies stacxk object, prepared for possibility of an empty
     Stack object

Parameters:  Reference to a const stack object

Returns: No returns
**********************************************************************/
Stack::Stack(const Stack& other)
{
   stack_capacity = other.stack_capacity;
   stack_size = other.stack_size;

   if (stack_capacity == 0)
      stack_array = nullptr;
   else
      stack_array = new int[stack_capacity];


    for (size_t i = 0; i < stack_size; i++)
       stack_array[i] = other.stack_array[i];
}

/************************************************************************
Assignment Operator

Use: Sets other object to this instance of stack copying values

Parameters: Reference const Stack

Returns: *this; 
*************************************************************************/
Stack& Stack::operator=(const Stack& other)
{
   if (this != &other)
   {
      delete[] stack_array;

      stack_capacity = other.stack_capacity;
      stack_size = other.stack_size;

      if (stack_capacity == 0)
         stack_array = nullptr;
      else
         stack_array = new int[stack_capacity];

      for (size_t i = 0; i < stack_size; i++)
         stack_array[i] = other.stack_array[i];
   }
   return *this;
}


/**************************************************************************
Output Operator

Use: when overloaded, a Stack canbe printed on standard output

Parameters: ostream &lhs, const Stack& rhs

Return: lhs

***************************************************************************/
ostream& operator<<(ostream& lhs, const Stack& rhs)
{
   for (size_t i = 0; i < rhs.stack_size; i++)
      lhs << rhs.stack_array[i] << " ";

   return lhs;
}

/****************************************************************************
Clear Method

Use: Sets the Stack objects size to zero.

Parameters: none

Returns:Nothing
*****************************************************************************/
void Stack::clear()
{
   stack_size = 0;
}


/****************************************************************************
Size Method

Use: grabs stack_size

Parameters: None

Returns: stack_size;

*****************************************************************************/
size_t Stack::size() const
{
   return stack_size;
}


/****************************************************************************
Capacity Method

Use: returns stack_capacity

Paramters:none

Returns: stack_capacity;
*****************************************************************************/
size_t Stack::capacity() const
{
    return stack_capacity;
}


/****************************************************************************
Empty Method

Use: Notifies the user if stack_size is empty.

Parameters: none

Returns: bool; true/false

****************************************************************************/
bool Stack::empty() const
{
  if(stack_size == 0)
    return true;
  else
    return false;
}


/**************************************************************************
Top Method

Use: returns top of Stack

Parameter: None

Returns: topof stack_array
****************************************************************************/
int Stack::top() const
{
   return stack_array[stack_size - 1];
}

/****************************************************************************
Push Method

Use: Pushes new value into Stack
Parameters: int val
Returns: none

*****************************************************************************/
void Stack::push(int val)
{
   if (stack_size == stack_capacity)
   {
      if (stack_capacity == 0)
         reserve(1);
      else
         reserve(stack_capacity * 2);
   }

   stack_array[stack_size] = val;

  ++stack_size;
}


/****************************************************************************
Pop Method

Use: decrease stack_size by 1, removes top element
No parameters
No Returns

******************************************************************************/
void Stack::pop()
{
  --stack_size;
}

/*****************************************************************************
Reserve Method

Use: Increases stack_array
Parameters: size_t n
No returns

*****************************************************************************/
void Stack::reserve(size_t n)
{
   if (n < stack_size || n == stack_capacity)
      return;

   int* tArray = new int[n];

   for (size_t i = 0; i < stack_size; i++)
      tArray[i] = stack_array[i];

   stack_capacity = n;
   stack_array = tArray;
   delete[] stack_array;
}

/***************************************************************************
Subscript Operator Overloader

use: returns element of stack_array at n
Parameters: size_t n
Returns: The item of the stack_array


***************************************************************************/
int Stack::operator[](size_t n) const
{
   return stack_array[n];
}

/***************************************************************************
No const Subscript Operator Overloader
Parameters: Reference to a const stack object
Returns: The item of the stack_array 

****************************************************************************/
int& Stack::operator[](size_t n)
{
   return stack_array[n];
}

/***************************************************************************
Comparison Operator Overloading

Parameters: a const reference to a Stack object
Returns: Either true or false

****************************************************************************/
bool Stack::operator==(const Stack& rhs) const
{
   if(this->stack_size == rhs.stack_size)
   {
      for (size_t i = 0; i < stack_size; i++)
      {
         if (this->stack_array[i] != rhs.stack_array[i])
            return false;
      }
   }
   else
       return false;


   return true;
}
