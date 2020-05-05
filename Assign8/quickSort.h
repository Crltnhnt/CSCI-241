/***************************************************************************
   PROGRAM:    quickSort.h
   PROGRAMMER: Carlton Hunt
   DUE DATE:   11/29/2017

   FUNCTION:   This header file sorts the lists using quicksort algorithms.
****************************************************************************/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <cstring>
using namespace std;

//Definitions

template <class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

/***************************************************************
Calls the recursive quickSort function.
***************************************************************/
template <class T>
   void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
   {
       quickSort(set, 0, set.size()-1, compare);
   }

/***************************************************************
This function performs the  recursive calls to implement quickSort
***************************************************************/
template <class T>
   void quickSort(vector<T> & set, int start, int end, bool (*compare)(const T&, const T&))
   {
       int pivotPoint;

       if (start < end)
       {
           pivotPoint = partition(set, start, end, compare);
           quickSort(set, start, pivotPoint - 1, compare);
           quickSort(set, pivotPoint + 1, end, compare);
       }
   }

/***************************************************************
This function selects the pivot element and partitions the vector
***************************************************************/
template <class T>
   int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
   {
       int pivotIndex, mid;
       T pivotValue;
       T temp;

       mid = (start + end) / 2;

       temp = set[start];
       set[start] = set[mid];
       set[mid] = temp;

       pivotIndex = start;
       pivotValue = set[start];

       for (int scan = start + 1; scan <= end; scan++)
       {
           if (compare(set[scan], pivotValue))
           {
               pivotIndex++;

               temp = set[pivotIndex];
               set[pivotIndex] = set[scan];
               set[scan] = temp;
           }
       }

       temp = set[start];
       set[start] = set[pivotIndex];
       set[pivotIndex] = temp;

       return pivotIndex;
   }

#endif
