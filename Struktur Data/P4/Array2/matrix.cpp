// test matrix class

#include <iostream>
#include "matrix.h"

int main()
{
   try {
      Matrix<int> X(3,2), Y, Z;
      int i, j;
      for (i = 1; i <= 3; i++)
         for (j = 1; j <= 2; j++)
            X(i,j) = 2*i + j;
      std::cout << "X(3,1) = " << X(3,1) << std::endl;
      std::cout << "X is" << std::endl;;
      std::cout << X << std::endl;
      Y = X;
      std::cout << "Y is" << std::endl;
      std::cout << Y << std::endl;
      X += 2;
      std::cout << "X incremented by 2 is" << std::endl;
      std::cout << X << std::endl;
      Z = Y + X;
      std::cout << "Y + X is" << std::endl;
      std::cout << Z << std::endl;
      std::cout << "-(Y + X) is" << std::endl;
      std::cout << -Z << std::endl;
      Matrix<int> W(2,3);
      for (i = 1; i <= 2; i++)
         for (j = 1; j <= 3; j++)
            W(i,j) = i + j;
      std::cout << "W is" << std::endl;
      std::cout << W << std::endl;
      Z = Y * W;
      std::cout << "Y * W is" << std::endl;
      std::cout << Z << std::endl;
      }
   catch (...) {
      std::cerr << "An exception has occurred" << std::endl;}
}
