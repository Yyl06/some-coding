package OOP.Inheritance;

public class Cylinder extends Circle{
    private final double length;

    public Cylinder(double radius, double length) {
        super(radius);
        this.length = length;
    }

    public double getVolume() {
        return getArea() * length;
    }
}
