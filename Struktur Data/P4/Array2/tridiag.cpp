// test tridiagonal matrix class

#include <iostream>
#include "tridiag.h"

int main()
{
   TridiagonalMatrix<int> X(20);
   X.Store(22,1,1).Store(44,5,5).Store(0,8,5).Store(55,7,8);
   std::cout << X.Retrieve(7,8) << std::endl;
   std::cout << X.Retrieve(5,5) << std::endl;
   std::cout << X.Retrieve(1,1) << std::endl;
   std::cout << X.Retrieve(10,1) << std::endl;
   std::cout << X.Retrieve(1,5) << std::endl;
}
