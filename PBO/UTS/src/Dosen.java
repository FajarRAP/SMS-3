public class Dosen extends Karyawan {
    private String jurusan;
    private String nidn;
    private int sksLebih;

    public Dosen() {
    }

    public Dosen(String NIP, String nama, String alamat, String tanggalLahir, String jenisKelamin, int tahunMasuk,
            String jurusan, String nidn) {
        super(NIP, nama, alamat, tanggalLahir, jenisKelamin, tahunMasuk);
        this.jurusan = jurusan;
        this.nidn = nidn;
    }

    public String getJurusan() {
        return jurusan;
    }

    public void setJurusan(String jurusan) {
        this.jurusan = jurusan;
    }

    public String getNidn() {
        return nidn;
    }

    public void setNidn(String nidn) {
        this.nidn = nidn;
    }

    public int getSksLebih() {
        return sksLebih;
    }

    public void setSksLebih(int sksLebih) {
        this.sksLebih = sksLebih;
    }

    public int hitungBonus(int sksLebih) {
        int bonus = 0;

        for (int i = 0; i < 4; i++) {
            for (int a = 0; a < sksLebih; a++) {
                bonus += 100000;
            }
        }
        return bonus;
    }

    public void hitungGaji(int sksLebih) {
        super.hitungGaji();
        System.out.println("Bonus SKS     : " + hitungBonus(sksLebih));
        System.out.println("Total         : " + (getGaji() + hitungBonus(sksLebih)) + "\n");
    }

    public void cetak() {
        super.cetak();
        System.out.println("Jurusan       : " + getJurusan());
        System.out.println("NIDN          : " + getNidn());
        System.out.println("SKS Lebih     : " + getSksLebih());
        hitungGaji(getSksLebih());
    }

}
