// simulated pointer dual available space lists

#include <iostream>
#include "dsimul.h"
using namespace std;
int main()
{
   int x;
   SimSpace<int> L(5);
   x = L.Allocate();
   cout << "Node allocated is " << x << endl;
   int y = L.Allocate();
   cout << "Node allocated is " << y << endl;
   L.Deallocate(x);
   y = L.Allocate();
   cout << "Node allocated is " << y << endl;
}
