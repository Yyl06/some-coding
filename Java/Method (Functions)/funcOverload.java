public class funcOverload {
    public static int add(int a, int b) {
        return a + b;
    }

    public static double add(double a, double b) {
        return a + b;
    }

    public static void main(String[] args) {
        System.out.println("Integer addition: " + add(5, 10));
        System.out.println("Double addition: " + add(5.5, 10.5));
    }
}
