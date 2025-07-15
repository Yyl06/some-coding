public class Circle extends Objects{
    private double radius;

    public Circle(){
        super();
        radius = 1.0;
    }

    public Circle(String color, boolean filled, double radius){
        super(color, filled);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius){
        this.radius = radius;
    }

    @Override
    public double findArea(){
        return Math.PI * radius * radius;
    }

    @Override
    public double findPerimeter(){
        return 2 * Math.PI * radius;
    }

    @Override
    public String toString(){
        return super.toString() + "\nRadius: " + radius + "\nArea: " + findArea() + "\nPerimeter: " + findPerimeter();
    }
}