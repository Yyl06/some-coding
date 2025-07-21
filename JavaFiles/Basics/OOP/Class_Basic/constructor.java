public class constructor{
    private double x;

    //Default constructor
    public constructor(double x) {
        this.x = x;
    }

    //Parameterized constructor
    public constructor() {
        this.x = 0.0;
    }

    //Accessor method
    public double getX() {
        return x;
    }

    //Mutator method
    public void setX(double x) {
        this.x = x;
    }

    //Calculation method
    public double calculate() {
        return x * 2;
    }

    // method to return information for object
    @Override
    public String toString() {
        return "Radius = " + x + " \nArea = " + calculate();
    }

    //Display method
    public void display() {
        System.out.println("Value of x: " + x);
        System.out.println("Calculated value: " + calculate());
    }

    public static void main(String[] args) {
        constructor obj = new constructor(5.0);
        System.out.println(obj);  // Prints: Radius = 5.0 Area = 10.0
    }
}