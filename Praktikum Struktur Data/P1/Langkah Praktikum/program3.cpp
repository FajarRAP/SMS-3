#include <iostream>

void cari(int x, int n){
    if(n == 0){
        std::cout << "Bilangan tidak ditemukan" << std::endl;
    }else if(x == n){
        std::cout << "Bilangan ditemukan pada perulangan ke-" << n << std::endl;
    }else{
        cari(x, n-1);
    }
}

int main(){
    cari(14, 20);
    system("PAUSE");
    return EXIT_SUCCESS;
    return 0;
}