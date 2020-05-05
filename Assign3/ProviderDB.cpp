/********************************************************************
// Program:	ProviderDB.cpp
// Programmer:	Carlton Hunt & Josh dyra
// LOGON ID:	z1772974 & z1798711
// TA:		Bhavana Mallineni
// Section:	3
// Date Due:	10/10/2017

Purpose: The cpp file allows the ProviderDB output to be printed
**********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ProviderDB.h"
#include "Provider.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ios;
using std::ws;
using std::string;

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

   for (i = 1; i < NumOfProviders; i++)
   {
      bucket = PArray[i];

      for (j = i; (j > 0) && (strcmp(PArray[j-1].getProviderSpecialty(), bucket.getProviderSpecialty()) < 0); j--)
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


//***********processTransactions method****
// Takes one parameter: a pointer to a constant char
//no returns
//*****************************************
void ProviderDB::processTransactions(const char* transactionFile)
{ string transactionType;
  string specialty;
  string number;

  ifstream tranFile;
  tranFile.open(transactionFile);
  
  if (!tranFile)
  {
    cerr << "Can not open file." << endl;
    exit(1);
  }

  while (tranFile >> transactionType)
  {
    if (transactionType == "all")
    {
	cout << "------All Providers------" << endl;

	sortByName();
	print();
    }
    else if (transactionType == "specialty")
    {
	cout << "---Specialty Providers---" << endl;

	tranFile >> ws;
	getline(tranFile, specialty);

	sortBySpecialty();

	int counter = 0;

	for (int i = 0; i < NumOfProviders; i++)
	{
	  if (PArray[i].getProviderSpecialty() == specialty)
	  {
	    PArray[i].print();
	    counter++;
          }
	}
    }
    else if (transactionType == "number")
    {
	tranFile >> ws;
	tranFile >> number;

	sortByProviderNumber();
	int mid = searchForProviderNumber(number.c_str());

	cout << "-----Phone Providers-----" << endl;

	if (searchForProviderNumber(number.c_str()) == -1)
	{
	  cout << "Number does not exist." << endl;
	}
	else
	{
	  PArray[mid].print();
	}
    }
  }
  tranFile.close();
}

//*********searchForProviderNumber*********
//parameter: a character array with the provider number
//returns an integer(-1)
//*****************************************
int ProviderDB::searchForProviderNumber(const char* number)
{
  int low = 0;
  int mid;
  int high = NumOfProviders -1;

  while (low <= high)
    { mid = (low + high) / 2;

      if (strcmp(PArray[mid].getProviderNumber(), number) == 0)
      { return mid; }
      else if (strcmp(PArray[mid].getProviderNumber(), number) > 0)
      { high = mid - 1; }
      else
      { low = mid + 1; }
    }
  return -1;
}
