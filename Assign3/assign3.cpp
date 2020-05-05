/********************************************************************
// PROGRAM:	assign2.cpp
// PROGRAMMER:	Carlton Hunt
// TA:		Bhavana MAllineni
// Section:	3
// DUE DATE:	10/10/2017
//
// PURPOSE: this cpp file includes all  header files and prints the 
	    output in the respective format in one place.

*********************************************************************/

#include <iostream>
#include "Provider.h"
#include "ProviderDB.h"
using std::cout;
using std::endl;

int main()
{
//************************************************************
// Calls the object from ProviderDB with data in transaction text
//**************************************************************
  ProviderDB loadData("providerdb");

  loadData.processTransactions("transactions.txt");

  return 0;
}
