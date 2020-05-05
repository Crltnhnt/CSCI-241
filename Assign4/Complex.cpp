/*****************************************************************
CSCI 241 - Assignment 4 - Fall 2017

Programmer:	Carlton Hunt & Joshua Dyra
Z-ID:		z1772974 & z1798711
Section:	3
TA:		Bhavanna Mallineni
Date Due:	October 19th, 2017

Purpose: This .cpp file has the implementations of the class methods.
*********************************************************************/

#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

Complex::Complex()
{
  realPart = 0;
  imaginaryPart = 0;
}

/*************************************************************************
Function: Complex::Complex(double, double)

Arguments: The constructor takes two double variables as args,
	representing the real & imaginary parts of a complex ##.

Returns: nothing

Notes: The two parameters default value is 0 in prototype for the constructor
*************************************************************************/
Complex::Complex(double newRealPart, double newImaginaryPart)
{
  setRealPart(newRealPart);
  setImaginaryPart(newImaginaryPart);
}

/*************************************************************************
Function: Complex::setComplex(double, double)

Arguments: This set Method takes two double variables as args,
	representing real & imaginary parts of complex number.

Returns: nothing

Notes: assigns method parameters to the data members.
*************************************************************************/
void Complex::setComplex(double newRealPart, double newImaginaryPart)
{
  realPart = newRealPart;
  imaginaryPart = newImaginaryPart;
}

/*************************************************************************
Function: Complex::getComplex(double &, double &)

Arguments: This method takes two references to double vars as args,
	representing real & imaginary parts of complex number.

Returns: nothing

Notes: Assigns method parameters to data members.
*************************************************************************/
void Complex::getComplex(double& newRealPart, double& newImaginaryPart) const
{
  newRealPart = realPart;
  newImaginaryPart = imaginaryPart;

}

/*************************************************************************
Function: Complex::setRealPart(double)

Arguments: The constructor takes one double variable representing
	real part of complex number.

Returns: nothing

Notes: assigns method parameter to real part data member of the object
*************************************************************************/
void Complex::setRealPart(double newRealPart)
{
  realPart = newRealPart;
}

/*************************************************************************
Function: Complex::getRealPart() const

Arguments: Method does not change data members of the object, declared const

Returns: A double, the real part of complex number

Notes: Data member returned representing real part of complex #.
*************************************************************************/
double Complex::getRealPart() const
{
  return realPart;
}

/*************************************************************************
Function: Complex::setImaginaryPart(double)

Arguments: A double

Returns: nothing

Notes: Assigns method parameter to imaginary part data member of object.
*************************************************************************/
void Complex::setImaginaryPart(double newImaginaryPart)
{
  imaginaryPart = newImaginaryPart;
}

/*************************************************************************
Function: Complex::getImaginaryPart() const

Arguments: Method does not change any data members of object, const

Returns:  imaginary part of complex number, double

Notes: return data member representing imaginaryPart of complex number
*************************************************************************/
double Complex::getImaginaryPart() const
{
   return imaginaryPart;
}

/*************************************************************************
Function: operator+

Use: For addition of two complex objects together by adding real
	data members together and imaginary data members together.

Arguments: Complex c

Returns: Complex object with addition results.
*************************************************************************/
Complex Complex::operator+(const Complex& rhs) const
{
  Complex temp;
  temp.realPart = realPart + rhs.realPart;
  temp.imaginaryPart = imaginaryPart + rhs.imaginaryPart;

  return temp;
}

/*************************************************************************
Function: operator*

Use: For multiplication of two complex objects together by multiplying real
	data members together and imaginary data members together.

Arguments: Complex comp

Returns: Complex object with multiplication results.
*************************************************************************/
Complex Complex::operator*(const Complex& comp) const
{
   return Complex(this->realPart * comp.realPart - this->imaginaryPart * comp.imaginaryPart,
      this->realPart * comp.imaginaryPart + this->imaginaryPart * comp.realPart);
}

/*************************************************************************
Function: bool Complex::operator==(Complex) const

Use: should return true if real part of lhs = real part of rhs,
	otherwise return false.

Arguments: Complex comp

Returns: a boolean value.
*************************************************************************/
bool Complex::operator==(const Complex& comp) const
{
  if ( this->realPart == comp.realPart && this->imaginaryPart == comp.imaginaryPart )
	return true;
  else
	return false;
}

/*************************************************************************
Function: ostream& operator<<(ostream &,Complex)

Arguments: fctn takes two parameters, first is reference to ostream object,
	lhs of stream insertion expression

Returns: a reference to ostream object

Notes: this function should print complex object as ordered pair
*************************************************************************/
ostream& operator<<(ostream& outStream, const Complex& comp)
{
  outStream << "(" << comp.getRealPart() << ", " << comp.getImaginaryPart() << ")";
  return outStream;
}

/*************************************************************************
Function: istream& operator>>(istream, Complex)

Arguments: fctn takes two parameters, first is reference to istream object,
	lhs of stream insertion expression

Returns: a reference to istream object

Notes: this function should read input by user as ordered pair
*************************************************************************/
istream & operator>>(istream& inStream, Complex& comp)
{
  char ch;
  double temp;

  inStream >> ch;
  inStream >> temp;

  comp.setRealPart(temp);

  inStream >> ch;
  inStream >> temp;

  comp.setImaginaryPart(temp);
  inStream >> ch;

  return inStream;
}
