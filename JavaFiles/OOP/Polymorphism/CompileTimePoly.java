package OOP.Polymorphism;

class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
}

public class CompileTimePoly {
    public static void main(String[] args) {
        Calculator c = new Calculator();
        System.out.println(c.add(3, 4));          // Calls int version
        System.out.println(c.add(3.2, 4.5));      // Calls double version
    }
}
