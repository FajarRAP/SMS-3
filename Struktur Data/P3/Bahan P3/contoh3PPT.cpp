#include<iostream>
#include<iomanip>

int pascal(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }else{
        return pascal(n-1, k-1) + pascal(n-1, k);
    }
}

int main(){
    for(int a = 0; a < 10; a++){
        for(int c = 10; c > a; c--){
            std::cout<<"  ";
        }
        for(int b = 0; b <= a; b++){
            std::cout<<std::setw(4)<<pascal(a, b);
        }
        std::cout<<std::endl;
    }
    return 0;
}