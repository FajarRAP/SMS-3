#include <iostream>
#include <conio.h>
// coba pakai const

void kurang_satu(int A[], int n) {
    for (int i=0; i<n; i++)
    A[i]--;
}

void cetak_array(int A[], int n) {
    for (int i=0; i<n; i++)
    std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i] << std::endl;
    getch();
}

int main() {
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    std::cout << "Nilai array asal : " << std::endl;
    cetak_array(A, n);
    kurang_satu(A, n);
    std::cout << "Setelah dikurangi 1 menjadi : " << std::endl;
    cetak_array(A, n);
    return 0;
}