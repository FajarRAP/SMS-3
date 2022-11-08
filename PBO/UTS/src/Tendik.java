public class Tendik extends Karyawan {
    private int jamLembur;

    public Tendik() {
    }

    public Tendik(String NIP, String nama, String alamat, String tanggalLahir, String jenisKelamin, int tahunMasuk) {
        super(NIP, nama, alamat, tanggalLahir, jenisKelamin, tahunMasuk);
    }

    public int getJamLembur() {
        return jamLembur;
    }

    public void setJamLembur(int jamLembur) {
        this.jamLembur = jamLembur;
    }

    public int hitungBonus(int jamLembur) {
        int bonus = 0;

        for (int a = 0; a < jamLembur; a++) {
            bonus += 50000;
        }
        return bonus;
    }

    public void hitungGaji(int jamLembur) {
        super.hitungGaji();
        System.out.println("Bonus Lembur  : " + hitungBonus(jamLembur));
        System.out.println("Total         : " + (getGaji() + hitungBonus(jamLembur)) + "\n");
    }

    public void cetak() {
        super.cetak();
        System.out.println("Jam Lembur    : " + getJamLembur());
        hitungGaji(getJamLembur());
    }

}
