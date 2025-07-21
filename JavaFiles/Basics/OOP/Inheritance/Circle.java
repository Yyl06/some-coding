package OOP.Inheritance;

public class Circle{
    protected double radius;

    public Circle(double radius){
        this.radius = 1.0;
    }

    public double getArea(){
        return Math.PI * radius * radius;
    }

    public double getCircumference(){
        return 2 * Math.PI * radius;
    }
}