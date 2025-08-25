/*Lab Skill 2 - Question 1
Name        : Yong Yuan Lin
Date        : 21 August 2025*/


public class Rectangle {
    public int width;
    public int length;
    public int area;

    public static void main(String[] args) {
        Rectangle rectangle1 = new Rectangle();
        System.out.println("Rectangle 1 Area: " + rectangle1.getArea());

        Rectangle rectangle2 = new Rectangle(10, 15);
        System.out.println("Rectangle 2 Area: " + rectangle2.getArea());


        int total = rectangle1.getArea() + rectangle2.getArea();
        System.out.println("Total Area of both Rectangles: " + total);
    }


    public Rectangle(){
        this.width = 5;
        this.length = 10;
    }

    public Rectangle(int width, int length) {
        this.width = width;
        this.length = length;
    }

    public int getArea(){
        return width * length;
    }
}
