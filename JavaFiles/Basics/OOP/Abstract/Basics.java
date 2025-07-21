public class Basics {
    public static void main(String[] args) {
        Objects o1 = new Circle("red", true, 5.0);
        Objects o2 = new Rectangle("white", false, 10.5, 20.0);

        System.out.println("The Circle's Object Info:\n" + o1.toString() + "\n");
        System.out.println("The Rectangle's Object Info:\n" + o2.toString());
    }
}
