#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

struct dataLahir{
    std::string tempat;
    std::string tanggal;
    std::string bulan;
    std::string tahun;
};

struct dataAlamat{
    std::string alamat;
    std::string rt;
    std::string rw;
    std::string desa;
    std::string kec;
};

struct dataKTP{
    std::string provinsi;
    std::string kabupatenKota;
    std::string nik;
    std::string nama;
    dataLahir ktpLahir;
    const char *jenisKelamin;
    const char *golDarah;
    dataAlamat ktpAlamat;
    const char *agama;
    const char *statusKawin;
    const char *gawe;
    const char *wargaNegara;
    const char *berlakuHingga;
};


class KTP{
    friend std::istream &operator>>(std::istream &masukan, KTP &data){
        switch(data.pilihMenu){
        case '1':
            while(!data.setProvinsi());
            while(!data.setKabKota());
            while(!data.setNIK());
            data.setNama();
            while(!data.setKelahiran());
            while(!data.setKelamin());
            while(!data.setGolonganDarah());
            while(!data.setAlamat());
            while(!data.setAgama());
            while(!data.setKawin());
            while(!data.isGawe());
            while(!data.isPenyusup());
            data.setDurasi("SEUMUR HIDUP");
            data.tulisFile();
            break;
        case '2':
            data.bacaFile();
            break;
        }
        return masukan;
    }

    friend std::ostream &operator<<(std::ostream &keluaran, KTP &data){
        switch(data.pilihMenu){
        case '1':
            data.garis(60);
        
            data.cetak(keluaran, 20, 30, "PROVINSI ",
                    data.pengguna.provinsi);
            data.cetak(keluaran, 21, 28, "KABUPATEN ",
                    data.pengguna.kabupatenKota);
        
            keluaran << std::left << std::setw(59) << "|"
                << "|" << std::endl;
        
            data.cetak(keluaran, 2, 33, "NIK\t\t\t: ", data.pengguna.nik);
            data.cetak(keluaran, 2, 33, "Nama\t\t\t: ", data.pengguna.nama);
        
            keluaran << std::left << std::setw(2) << "|"
                << "Tempat/Tgl Lahir\t: " << data.pengguna.ktpLahir.tempat
                << ", ";
            keluaran << data.pengguna.ktpLahir.tanggal << "-" << data.bantuBulan
                << data.pengguna.ktpLahir.bulan << "-" << std::setw(20);
            keluaran << data.pengguna.ktpLahir.tahun << "|" << std::endl;
            keluaran << std::left << std::setw(2) << "|"
                << "Jenis Kelamin\t\t: " << data.pengguna.jenisKelamin << "\t";
            keluaran << "Gol. Darah : " << std::setw(6) << data.pengguna.golDarah << "|"
                << std::endl;
        
            data.cetak(keluaran, 2, 33,
                    "Alamat\t\t: ", data.pengguna.ktpAlamat.alamat);
        
            keluaran << std::left << std::setw(2) << "|"
                << "\tRT/RW\t\t: " << data.pengguna.ktpAlamat.rt << "/" << std::setw(29)
                << data.pengguna.ktpAlamat.rw << "|";
            keluaran << std::endl;
        
            data.cetak(keluaran, 2, 33,
                    "\tKel/Desa\t: ", data.pengguna.ktpAlamat.desa);
            data.cetak(keluaran, 2, 33,
                    "\tKecamatan\t: ", data.pengguna.ktpAlamat.kec);
            data.cetak(keluaran, 2, 33, "Agama\t\t\t: ", data.pengguna.agama);
            data.cetak(keluaran, 2, 33,
                    "Status Perkawinan\t: ", data.pengguna.statusKawin);
            data.cetak(keluaran, 2, 33, "Pekerjaan\t\t: ", data.pengguna.gawe);
            data.cetak(keluaran, 2, 33,
                    "Kewarganegaraan\t: ", data.pengguna.wargaNegara);
            data.cetak(keluaran, 2, 33, "Berlaku hingga\t: ", data.pengguna.berlakuHingga);
            data.garis(60);
            break;
        case '2':
            std::cout<<std::endl;
            data.garis(60);
        
            data.cetak(keluaran, 20, 30, "PROVINSI ",
                    data.buffer[0]);
            data.cetak(keluaran, 21, 28, "KABUPATEN ",
                    data.buffer[1]);
        
            keluaran << std::left << std::setw(59) << "|"
                << "|" << std::endl;
        
            data.cetak(keluaran, 2, 33, "NIK\t\t\t: ", data.buffer[2]);
            data.cetak(keluaran, 2, 33, "Nama\t\t\t: ", data.buffer[3]);
            keluaran << std::left << std::setw(2) << "|" << "Tempat/Tgl Lahir\t: " << data.buffer[4] << ", ";
            keluaran << data.buffer[5] << "-" << data.bantuBulan << data.buffer[6] << "-" << std::setw(20);
            keluaran << data.buffer[7] << "|" << std::endl;
            keluaran << std::left << std::setw(2) << "|" << "Jenis Kelamin\t\t: " << data.buffer[8] << "\t";
            keluaran << "Gol. Darah : " << std::setw(6) << data.buffer[9] << "|" << std::endl;
            data.cetak(keluaran, 2, 33, "Alamat\t\t: ", data.buffer[10]);
            keluaran << std::left << std::setw(2) << "|" << "\tRT/RW\t\t: " << data.buffer[11] << "/" << std::setw(29) << data.buffer[12] << "|";
            keluaran << std::endl;
        
            data.cetak(keluaran, 2, 33, "\tKel/Desa\t: ", data.buffer[13]);
            data.cetak(keluaran, 2, 33, "\tKecamatan\t: ", data.buffer[14]);
            data.cetak(keluaran, 2, 33, "Agama\t\t\t: ", data.buffer[15]);
            data.cetak(keluaran, 2, 33, "Status Perkawinan\t: ", data.buffer[16]);
            data.cetak(keluaran, 2, 33, "Pekerjaan\t\t: ", data.buffer[17]);
            data.cetak(keluaran, 2, 33, "Kewarganegaraan\t: ", data.buffer[18]);
            data.cetak(keluaran, 2, 33, "Berlaku hingga\t: ", data.buffer[19]);
            data.garis(60);
            break;
        }
        return keluaran;
    }

    public:
        KTP(){
        std::cout<<"Program KTP Semester 3"<<std::endl;
        std::cout<<"1. Input Baru\n2. Baca file\nPilih : ";
        std::cin>>pilihMenu;
        }

        bool setProvinsi(){
        std::vector<std::string> namaProvinsi;
        std::string buffer;
        bacaDatabase(namaProvinsi, buffer, "Database/dataProvinsi.txt");
        std::cin.ignore();
        std::cout<<"Provinsi : ";
        std::getline(std::cin, pengguna.provinsi);
        for(int a = 0; a < namaProvinsi.size(); a++){
            if(pengguna.provinsi == namaProvinsi.at(a)){
            return 1;
            }
        }
        std::cout<<"Provinsi tidak valid"<<std::endl;
        return 0;
        }

        bool setKabKota(){
        bool isKetemu = false;
        std::vector<std::string> kabupatenKota;
        std::string buffer;
        char pilih;
        std::cout<<"1. Kabupaten\n2. Kota\nPilih : ";
        std::cin>>pilih;
        switch(pilih){
            case '1':
            bacaDatabase(kabupatenKota, buffer, "Database/dataKab.txt");
            while(!isKetemu){
                std::cout<<"Nama Kabupaten : ";
                std::cin>>pengguna.kabupatenKota;
                for(int a = 0; a < kabupatenKota.size(); a++){
                if(pengguna.kabupatenKota == kabupatenKota.at(a)){
                    return 1;
                }
                }            
                std::cout<<"Kabupaten tidak valid"<<std::endl;
                return 0;
            }
            break;
            case '2':
            bacaDatabase(kabupatenKota, buffer, "Database/dataKota.txt");
            while(!isKetemu){
                std::cout<<"Nama Kota : ";
                std::cin>>pengguna.kabupatenKota;
                for(int a = 0; a < kabupatenKota.size(); a++){
                if(pengguna.kabupatenKota == kabupatenKota.at(a)){
                    return 1;
                }
                }            
                std::cout<<"Kota tidak valid"<<std::endl;
                return 0;
            }
            break;
            default:
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
            return 0;
        }
        return 0;
        }

        bool setNIK(){
        std::cout<<"NIK : ";
        std::cin>>pengguna.nik;
        if(cekAngka(pengguna.nik) && pengguna.nik.length() == 16){
            return 1;
        }
        std::cout<<"NIK tidak valid"<<std::endl;
        return 0;
        }

        void setNama(){
        std::cin.ignore();
        std::cout<<"Nama : ";
        std::getline(std::cin, pengguna.nama);
        }

        bool setKelahiran(){
        short tanggal, bulan, tahun;
        std::cout<<"Kelahiran"<<std::endl;
        std::cout<<"Tempat : ";
        std::cin>>pengguna.ktpLahir.tempat;
        std::cout<<"Tanggal : ";
        std::cin>>pengguna.ktpLahir.tanggal;
        std::cout<<"Bulan   : ";
        std::cin>>pengguna.ktpLahir.bulan;
        std::cout<<"Tahun   : ";
        std::cin>>pengguna.ktpLahir.tahun;
        if(cekAngka(pengguna.ktpLahir.tanggal) && cekAngka(pengguna.ktpLahir.bulan) && cekAngka(pengguna.ktpLahir.tahun)){
            tanggal = std::stoi(pengguna.ktpLahir.tanggal);
            bulan = std::stoi(pengguna.ktpLahir.bulan);
            tahun = std::stoi(pengguna.ktpLahir.tahun);
            if(bulan < 10){
            bantuBulan = "0";
            }
            if(tanggal <= 0 || tanggal > 31){
            std::cout<<"Tanggal tidak valid"<<std::endl;
            return 0;
            }else if(bulan <= 0 || bulan > 12){
            std::cout<<"Bulan tidak valid"<<std::endl;
            return 0;
            }else if(tahun <= 0){
            std::cout<<"Tahun tidak valid"<<std::endl;
            return 0;
            }
        return 1;
        }
        std::cout<<"Mengandung karakter ilegal"<<std::endl;
        return 0;
        }

        bool setKelamin(){
        char pilihKelamin;
        std::cout<<"Jenis Kelamin : "<<std::endl;
        std::cout<<"1. Laki-laki\n2. Perempuan\nPilih : ";
        std::cin>>pilihKelamin;
        switch(pilihKelamin){
            case '1':
            pengguna.jenisKelamin = "LAKI-LAKI";
            return 1;
            break;
            case '2':
            pengguna.jenisKelamin = "PEREMPUAN";
            return 1;
            break;
            default:
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
        }
        return 0;
        }

        bool setGolonganDarah(){
        char pilihGolDar;
        std::cout<<"Golongan darah : "<<std::endl;
        std::cout<<"1. O\n2. AB\n3. B\n4. A\nPilih : ";
        std::cin>>pilihGolDar;
        switch(pilihGolDar){
            case '1':
            pengguna.golDarah = "O";
            return 1;
            break;
            case '2':
            pengguna.golDarah = "AB";
            return 1;
            break;
            case '3':
            pengguna.golDarah = "B";
            return 1;
            break;
            case '4':
            pengguna.golDarah = "A";
            return 1;
            break;
            default:
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
        }
        return 0;
        }

        bool setAlamat(){
        std::cin.ignore();
        std::cout<<"Alamat    : ";
        std::getline(std::cin, pengguna.ktpAlamat.alamat);
        std::cout<<"RT        : ";
        std::cin>>pengguna.ktpAlamat.rt;
        if(!cekAngka(pengguna.ktpAlamat.rt)){
            std::cout<<"RT tidak valid"<<std::endl;
            return 0;
        }
        std::cout<<"RW        : ";
        std::cin>>pengguna.ktpAlamat.rw;
        if(!cekAngka(pengguna.ktpAlamat.rw)){
            std::cout<<"RW tidak valid"<<std::endl;
            return 0;
        }
        std::cout<<"Kel/Desa  : ";
        std::cin>>pengguna.ktpAlamat.desa;
        std::cout<<"Kecamatan : ";
        std::cin>>pengguna.ktpAlamat.kec;
        return 1;
        }

        bool setAgama(){
        char pilihAgama;
        std::cout<<"Agama : "<<std::endl;
        std::cout<<"1. Buddha\n2. Islam\n3. Hindu\n4. Katolik\n5. Konghucu\n6. Protestan\nPilih : ";
        std::cin>>pilihAgama;
        switch(pilihAgama){
            case '1':
            pengguna.agama = "BUDDHA";
            return 1;
            break;
            case '2':
            pengguna.agama = "ISLAM";
            return 1;
            break;
            case '3':
            pengguna.agama = "HINDU";
            return 1;
            break;
            case '4':
            pengguna.agama = "KATOLIK";
            return 1;
            break;
            case '5':
            pengguna.agama = "KONGHUCU";
            return 1;
            break;
            case '6':
            pengguna.agama = "PROTESTAN";
            return 1;
            break;
            default:
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
        }
        return 0;
        }

        bool setKawin(){
        char pilihKawin;
        std::cout<<"Status Perkawinan : "<<std::endl;
        std::cout<<"1. KAWIN\n2. BELUM KAWIN\n3. CERAI MATI\n4. CERAI HIDUP\nPilih : ";
        std::cin>>pilihKawin;
        switch(pilihKawin){
            case '1':
            pengguna.statusKawin = "KAWIN";
            return 1;
            break;
            case '2':
            pengguna.statusKawin = "BELUM KAWIN";
            return 1;
            break;
            case '3':
            pengguna.statusKawin = "CERAI MATI";
            return 1;
            break;
            case '4':
            pengguna.statusKawin = "CERAI HIDUP";
            return 1;
            break;
            default:  
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
        }
        return 0;
        }

        bool isGawe(){
        char pilihGawe;
        std::cout<<"Pekerjaan : "<<std::endl;
        std::cout<<"1. BEKERJA\n2. BELUM/TIDAK BEKERJA\nPilih : ";
        std::cin>>pilihGawe;
        switch(pilihGawe){
            case '1':
            pengguna.gawe = "BEKERJA";
            return 1;
            break;
            case '2':
            pengguna.gawe = "NGANGGUR";
            return 1;
            break;
            default:
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
        }
        return 0;
        }

        bool isPenyusup(){
        char pilihWN;
        std::cout<<"Kewarganegaraan : "<<std::endl;
        std::cout<<"1. WNI\n2. WNA\nPilih : ";
        std::cin>>pilihWN;
        switch(pilihWN){
            case '1':
            pengguna.wargaNegara = "WNI";
            return 1;
            break;
            case '2':
            pengguna.wargaNegara = "WNA";
            return 1;
            break;
            default:
            std::cout<<"Pilihan tidak tersedia"<<std::endl;
        }
        return 0;
        }

        void setDurasi(const char *kata){
        pengguna.berlakuHingga = kata;
        }

        void tulisFile(){
        std::fstream tulis;
        tulis.open("Database/hasilInput.txt", std::ios::out|std::ios::app);
        tulis<<pengguna.provinsi<<","<<pengguna.kabupatenKota<<","<<pengguna.nik<<","<<pengguna.nama<<","<<pengguna.ktpLahir.tempat<<","<<pengguna.ktpLahir.tanggal<<","<<pengguna.ktpLahir.bulan<<","<<pengguna.ktpLahir.tahun<<","<<pengguna.jenisKelamin<<","<<pengguna.golDarah<<","<<pengguna.ktpAlamat.alamat<<","<<pengguna.ktpAlamat.rt<<","<<pengguna.ktpAlamat.rw<<","<<pengguna.ktpAlamat.desa<<","<<pengguna.ktpAlamat.kec<<","<<pengguna.agama<<","<<pengguna.statusKawin<<","<<pengguna.gawe<<","<<pengguna.wargaNegara<<","<<pengguna.berlakuHingga<<std::endl;
        tulis.close();
        }

        void bacaFile(){
        std::fstream baca;
        baca.open("Database/hasilInput.txt", std::ios::in);
        while(
            std::getline(baca, buffer[0], ',') &&
            std::getline(baca, buffer[1], ',') &&
            std::getline(baca, buffer[2], ',') &&
            std::getline(baca, buffer[3], ',') &&
            std::getline(baca, buffer[4], ',') &&
            std::getline(baca, buffer[5], ',') &&
            std::getline(baca, buffer[6], ',') &&
            std::getline(baca, buffer[7], ',') &&
            std::getline(baca, buffer[8], ',') &&
            std::getline(baca, buffer[9], ',') &&
            std::getline(baca, buffer[10], ',') &&
            std::getline(baca, buffer[11], ',') &&
            std::getline(baca, buffer[12], ',') &&
            std::getline(baca, buffer[13], ',') &&
            std::getline(baca, buffer[14], ',') &&
            std::getline(baca, buffer[15], ',') &&
            std::getline(baca, buffer[16], ',') &&
            std::getline(baca, buffer[17], ',') &&
            std::getline(baca, buffer[18], ',') &&
            std::getline(baca, buffer[19], ',') &&
            std::getline(baca, buffer[20])
        );
        baca.close();
        }

        bool cekAngka(std::string nik){
        for(int a = 0; a < nik.length(); a++){
            if(isdigit(nik[a]) == 0){
            return 0;
            }
        }
        return 1;
        }
        
        template <typename T>
        void bacaDatabase(std::vector<T> &vector, T buffer, const char *namaFile){
        std::ifstream bacaDatabase;
        bacaDatabase.open(namaFile);
        for(int a = 0; std::getline(bacaDatabase, buffer); a++){
            vector.push_back(buffer);
        }
        bacaDatabase.close();
        }

        void garis(int x){
        for(int a = 0; a < x; a++){
            std::cout<<"=";
        }
        std::cout<<std::endl;
        }

        template <typename T>
        void cetak(std::ostream &x, int batasKiri, int batasKanan, const char *kata, T &dataNya) {
        x << std::left << std::setw(batasKiri) << "|" << kata
            << std::setw(batasKanan) << dataNya << "|" << std::endl;
        }

    private:
        dataKTP pengguna;
        const char *bantuBulan = "";
        char pilihMenu;
        std::string buffer[21];
};

int main(){
    KTP orang[3];
    for(int a = 0; a < 3; a++){
        std::cin>>orang[a];
        std::cout<<orang[a];
    }
    return 0;
}