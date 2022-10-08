#include <iostream>
#include <conio.h>

void cetak_array(int A[], int n, int kurang) {
    for (int i=0; i<n; i++)
    std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i]-kurang << std::endl;
    getch();
}
int main() {
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    std::cout << "Nilai array asal : ";
    cetak_array(A, n, 0);
    std::cout << "Setelah dikurangi 1 menjadi : " << std::endl;
    cetak_array(A, n, 1);
    std::cout << "Nilai array dicetak kembali" << std::endl;
    cetak_array(A, n, 0);
    std::cout << "Ternyata tidak berubah. Perhatikan perbedaannya " << std::endl;
    for (int i=0; i<n; i++){
        std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i]-- << std::endl;
    }
    std::cout << "Nilai array dicetak kembali" << std::endl;
    cetak_array(A, n, 0);
    return 0;
}