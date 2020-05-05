#ifndef STACK_H
#define STACK_H

/*************************************************************************
FILE:		Stack.h
AUTHOR:		Carlton Hunt
DUE DATE:	October 31st, 2017

PURPOSE: Declarations for the Stack Class

**************************************************************************/

#include <iostream>
#include <ostream>

using namespace std;

class Stack

/**********************Friend Functions****************************/
{ friend ostream& operator<<(ostream& lhs, const Stack& rhs);

private:
/*******************Data members***********************************/
  int* stack_array;
  size_t stack_capacity;
  size_t stack_size;
  int stackTopSubscript = stack_size -1;

public:
/*********************Methods***************************************/
  Stack();
  ~Stack();
  
  Stack(const Stack& other);
  
  Stack& operator=(const Stack& other);
  
  size_t size() const;
  size_t capacity() const;
  
  bool empty() const;
  int top() const;
  void clear();
  void push(int val);
  void pop();
  void reserve(size_t n);
  
  int operator[](size_t n) const;
  int& operator[](size_t n);
  bool operator==(const Stack& rhs) const;
};
#endif
