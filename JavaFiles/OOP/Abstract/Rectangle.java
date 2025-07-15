public class Rectangle extends Objects{
    private double width;
    private double height;

    public Rectangle(){
        super();
        width = 1.0;
        height = 1.0;
    }

    public Rectangle(String color, boolean filled, double width, double height){
        super(color, filled);
        this.width = width;
        this.height = height;
    }

    public double getWidth(){
        return width;
    }

    public void setWidth(double width){
        this.width = width;
    }

    public double getHeight(){
        return height;
    }

    public void setHeight(double height){
        this.height = height;
    }

    @Override
    public double findArea(){
        return height * width;
    }

    @Override
    public double findPerimeter(){
        return 2 * height * width;
    }

    @Override
    public String toString(){
        return super.toString() + "\n Width: " + getWidth() + "\n Height: " + getHeight()+ "\n Area: " + findArea()+ "\n Perimeter: " + findPerimeter();
    }
}
