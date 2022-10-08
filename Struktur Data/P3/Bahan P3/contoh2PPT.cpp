#include<iostream>

int fibo(int n){
    if(n <= 1){
        return 1;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}

int fibo(int n){
    int n1 = 1, n2 = 1;
    if(n <= 1){
        return 1;
    }else{
        int hasil = 0;
        for(int i = 2; i <= n; i++){
            hasil = n1+n2;
            n1 = n2;
            n2 = hasil;
        }
        return hasil;
    }
}

int main(){
    for(int a = 0; a < 10; a++){
        std::cout<<fibo(a)<<" ";
    }
    return 0;
}