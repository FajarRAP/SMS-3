#include<iostream>

class Bilangan{
    friend std::ostream &operator<<(std::ostream &, const Bilangan &);
    friend std::istream &operator>>(std::istream &, Bilangan &);
    public:
        Bilangan(int a = 0, float b = 0.0){}
        void banding_int(const Bilangan &, const Bilangan &);
        Bilangan &operator=(const Bilangan &);
        Bilangan operator+(const Bilangan &) const;
        Bilangan operator-() const;
    private:
        int a;
        float b;
};

std::ostream &operator<<(std::ostream &out, const Bilangan &x){
    out<<"Bagian integer : "<<x.a<<std::endl;
    out<<"Bagian float   : "<<x.b<<std::endl;
    return out;
}

void Bilangan::banding_int(const Bilangan &x, const Bilangan &y){
    if(x.a > y.a){
        std::cout<<x.a<<"::x lebih besar dari "<<y.a<<"::y"<<std::endl;
    }else{
        std::cout<<x.a<<"::x lebih kecil dari "<<y.a<<"::y"<<std::endl;
    }
}

Bilangan &Bilangan::operator=(const Bilangan &x){
    a = x.a;
    b = x.b;
    return *this;
}

std::istream &operator>>(std::istream &in, Bilangan &x){
    std::cout<<"Masukkan bagian integer : ";
    in>>x.a;
    std::cout<<"Masukkan bagian float   : ";
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
    std::cout<<"Nilai awal s : "<<s;
    std::cout<<"Nilai awal t : "<<t;
    s = t;
    std::cout<<"Setelah di assign t\nNilai s : "<<s;
    std::cout<<"Masukkan nilai objek d : ";
    std::cin>>d;
    std::cout<<"Setelah d + t = "<<d+t;
    std::cout<<"Nilai b dinegatifkan : "<<-d;
    return 0;
}