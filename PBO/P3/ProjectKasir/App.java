package PBO.P3.ProjectKasir;

public class App{
    public static void main(String args[]) throws Exception{
        Barang item1 = new Barang("1911", "Giv Putih", 2500, 3);
        item1.displayBarang();
        item1.updateNama("Giv Hitam");
        item1.displayBarang();
    }
}
