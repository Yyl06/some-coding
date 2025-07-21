package OOP.Polymorphism;

import OOP.Inheritance.Circle;
import OOP.Inheritance.Cylinder;

public class Instanceof {
    public static void main(String[] args) {
        Object ob1 = new Circle(1.0);
        Object ob2 = new Cylinder(1.0, 1.0);
        DisplayObject(ob1);
        DisplayObject(ob2);
    }

    public static void DisplayObject(Object ob) {
        if (ob instanceof Cylinder) {
            Cylinder c = (Cylinder) ob;
            System.out.println("The cylinder area is " + c.getArea());
            System.out.println("The cylinder volume is " + c.getVolume());
        } else if (ob instanceof Circle) {
            Circle c = (Circle) ob;
            System.out.println("The circle area is " + c.getArea());
        }
    }
}
