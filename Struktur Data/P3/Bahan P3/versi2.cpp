#include <iostream>
#include <conio.h>

void cetak_array(int A[], int n) {
    for (int i=0; i<n; i++)
    printf("Nilai indeks ke-[%d] adalah %d\n", i, A[i]);
    getch();
}

int main() {
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    std::cout << "Nilai array asal : ";
    cetak_array(A, n);

    std::cout << "Setelah dikurangi 1 menjadi : " << std::endl;
    for (int i=0; i<n; i++){
        std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i]-1 << std::endl;
    }
    getch();

    std::cout << "Nilai array dicetak kembali" << std::endl;
    cetak_array(A, n);

    std::cout << "Ternyata tidak berubah. Perhatikan perbedaannya " << std::endl;
    for (int i=0; i<n; i++){
        std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i]-- << std::endl;
    }
    std::cout << "Nilai array dicetak kembali" << std::endl;
    cetak_array(A, n);
    return 0;
}