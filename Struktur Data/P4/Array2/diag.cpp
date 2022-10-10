// test diagonal matrix class

#include <iostream>
#include "diag.h"

int main()
{
   DiagonalMatrix<int> X(20);
   X.Store(22,1,1).Store(44,5,5).Store(0,8,5);
   std::cout << X.Retrieve(5,5) << std::endl;
   std::cout << X.Retrieve(1,1) << std::endl;
   std::cout << X.Retrieve(10,1) << std::endl;
}
