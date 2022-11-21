// test linked stack class

#include <iostream>
#include "lstack.h"

int main()
{
   int x;
   LinkedStack<int> S;
   try
   {
      S.Add(1).Add(2).Add(3).Add(4);
   }
   catch (NoMem)
   {
      std::cout << "Could not complete additions" << std::endl;
   }
   std::cout << "Stack should be 1234" << std::endl;
   std::cout << "Stack top is " << S.Top() << std::endl;
   try
   {
      S.Delete(x);
      std::cout << "Deleted " << x << std::endl;
      S.Delete(x);
      std::cout << "Deleted " << x << std::endl;
      S.Delete(x);
      std::cout << "Deleted " << x << std::endl;
      S.Delete(x);
      std::cout << "Deleted " << x << std::endl;
   }
   catch (OutOfBounds)
   {
      std::cout << "Last delete failed " << std::endl;
   }
}
