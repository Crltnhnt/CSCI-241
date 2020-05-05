/********************************************************************
// PROGRAM:	assign2.cpp
// PROGRAMMER:	Carlton Hunt
// TA:		Bhavana MAllineni
// Section:	3
// DUE DATE:	09/27/2017
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
// call methods for the ProviderDB object and use print method to print the output//
// use the alternate constructor to pass the "providerdb"//
    cout << "#####################################################################\n" << endl;
	cout <<	"#################| Unsorted Print of all providers |#################\n" << endl;
	cout << "#####################################################################\n" << endl; << endl;
	
   ProviderDB loadData("providerdb");
   loadData.print();

    cout << "#####################################################################\n" << endl;
	cout <<	"###################| Sorted By Provider's Number |###################\n" << endl;
	cout << "#####################################################################\n" << endl; << endl;
	
	loadData.sortByProviderNumber();
	loadData.print();
	

    cout << "#####################################################################\n" << endl;
	cout <<	"######################| Sorted By Specialty |########################\n" << endl;
	cout << "#####################################################################\n" << endl; << endl;
   loadData.sortBySpecialty();
   loadData.print();



    cout << "#####################################################################\n" << endl;
	cout <<	"##########################| Sorted By Name |#########################\n" << endl;
	cout << "#####################################################################\n" << endl; << endl;
   loadData.sortByName();
   loadData.print();

}
