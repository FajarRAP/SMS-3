// output a chain using a chain iterator

#include <iostream>
#include "chain.h"
#include "citer.h"

int main()
{
   int *x;
   Chain<int> X;
   ChainIterator<int> c;
   X.Insert(0,6);
   X.Insert(0,5);
   X.Insert(0,4);
   X.Insert(0,3);
   X.Insert(0,2);
   X.Insert(0,1);
   cout << "List is ";
   x = c.Initialize(X);
   while (x) {
      cout << *x << ' ';
      x = c.Next();
      }
   cout << endl;
}
