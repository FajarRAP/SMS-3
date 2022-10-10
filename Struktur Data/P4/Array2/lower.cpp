// test lower triangular matrix class

#include <iostream>
#include "lower.h"

int main()
{
   LowerMatrix<int> X(20);
   X.Store(22,1,1).Store(44,5,3).Store(55,10,2).Store(0,8,5);
   std::cout << X.Retrieve(10,2) << std::endl;
   std::cout << X.Retrieve(5,3) << std::endl;
   std::cout << X.Retrieve(1,1) << std::endl;
   std::cout << X.Retrieve(10,14) << std::endl;
   std::cout << X.Retrieve(8,5) << std::endl;
}
