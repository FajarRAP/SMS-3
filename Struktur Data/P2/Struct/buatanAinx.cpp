#include<iostream>
#include<fstream>
#include<array>

const int jadiSales = 6;

struct JualanPerOrang{
    std::string ID;
    std::array<double, 4> perQuarter;
    double totalJual;
};

void inisialisasi(std::fstream &file, std::array<JualanPerOrang, jadiSales> &daftarSales, int jadiSales){
    for(int indeks = 0; indeks < jadiSales; indeks++){
        file >> daftarSales.at(indeks).ID; //baca ID
        for(int quarter = 0; quarter < 4; quarter++){
            daftarSales.at(indeks).perQuarter.at(quarter) = 0.0;
        }
        daftarSales.at(indeks).totalJual = 0.0;
    }
}

void bacaData(std::fstream &file, std::array<JualanPerOrang, jadiSales> &daftarSales, int jadiSales){
    std::string IDSales;
    int bulan, uang, kuarter, indeks;

    file>>IDSales;

    while(file){
        file>>bulan>>uang;
        for(indeks = 0; indeks < jadiSales; indeks++){
            if(IDSales == daftarSales.at(indeks).ID){
                break;
            }
        }

        if (1 <= bulan && bulan <= 3){ 
            kuarter = 0;
        }else if (4 <= bulan && bulan <= 6){
            kuarter = 1;
        }else if (7 <= bulan && bulan <= 9){
            kuarter = 2;
        }else{
            kuarter = 3;
        }

        if(indeks < jadiSales){
            daftarSales.at(indeks).perQuarter.at(kuarter) += uang;
        }else{
            std::cout<<"ID tidak ditemukan"<<std::endl;
        }
        file>>IDSales;
    }
}

int main(){
    std::fstream file;
    std::string namaFile;
    std::array<JualanPerOrang, jadiSales> daftarSales;

    std::cout<<"Nama file ID : ";
    std::cin>>namaFile;

    //mulai setData & inisialisasi
    file.open(namaFile + ".txt", std::ios::in);
    if(!file.is_open()){
        std::cout<<"File tidak ditemukan"<<std::endl;
        exit(1);
    }
    inisialisasi(file, daftarSales, jadiSales);
    file.close();
    //kelar setData & inisialisasi

    
    std::cout<<"Nama file data sales : ";
    std::cin>>namaFile;

    file.open(namaFile + ".txt", std::ios::in);
    bacaData(file, daftarSales, jadiSales);
    file.close();
    std::cout<<daftarSales.at(1).perQuarter.at(2);
    return 0;
}