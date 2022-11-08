public class App {
    public static void main(String[] args) throws Exception {
        Tendik t1 = new Tendik("0001", "Empud Solehudin", "Citeurup, Kawali", "10 November 2002", "Laki-Laki", 2018);
        t1.setJamLembur(20);
        System.out.println("Contoh Tendik");
        t1.cetak();

        Dosen d1 = new Dosen("0002", "Asep Rahmat", "Patrol, Lumbung", "21 Februari 2002", "Laki-laki", 2015,
                "Informatika", "2100018165");
        d1.setSksLebih(6);
        System.out.println("Contoh Dosen");
        d1.cetak();
    }
}
