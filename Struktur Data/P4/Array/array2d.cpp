// test 2D array class

#include <iostream>
#include "array2d.h"

int main()
{
   try {
      int i, j;
      Array2D<int> X(3,2), Y, Z;
      for (i = 0; i < 3; i++)
         for (j = 0; j < 2; j++)
            X[i][j] = 2*i + j;
      std::cout << "X[2][1] = " << X[2][1] << std::endl;
      std::cout << "X is" << std::endl;
      std::cout << X << std::endl;
      Y = X;
      std::cout << "Y is" << std::endl;
      std::cout << Y << std::endl;
      X += 2;
      std::cin >> i;
      std::cout << "X incremented by 2 is" << std::endl;
      std::cout << X << std::endl;
      Z = Y + X;
      std::cout << "Y + X is" << std::endl;
      std::cout << Z << std::endl;
      std::cout << "-(Y + X) is" << std::endl;
      std::cout << -Z << std::endl;
      Array2D<int> W(2,3);
      for (i = 0; i < 2; i++)
         for (j = 0; j < 3; j++)
            W[i][j] = i + j;
      std::cout << "W is" << std::endl;
      std::cout << W << std::endl;
      Z = Y * W;
      std::cout << "Y * W is" << std::endl;
      std::cout << Z << std::endl;
      }
   catch (...) {
      std::cerr << "An exception has occurred" << std::endl;}
}
