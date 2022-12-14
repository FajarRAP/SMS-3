#ifndef Currency_
#define Currency_

#include <iostream>
#include <stdlib.h>

enum sign {plus, minus};

class Currency {
   public:
      // constructor
      Currency(sign s = plus, unsigned long d = 0, unsigned int c = 0);
      // destructor
      ~Currency() {
         std::cout<<std::endl<<"Dihancurkan"<<std::endl;
      }
      bool Set(sign s, unsigned long d, unsigned int c);
      bool Set(float a);
      sign Sign() const{
         return (amount < 0)? minus : plus;
         // if (amount < 0) {
         //    return minus;
         // }else {
         //    return plus;
         // }
      }
      unsigned long Dollars() const{
         return (amount < 0)? (-amount)/100 : amount/100;
         // if (amount < 0) {
         //    return (-amount) / 100;
         // }
         // else {
         //    return amount / 100;
         // }
      }
      unsigned int Cents() const{
         return (amount < 0)? (-amount) - Dollars() * 100 : amount - Dollars() * 100;
         // if (amount < 0) {
         //    return -amount - Dollars() * 100;
         // }else {
         //    return amount - Dollars() * 100;
         // }
      }
      Currency Add(const Currency& x) const;
      Currency &Increment(const Currency& x){
         amount += x.amount; 
         return *this;
         }
      void Output() const;
   private:
      long amount;
};

Currency::Currency(sign s, unsigned long d, unsigned int c){
   // Create a Currency object.
   if (c > 99) {
      // too many cents
      std::cerr << "Cents should be < 100" << std::endl;
      exit(1);
   }
   amount = d * 100 + c;
   if (s == minus) {
      amount = -amount;
   }
}

bool Currency::Set(sign s, unsigned long d, unsigned int c){
   // Reset value.
   if (c > 99) {
      return false;
   }
   
   amount = d * 100 + c;
   if (s == minus) {
      amount = -amount;
   }
   return true;
}
   
bool Currency::Set(float a){
   // Reset value.
   sign sgn;
   if (a < 0) {
      sgn = minus; 
      a = -a;
   }
   else {
      sgn = plus;
   }
   amount = (a + 0.001) * 100;
   if (sgn == minus) {
      amount = -amount;
   }
   return true;
}

Currency Currency::Add(const Currency& x) const{
   // Add x and *this.
   Currency y;
   y.amount = amount + x.amount;
   return y;
}

void Currency::Output() const{
   // Output currency value.
   long a = amount;
   if (a < 0) {
      std::cout << '-';
      a = -a;
   }
   long d = a / 100; // dollars
   std::cout << '$' << d << '.';
   int c = a - d * 100; // cents
   if (c < 10) {
      std::cout << "0";
   }
   std::cout << c;
}

#endif

