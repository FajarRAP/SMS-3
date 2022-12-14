
// test 1D array class

#include <iostream>
#include "array1d.h"
using namespace std;
int main()
{
   try {
      Array1D X(10), Y, Z;
      for (int i=0; i < 10; i++)
         X[i] = i;
      cout << "X[3] = " << X[3] << endl;
      cout << "X is " << X << endl;
      Y = X;
      cout << "Y is " << Y << endl;
      X += 2;
      cout << "X incremented by 2 is " << X << endl;
      Z = (Y + X) * Y;
      cout << "(Y + X) * Y is " << Z << endl;
      cout << "-(Y + X) * Y is " << -Z << endl;
      }
   catch (...) {
      cerr << "An exception has occurred" << endl;}
}

