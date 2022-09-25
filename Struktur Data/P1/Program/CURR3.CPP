// test currency class
#include <iostream>
#include "CURR3.h"

int main(){
   Currency g, h(plus, 3, 50), i, j;
   g.Set(minus, 2, 25);
   i.Set(-6.45);
   j = h + g;
   std::cout << j << std::endl;
   i += h;
   std::cout << i << std::endl;
   j = i + g + h;
   std::cout << j << std::endl;
   j = (i+=g) + h;
   std::cout << j << std::endl;
   std::cout << i << std::endl;
   return 0;
}
