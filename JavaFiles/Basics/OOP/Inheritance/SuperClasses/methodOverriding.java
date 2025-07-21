package OOP.Inheritance.SuperClasses;

class Circle {

    private double radius;

    public Circle() {
        radius = 1.0;
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double findArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public String toString() {
        return "Radius: " + radius + "\nArea: " + findArea();
    }
}

class Cylinder extends Circle{
    private double length;

    public Cylinder() {
        super();
        length = 1.0;
    }

    public Cylinder(double radius,
        double length) {
        super(radius);
        this.length = length;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    @Override
    public double findArea() {
        return 2 * super.findArea() + 2 * getRadius() * Math.PI * length;
    }

    public double findVolume() {
        return super.findArea()* length;
    }

    //Advised to use @Override 
    @Override
    public String toString() {
        return super.getRadius() + "\nLength:" + length + "\nArea:" + findArea() + "\nVolume:" + findVolume();
    }
}

    public class methodOverriding {
        public static void main(String[] args) {
            Cylinder c = new Cylinder(2.0, 5.0);
            System.out.println(c);
        }
    }
