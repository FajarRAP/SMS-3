#include<iostream>

class Bilangan{
    friend std::ostream &operator<<(std::ostream &, const Bilangan &);
    friend std::istream &operator>>(std::istream &, Bilangan &);
    public:
        Bilangan(int a = 0, float b = 0.0){
            this->a = a;
            this->b = b;
        }
        void banding_int(const Bilangan &, const Bilangan &);
        Bilangan &operator=(const Bilangan &);
        Bilangan operator+(const Bilangan &) const;
        Bilangan operator-() const;
    private:
        int a;
        float b;
};

std::ostream &operator<<(std::ostream & out, const Bilangan &x){
    out << "Bagian integer : " << x.a << std::endl;
    out << "Bagian float   : " << x.b << std::endl;
    return out;
}

void Bilangan::banding_int(const Bilangan &x, const Bilangan &y){
    if(x.a > y.a){
        printf("%d::x lebih besar dari %d::y\n", x.a, y.a);
    }else{
        printf("%d::x lebih kecil dari %d::y\n", x.a, y.a);
    }
}

Bilangan &Bilangan::operator=(const Bilangan &x){
    a = x.a;
    b = x.b;
    return *this;
}

std::istream &operator>>(std::istream &in, Bilangan &x){
    std::cout<<"\nMasukkan bagian integer : ";
    in>>x.a;
    std::cout<<"Masukkan bagian float     : ";
    in>>x.b;
    return in;
}

Bilangan Bilangan::operator+(const Bilangan &x) const{
    Bilangan cc;
    cc.a = a + x.a;
    cc.b = b + x.b;
    return cc;
}

Bilangan Bilangan::operator-() const{
    Bilangan x;
    x.a = -a;
    x.b = -b;
    return x;
}

int main(){
    Bilangan s, t(-2, 3.14), d;
    std::cout << "Nilai awal s\n" << s;
    std::cout << "\nNilai awal t dari deklarasi\n" << t;
    s = t;
    std::cout << "\nSetelah s di-assign t\n";
    std::cout << "Nilai s\n" << s;
    std::cout << "\nMasukkan nilai-nilai objek d";
    std::cin >> d;
    std::cout << "\nSetelah d + t\n" << d + t;
    std::cout << "\nNilai dinegatifkan\n" << -d;
    return 0;
}