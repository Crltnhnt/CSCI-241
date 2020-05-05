/********************************************************************
// Program:	ProviderDB.cpp
// Programmer:	Carlton Hunt
// TA:		Bhavana Mallineni
// Section:	3
// Date Due:	09/27/2017

Purpose: The cpp file allows the ProviderDB output to be printed
**********************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "ProviderDB.h"
#include "Provider.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ios;

//*******Default constructor****
// no parameters
// no return type
//******************************
ProviderDB::ProviderDB()
{
}

//************Alternate Constructor****
// one parameter: pointer to a const char*
// no return type
//**************************************
ProviderDB::ProviderDB(const char* filename)
{
   ifstream inFile;

   inFile.open(filename, ios::binary);

   if (!inFile)
   {
       cerr << "Could not open file" << endl;
       exit(1);
   }

   inFile.read((char *) this, sizeof(ProviderDB));

   inFile.close();
}

//**********print method************
// no parameters
//*********************************
void ProviderDB::print()const
{
   for (int i = 0; i < NumOfProviders; i++)
   {
      PArray[i].print();
   }
}

//***********ProviderNumber method******
// no parameters
// return the provider number data member
//***************************************
void ProviderDB::sortByProviderNumber()
{
   int i, j;
   Provider bucket;

   for (i = 1; i < NumOfProviders; i++)
   {
      bucket = PArray[i];

      for (j = i; (j > 0) && (strcmp(PArray[j-1].getProviderNumber(), bucket.getProviderNumber()) > 0); j--)
         PArray[j] = PArray[j-1];

      PArray[j] = bucket;
   }
}

//***********ProviderSpecialty method**********
// no parameters
// returns the specialty data member
//*******************************************
void ProviderDB::sortBySpecialty()
{
   int i,j;
   Provider bucket;

   for (i =1; i < NumOfProviders; i++)
   {
      bucket = PArray[i];

      for (j =i; (j > 0) && (strcmp(PArray[j-1].getProviderSpecialty(), bucket.getProviderSpecialty()) < 0); j--)
         PArray[j] = PArray[j-1];

      PArray[j] = bucket;
   }
}

//******************ProviderName method******
// no parameters
// returns the name data member
//*******************************************
void ProviderDB::sortByName()
{
   int i,j;
   Provider bucket;

   for (i = 1; i < NumOfProviders; i++)
   {
      bucket = PArray[i];

      for (j = i; (j > 0) && (strcmp(PArray[j-1].getProviderName(), bucket.getProviderName()) > 0); j--)
         PArray[j]= PArray[j-1];

      PArray[j] = bucket;
   }
}
