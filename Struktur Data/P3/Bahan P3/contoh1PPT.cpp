#include<iostream>

int faktorial(int n){
    if(n <= 1){
        return 1;
    }else{
        return n*faktorial(n-1);
    }
}

int faktorial(int n){
    int hasil = 1;
    for(int a = 1; a <= n; a++){
        hasil *= a;
    }
    return hasil;
}

int main(){
    std::cout<<faktorial(6)<<std::endl;
    return 0;
}