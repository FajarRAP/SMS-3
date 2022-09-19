#ifndef Currency_
#define Currency_

#include <iostream>
#include <stdlib.h>

enum sign {plus, minus};

class Currency{
   public:
      // constructor
      Currency(sign tanda = plus, unsigned long dolar = 0, unsigned int sen = 0);
      // destructor
      ~Currency(){}
      bool Set(sign tanda, unsigned long dolar, unsigned int sen);
      bool Set(float duitNya);
      unsigned long Dollars() const {return dolar;}
      unsigned int Cents() const {return sen;}
      sign Sign() const {return tanda;}
      Currency Add(const Currency& x) const;
      Currency& Increment(const Currency& x);
      void Output() const;
      void cetak(){
         std::cout<<this->tanda<<" "<<this->dolar<<" "<<this->sen<<std::endl;
      }
   private:
      sign tanda;
      unsigned long dolar;
      unsigned int sen;
};

Currency::Currency(sign tanda, unsigned long dolar, unsigned int sen){
   // Create duitNya Currency object.
   if (sen > 99){// too many sen
      std::cerr << "Cents should be < 100" << std::endl;
      exit(1);
   }
   this->tanda = tanda; 
   this->dolar = dolar; 
   this->sen = sen;
}

bool Currency::Set(sign tanda, unsigned long dolar, unsigned int sen){
   // Reset value.
   if (sen > 99){
      return false;
   }
   this->tanda = tanda; 
   this->dolar = dolar; 
   this->sen = sen;
   return true;
}
   
bool Currency::Set(float duitNya){
   // Reset value.
   if (duitNya < 0){
      this->tanda = minus; 
      duitNya = -duitNya;
   }
   else {
      this->tanda = plus;
   }
   this->dolar = duitNya; // extract integer part
   // get two decimal digits
   this->sen = (duitNya + 0.001 - dolar) * 100;
   return true;
}

Currency Currency::Add(const Currency& x) const{
   // Add x and *this.
   long removeCommaDollar[2], hasilTambah;
   Currency objectTemp;
   // convert invoking object to signed integers
   removeCommaDollar[0] = dolar * 100 + sen;
   if (tanda == minus) {
      removeCommaDollar[0] = -removeCommaDollar[0];
   }
   // convert x to signed integer
   removeCommaDollar[1] = x.dolar * 100 + x.sen;
   if (x.tanda == minus) {
      removeCommaDollar[1] = -removeCommaDollar[1];
   }
   hasilTambah = removeCommaDollar[0] + removeCommaDollar[1];
   
   // convert to currency representation
   if (hasilTambah < 0) {
      objectTemp.tanda = minus; 
      hasilTambah = -hasilTambah;
   }
   else {
      objectTemp.tanda = plus;
   }
   objectTemp.dolar = hasilTambah / 100;
   objectTemp.sen = hasilTambah - objectTemp.dolar * 100;
   
   return objectTemp;
}

Currency& Currency::Increment(const Currency& x){
   // Increment by x.
   *this = Add(x);
   return *this;
}

void Currency::Output() const{// Output currency value.
   if (tanda == minus) {
      std::cout << '-';
   }
   std::cout << '$' << dolar << '.';
   if (sen < 10) {
      std::cout << "0";
      std::cout << sen << std::endl;
   }else{
      std::cout << sen << std::endl;
   }
}

#endif