#include <iostream>
#include <conio.h>
class MyArray {
    friend std::ostream& operator<<(std::ostream&, const MyArray&);
    public:
        MyArray(int n=10);
        void kurang_satu();
        void cetak_array();
    private:
        int n;
        int A[10];
};
std::ostream& operator<<(std::ostream& output, const MyArray& Mine) {
    for (int i=0; i<Mine.n; i++){
        output << "Nilai indeks ke-[" << i << "] adalah " << Mine.A[i] << std::endl;
    }
    getch();
    return output;
}

MyArray::MyArray(int ukuran) {
    n = ukuran;
    for (int i=0; i<n; i++){
        A[i] = i+1;
    }
}

void MyArray::kurang_satu() {
    for (int i=0; i<n; i++){
        A[i]--;
    }
}

void MyArray::cetak_array() {
    for (int i=0; i<n; i++){
        std::cout << "Nilai indeks ke-[" << i << "] adalah " << A[i] << std::endl;
    }
    getch();
}
int main() {
    MyArray X;
    std::cout << "Nilai array asal : " << std::endl;
    X.cetak_array();
    std::cout << "\nPakai operator overloading :\n";
    std::cout << X;
    X.kurang_satu();
    std::cout << "Setelah dikurangi 1 menjadi : " << std::endl;
    X.cetak_array();
    return 0;
}