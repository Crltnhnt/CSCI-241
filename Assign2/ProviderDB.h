#ifndef PROVIDERDB_H
#define PROVIDERDB_H

/***********************************************************************
// File:	ProviderDB.h
// Author:	Carlton Hunt
// TA:		Bhavana Mallineni
// Section:	3
// Due Date:	09/27/2017

//  Purpose: Declaration for the ProviderDB class,
************************************************************************/

#include "Provider.h"

class ProviderDB
{
   private:
      Provider PArray[40];
      int NumOfProviders;

   public:
      ProviderDB();		//default constructor

      ProviderDB(const char* filename);		//alternate constructor

      void print() const;			//print method

//**********sorting methods***********
      void sortByProviderNumber();

      void sortBySpecialty();

      void sortByName();

};

#endif
