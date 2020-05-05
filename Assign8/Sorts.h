/***************************************************************************
   PROGRAM:    Sorts.h
   PROGRAMMER: Carlton Hunt
   DUE DATE:   11/29/2017

   FUNCTION:   This header file sorts the lists using the sort algorithms.
***************************************************************************/
#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Sorts
{
    private:
    public:

        void buildList(vector<T>& set, const char* fileName);
        void printList(const vector<T>& set, int itemWidth, int numPerLine);

        bool lessThan(const T& item1, const T& item2);
        bool greaterThan(const T& item1, const T& item2);

};

/****************************************************************************
This function reads the items from an input file and puts them into a vector
*****************************************************************************/
template <class T>
   void buildList(vector<T>& set, const char* fileName)
   {
       T item;
       ifstream inFile;

       inFile.open(fileName);
       if (!inFile)
       {
           cerr << "Unable to open input file." << endl;
           exit(1);
       }

       inFile >> item;

       while (inFile)
       {
           set.push_back(item);

           inFile >> item;
       }

       inFile.close();
   }

/***************************************************************
This function prints the list of items from the vector.
***************************************************************/
template <class T>
   void printList(const vector<T>& set, int itemWidth, int numPerLine)
   {
       int i = 0;
       while (i < (int) set.size())
       {
           cout << setw(itemWidth) << set[i] << ' ';
           i++;
           if (i % numPerLine == 0)
           {
              cout << endl;
           }
       }

       if (i % numPerLine != 0)
       {
           cout << endl;
       }
   }

/********************************************************************
This function compares two items to see if item1 is less than item2
*********************************************************************/
template <class T>
   bool lessThan(const T& item1, const T& item2)
   {
       if (item1 < item2)
       {
           return true;
       }
       else
       {
           return false;
       }
   }

/************************************************************************
This function compares two items to see if one is greater than the other
*************************************************************************/
template <class T>
   bool greaterThan(const T& item1, const T& item2)
   {
       if (item1 > item2)
       {
           return true;
       }
       else
       {
           return false;
       }
   }

#endif
