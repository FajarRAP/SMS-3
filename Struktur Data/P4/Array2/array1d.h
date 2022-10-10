
#ifndef Array1D_
#define Array1D_

// One-dimensional arrays.

#include <iostream>
// #include "xcept.h"
using namespace std;
class Array1D {
   friend ostream& operator << (ostream&, const Array1D&);
   public:
      Array1D(int size = 0);
      Array1D(const Array1D &v); // copy constructor
      ~Array1D() {delete [] element;}
      int& operator[](int i) const;
      int Size() {return size;}
      Array1D  &operator=(const Array1D &v);
      Array1D  operator+() const; // unary +
      Array1D  operator+(const Array1D & v) const;
      Array1D  operator-() const; // unary minus
      Array1D  operator-(const Array1D & v) const;
      Array1D  operator*(const Array1D & v) const;
      Array1D & operator+=(const int& x);
      Array1D & ReSize(int sz);
   private:
       int size;
       int *element; // 1D array
};  

// template<class T>
Array1D::Array1D(int size)
{// Constructor for one-dimensional arrays.
   // if (sz < 0) throw BadInitializers();
   size = size;
   element = new int[size];
}

// template<class T>
Array1D::Array1D(const Array1D &v)
{// Copy constructor for one-dimensional arrays.
   size = v.size;
   element = new int[size];  // get space
   for (int i = 0; i < size; i++) // copy elements
      element[i] = v.element[i];
}

// template<class T>
int& Array1D ::operator[](int i) const
{// Return reference to element i.
   //if (i < 0 || i >= size) throw OutOfBounds();
   return element[i];
}

// template<class T>
Array1D & Array1D ::operator=(const Array1D & v)
{// Overload assignment operator.
   if (this != &v) {// not self-assignment
      size = v.size;
      delete [] element; // free old space
      element = new int[size]; // get right amount
      for (int i = 0; i < size; i++) // copy elements
         element[i] = v.element[i];
      }
   return *this;
}

// template<class T>
Array1D  Array1D :: operator+(const Array1D & v) const
{// Return w = (*this) + v.
   //if (size != v.size) throw SizeMismatch();

   // create result array w
   Array1D  w(size);
   for (int i = 0; i < size; i++)
       w.element[i] = element[i] + v.element[i];

   return w;
}

// template<class T>
Array1D  Array1D :: operator-(const Array1D & v) const
{// Return w = (*this) - v.
   //if (size != v.size) throw SizeMismatch();

   // create result array w
   Array1D  w(size);
   for (int i = 0; i < size; i++)
       w.element[i] = element[i] - v.element[i];

   return w;
}

// template<class T>
Array1D  Array1D ::operator-() const
{// Return w = -(*this).
   // create result array w
   Array1D  w(size);
   for (int i = 0; i < size; i++)
       w.element[i] = -element[i];

   return w;
}

// template<class T>
Array1D  Array1D ::operator*(const Array1D & v) const
{// Return w = (*this) * v. Pairwise multiply.
   //if (size != v.size) throw SizeMismatch();

   // create result array w
   Array1D  w(size);
   for (int i = 0; i < size; i++)
       w.element[i] = element[i] * v.element[i];

   return w;
}

// template<class T>
Array1D & Array1D ::operator+=(const int& x)
{// Add x to each element of (*this).
   for (int i = 0; i < size; i++)
       element[i] += x;
   return *this;
   }

// template<class T>
ostream& operator<<(ostream& out, const Array1D & x)
{// Put the elements of x into the stream out.
   for (int i = 0; i < x.size; i++)
      out << x.element[i] << "  ";
   return out;
}

// template<class T>
Array1D & Array1D ::ReSize(int sz)
{// Change the size to sz.
 // Do not copy array elements to new space.
   //if (sz < 0) throw BadInitializers();
   delete [] element;
   size = sz;
   element = new int [size];
   return *this;
}

#endif

