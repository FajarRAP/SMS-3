#include <iostream>

class Postest{
    public:
        Postest(){
            while(!this->setAngka());
            std::cout<<"1. Iteratif\n2. Rekursif\nPilih : ";
            std::cin>>this->pilihMenu;
            switch(this->pilihMenu){
                case '1':
                    std::cout<<"Setelah dibalik"<<std::endl;
                    this->balikIteratif(angka);
                    break;
                case '2':
                    std::cout<<"Setelah dibalik"<<std::endl;
                    this->balikRekursif(angka);
                    break;
            }
        }

        bool setAngka(){
            std::cout<<"Angka : ";
            std::cin>>this->angka;
            std::string x = std::to_string(this->angka);
            if(x.length() > 5){
                std::cout<<"Angka > 5"<<std::endl;
                return 0;
            }
            return 1;
        }

        void balikIteratif(int n){
            while(n != 0){
                std::cout<<n%10;
                n/=10;
            }
        }

        void balikRekursif(int n){
            if(n != 0){
                std::cout<<n%10;
                balikRekursif(n/10);
            }
        }
    private:
        char pilihMenu;
        int angka;
};

int main(){
    Postest *minggu1 = new Postest;
    return 0;
}