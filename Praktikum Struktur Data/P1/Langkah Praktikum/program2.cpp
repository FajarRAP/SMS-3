#include<iostream>

void tampil(int n){
    if(n > 0){
        std::cout<<"Pemanggilan ke : " << n << std::endl;
        tampil(n-1);
    }
}

int main(){
    int n = 3;
    tampil(n);
    system("PAUSE");
    return EXIT_SUCCESS;
    return 0;
}