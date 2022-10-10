
#ifndef Node_
#define Node_

template <class T> class Chain;

class Node {
   friend void BinSort(Chain<Node>&, int);
   // friend main();
   public:
      int score;
      operator int() const {return score;}
   private:
      char *name;
};

#endif
