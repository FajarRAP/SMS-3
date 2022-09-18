#include<iostream>

template<class T>
auto Abc(T a, T b, T c){
   return a + b + b * c + (a + b - c) / (a + b) + 4;
}

int main(){
   std::cout << Abc(2, 3, 4) << std::endl;
}

