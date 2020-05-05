/***********************************************************
Program:	Provider.cpp
Programmer:	Carlton Hunt
TA:		Bhavana Mallineni
Section:	3
Date Due:	10/10/2017

Purpose: The cpp file allows the output to be printed.
****************************************************************/

#include <iostream>
#include "Provider.h"

using std::cout;
using std::endl;

//***********Default Provider Constructor***************
Provider::Provider()
{
}

//***********Print method deinition**********
void Provider::print() const
{
//************Code for Print method******
   cout << "#" << number << endl;
   cout << name << endl;
   cout << specialty << endl;
   cout << address1 << endl;
   cout << address2 << endl;
   cout << city << "," << state << " " << zcode << endl;
   cout << pnumber << endl;
   cout << "\n";
}
