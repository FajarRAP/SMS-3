#include<iostream>

float pangkat(float x, int n){
    if(n == 0 ){
        return 1;
    }
    if(n == 1){
        return x;
    }
    if(n%2 == 1){
        std::cout << "Masuk bagian ganjil" << std::endl;
        return pangkat(x, n-1) * x;
    }else{
        std::cout << "Masuk bagian genap" << std::endl;
        return pangkat(x*x, n/2);
    }
}

int main(){
    std::cout<<pangkat(2, 5)<<std::endl;
    std::cout<<pangkat(2, 6)<<std::endl;
    return 0;
}