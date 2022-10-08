package PBO.P3.ProjectKasir;

public class Barang {
    //Properties
    private String idBarang;
    private String namaBarang;
    private double hargaBarang;
    private int stok;

    //contructor
    public Barang(String idBarang, String namaBarang, double hargaBarang, int stok){
        this.idBarang = idBarang;
        this.namaBarang = namaBarang;
        this.hargaBarang = hargaBarang;
        this.stok = stok;
    }

    //Behaviours
    public void updateNama(String updateNama){
        this.namaBarang = updateNama;
    }

    public void updateHarga(double updateHarga){
        this.hargaBarang = updateHarga;
    }

    //pesan
    public void displayBarang(){
        System.out.println("ID Barang = " + this.idBarang);
        System.out.println("Nama Barang = " + this.namaBarang);
        System.out.println("Harga Barang = " + this.hargaBarang);
        System.out.println("Stok = " + this.stok);
    }
}
