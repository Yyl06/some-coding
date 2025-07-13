package OOP.Inheritance;

public class Client {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        Cylinder cylinder = new Cylinder(5, 10);

        System.out.println("Circle Area: " + circle.getArea());
        System.out.println("Circle Circumference: " + circle.getCircumference());
        System.out.println("Cylinder Volume: " + cylinder.getVolume());
    }
}
