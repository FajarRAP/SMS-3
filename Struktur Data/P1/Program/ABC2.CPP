
#include<iostream>

float Abc(float a, float b, float c){
   return a + b + b * c + (a + b - c) / (a + b) + 4;
}

int main(){
   std::cout << Abc(2, 3, 4) << std::endl;
   return 0;
}

