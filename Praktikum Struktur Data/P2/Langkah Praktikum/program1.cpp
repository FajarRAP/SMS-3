#include<iostream>
#define maks 5

class Array1D{
    friend std::ostream &operator<<(std::ostream &, const Array1D &);
    friend std::istream &operator>>(std::istream &, Array1D &);
    public:
        Array1D();
        void cetak();
        void geser_kiri();
        void geser_kanan();
    private:
        char A[maks];
};

Array1D::Array1D(){
    for(int a = 0; a < maks ; a++){
        this->A[a] = '0';
    }
}

void Array1D::geser_kiri(){
    int temp = this->A[0];
    for(int a = 0; a < maks; a++){
        this->A[a] = this->A[a+1];
    }
    this->A[maks-1] = temp;
}

void Array1D::geser_kanan(){
    int temp = this->A[maks-1];
    for(int a = maks-1; a >= 0; a--){
        this->A[a] = this->A[a-1];
    }
    this->A[0] = temp;
}

std::ostream &operator<<(std::ostream &out, const Array1D &x){
    for(int a = 0; a < maks; a++){
        std::cout<<x.A[a]<<" ";
    }
    std::cout<<std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Array1D &x){
    int posisi;
    char isi;
    std::cout<<"Isi array posisi ke : ";
    in>>posisi;
    if(posisi-1 < 0 || posisi-1 >= 5){
        std::cout<<"Di luar kendali"<<std::endl;
        exit(1);
    }
    std::cout<<"Karakter : ";
    in>>isi;
    x.A[posisi-1] = isi;
    return in;
}

int main(){
    Array1D array1;
    std::cout<<"Array masih kosong : "<<array1;
    std::cin>>array1;
    std::cout<<"Isi array sekarang : "<<array1;
    array1.geser_kanan();
    std::cout<<"Setelah geser kanan : "<<array1;
    return 0;
}