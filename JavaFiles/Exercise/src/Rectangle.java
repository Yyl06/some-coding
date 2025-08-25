public class Rectangle {
    private float length;
    private float width;

    public Rectangle() {
        this.length = 1.0f;
        this.width = 1.0f;
    }

    public Rectangle(float length, float width){
        this.length = length;
        this.width = width;
    }

    public float getLength(){
        return this.length;
    }

    public void setLength(float length){
        this.length = length; 
    }

    public float getWidth(){
        return this.width;
    }

    public void setWidth(float width){
        this.width = width;
    }

    public double getArea(){
        return width * length;
    }

    public double getPerimeter(){
        return (width * 2) + (length * 2);
    }

    @Override
    public String toString(){
        return "Rectangle length: " + this.length + " Width: " + this.width + " and area: " + getArea() + " and perimeter: " + getPerimeter(); 
    }

    public static void main(String[] args) {
        Rectangle Shape1 = new Rectangle();
        System.out.println(Shape1.toString());
    }
}
