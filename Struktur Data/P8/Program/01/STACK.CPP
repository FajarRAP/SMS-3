// test formula based stack class

#include <iostream>
#include "stack.h"

int main()
{
   int x;
   Stack<int> S(3);
   try
   {
      S.Add(1);
      std::cout << S.getData() << " Pushed" << std::endl;
      S.Add(2);
      std::cout << S.getData() << " Pushed" << std::endl;
      S.Add(3);
      std::cout << S.getData() << " Pushed" << std::endl;
      S.Add(4);
      std::cout << S.getData() << " Pushed" << std::endl;
   }
   catch (NoMem)
   {
      std::cout << "Stack Overflow" << std::endl;
   }
   std::cout << "Stack sekarang : " << std::endl;
   S.print();
   std::cout << "Stack puncak   :  " << S.Top() << std::endl;
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
      std::cout << "Stack Underflow" << std::endl;
   }
   return 0;
}
