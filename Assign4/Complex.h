#ifndef COMPLEX_H
#define COMPLEX_H

/****************************************************************************
CSCI 241 - Assignment 4 - Fall 2017

Programmer:	Carlton Hunt & Joshua Dyra
Z-ID:		z1772974 & z1798711
Section:	3
TA:		Bhavanna Mallieneni
Date Due:	October 19th, 2017

Purpose: Class for Complex

****************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


class Complex
{
   friend ostream& operator<<(ostream&, const Complex&);
   friend istream& operator>>(istream&, Complex&);

   private:

      //Data members
      double realPart, imaginaryPart;

   public:
      //method prototypes

      //Complex Constructor

       Complex();
       Complex(double, double);

       //setAccess methods
       void setComplex(double, double);
       void setRealPart(double);
       void setImaginaryPart(double);

       //getAccess methods
       void getComplex(double&, double&) const;
       double getRealPart() const;
       double getImaginaryPart() const;

       // overloaded operators
       Complex operator+(const Complex&) const;
       Complex operator*(const Complex&) const;
       bool  operator==(const Complex&) const;

};

#endif
