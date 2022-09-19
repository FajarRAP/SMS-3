// test currency class
#include <iostream>
#include "CURR1.h"

int main(){
   Currency g, h(plus, 3, 50), i, j;
   g.Set(minus, 2, 24);
   i.Set(-6.45);
   j = h.Add(g);
   // j = h.Increment(g);
   j.Output(); 
   std::cout << std::endl;

   i.Increment(h);
   i.Output();
   std::cout << std::endl;

   j = i.Add(g).Add(h);   
   j.Output();
   std::cout << std::endl;

   j = i.Increment(g).Add(h);
   j.Output();
   std::cout << std::endl;

   i.Output();
   std::cout << std::endl;
   return 0;
}
