// bin sort as member of chain class

#include <iostream>
#include "binnode2.h"
#include "nchain.h"
using namespace std;
int main()
{
   Node x;
   Chain<Node> L;
   for(int i = 1; i <= 20; i++) {
   x.score = i/2;
   L.Insert(0,x); }
   L.BinSort(10);
   cout << L << endl;
}
