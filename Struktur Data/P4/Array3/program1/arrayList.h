// array implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
// USES STL ALGORITHMS TO SIMPLIFY CODE

#ifndef arrayList_
#define arrayList_

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include <iterator>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

template<class T>
class arrayList : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
      arrayList(int initialCapacity = 10);
      arrayList(const arrayList<T>&);
//      arrayList(int intialCapacity=10, int theAmount=arrayLength);
      ~arrayList() {delete [] element;}
      
      //copy assignment
      

      // ADT methods
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;
      // additional method
      int capacity() const {return arrayLength;}

      //assignment
      void push_back(const T& theElement);
      void pop_back();
      void swap(arrayList<T>& theList);
            
      // operator overloading
      T& operator[](int theIndex);
      const T& operator[](int theIndex) const;
	  arrayList<T>& operator=(const arrayList<T>& theList);
	  bool operator==(const arrayList<T>& theList);
	  bool operator!=(const arrayList<T>& theList);
	  
   protected:
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      T* element;            // 1D array to hold list elements
      int arrayLength;       // capacity of the 1D array
      int listSize;          // number of elements in list
//      int increaseAmount;    // the amount to increase when resize is needed
};

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1)
   {ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }
   arrayLength = initialCapacity;
   element = new T[arrayLength];
   listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{// Copy constructor.
   arrayLength = theList.arrayLength;
   listSize = theList.listSize;
   element = new T[arrayLength];
   copy(theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search for theElement
   int theIndex = (int) (find(element, element + listSize, theElement)
                         - element);

   // check if theElement was found
   if (theIndex == listSize)
     // not found
     return -1;
   else return theIndex;
 }

template<class T>
void arrayList<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // valid index, shift elements with higher index
   copy(element + theIndex + 1, element + listSize,
                                element + theIndex);

   element[--listSize].~T(); // invoke destructor
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   // valid index, make sure we have space
   if (listSize == arrayLength)
      {// no space, double capacity
//         changeLength1D(element, arrayLength, 2 * arrayLength);
//         arrayLength *= 2;
         changeLength1D(element, arrayLength, arrayLength*2);
         arrayLength *= 2;

      }

   // shift elements right one position
   copy_backward(element + theIndex, element + listSize,
                 element + listSize + 1);

   element[theIndex] = theElement;

   listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
	x.output(out); return out;
}

// overload []
template<class T>
T& arrayList<T>::operator[](int theIndex)
{
	checkIndex(theIndex);
	return element[theIndex];	
}



   
//assignment push_back 11, 12, 13

template<class T>
void arrayList<T>::push_back(const T& theElement)
{
}

template<class T>
void arrayList<T>::pop_back()
{
}

template<class T>
void arrayList<T>::swap(arrayList<T>& theList)
{
	std::swap(*this, theList);
}

template<class T>
arrayList<T>& arrayList<T>::operator=(const arrayList<T>& theList)
{
	if(theList.element != element)
	{
		delete [] element;
		element = new T[theList.arrayLength];
		arrayLength = theList.arrayLength;
		listSize = theList.listSize;
		copy(theList.element, theList.element+listSize, element);
	}
	return (*this);

}

//bonus

template<class T>
bool arrayList<T>::operator==(const arrayList<T>& theList)
{
}

template<class T>
bool arrayList<T>::operator!=(const arrayList<T>& theList)
{
	return !((*this) == theList); 
}

#endif
