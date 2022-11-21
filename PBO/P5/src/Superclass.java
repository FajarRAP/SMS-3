public class Superclass {
    // protected bisa diakses oleh class itu sendiri dan keturunannya
    protected int num = 20; // properti bapanya

    protected void display() { // behavior bapanya
        System.out.println("Superclass. Value = " + num);
    }
}
