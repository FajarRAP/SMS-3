#include<iostream>

namespace strak{
    struct Mahasiswa{
        int nim;
        char kelas;
    };
}

class Mahasiswa{
    public:
        void setData(int nim, char kelas){
            data.nim = nim;
            data.kelas = kelas;
        }
        strak::Mahasiswa getData(){
            return data;
        }
    private:
        strak::Mahasiswa data;
};

int main(){
    Mahasiswa p2;
    strak::Mahasiswa tes;
    p2.setData(2100018165, 'C');
    tes = p2.getData();
    return 0;
}