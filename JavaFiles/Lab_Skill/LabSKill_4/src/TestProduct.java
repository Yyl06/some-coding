/*Lab Skill 4 - Question 2
Name		: YONG YUAN LIN
Date		: 10 October 2025*/

abstract class Product{
    protected String description;
    protected double price;

    Product(String description, double price){
        this.description = description;
        this.price = price;
    }

    public double getPrice(){
        return price;
    }

    public String display(){
        return "Description: " + description + "\nPrice: " + price;
    }
}

interface taxable{
    double GasTaxRate = 0.75;
    double MotorVehicletaxRate = 0.5;

    abstract public double CalcTax();
}

class Gasoline extends Product implements taxable{
    private final String type;

    public Gasoline(String description, double price, String type){
        super(description, price);
        this.type = type;
    }

    public String getType(){
        return type;
    }

    @Override
    public double CalcTax(){
        return price * GasTaxRate;
    }
}

class MotorVehicle extends Product implements taxable{
    private String MotorType;

    public MotorVehicle(String description, double price, String MotorType) {
        super(description, price);
        this.MotorType = MotorType;
    }

    public String getMotorType(){
        return MotorType;
    }

    @Override
    public double CalcTax(){
        return price * MotorVehicletaxRate;
    }
}

class Food extends Product{
    private int calories;

    public Food(String description, double price, int food){
        super(description, price);
        this.calories = food;
    }

    public int getCalory(){
        return calories;
    }
}

public class TestProduct {
    public static void main(String[] args) {
        Product[] inventory = new Product[6];
        inventory[0] = new Food("Meat", 14.40, 2000);
        inventory[1] = new Food("Banana", 1.50, 500);
        inventory[2] = new MotorVehicle("Car", 55000.00, "Myvi");
        inventory[3] = new MotorVehicle("Motor", 12000.00, "Yamaha");
        inventory[4] = new Gasoline("Petrol 95", 25.90, "Petronas");
        inventory[5] = new Gasoline("Diesel", 13.85, "Shell");

        for(Object o : inventory){
            System.out.println(((Product) o).display());
            System.out.println("");
        }
    }
}
