#ifndef PROVIDER_H
#define PROVIDER_H

/**************************************************************************
// FILE:	Provider.h
// AUTHOR:	Carlton Hunt
// TA:		Bhavana Mallineni
// Section:	3
// DUE DATE:	09/27/2017

// PURPOSE:	Declaration for the provider class, which represents
		information about a health care provider.
***************************************************************************/

class Provider
{
   private:
      char number[7] = {};
      char specialty[41] = {};
      char name[41] = {};
      char address1[41] = {};
      char address2[31] = {};
      char city[21] = {};
      char state[3] = {};
      char zcode[6] = {};
      char pnumber[15] = {};

   public:
      Provider();		//default constructor

      void print() const;	//print provider

//*********Accessor methods********
      const char* getProviderNumber()
 	{ return number; }
      const char* getProviderName() 
	{ return name; }
      const char* getProviderSpecialty() 
	{ return specialty; }
};
#endif
