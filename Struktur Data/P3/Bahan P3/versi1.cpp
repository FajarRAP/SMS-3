#include <iostream>
#include <conio.h>

int main() {
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    std::cout << "Nilai array asal : " << std::endl;
    for (int i=0; i<n; i++){
        printf("Nilai indeks ke-[%d] adalah %d\n", i, A[i]);
    }
    std::cout<<std::endl;
    getch();

    std::cout << "Setelah dikurangi 1 menjadi : " << std::endl;
    for (int i=0; i<n; i++){
        printf("Nilai indeks ke-[%d] adalah %d\n", i, A[i]-1);
    }
    std::cout<<std::endl;
    getch();

    std::cout << "Nilai array dicetak kembali" << std::endl;
    for (int i=0; i<n; i++){
        printf("Nilai indeks ke-[%d] adalah %d\n", i, A[i]);
    }
    std::cout << "Ternyata tidak berubah. Perhatikan perbedaannya " << std::endl;
    std::cout<<std::endl;
    getch();

    for (int i=0; i<n; i++){
        printf("Nilai indeks ke-[%d] adalah %d\n", i, A[i]--);
    }
    std::cout<<std::endl;

    std::cout << "Nilai array dicetak kembali" << std::endl;
    for (int i=0; i<n; i++){
    std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i] << std::endl;
    }
    getch();
    return 0;
}