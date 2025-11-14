/*Lab Skill 4 - Question 1
Name		: Yong Yuan Lin
Date		: 10 October 2025*/


abstract class RetailItem{
    protected String itemID;

    public RetailItem(){}

    public void setItemID(String itemID){
        this.itemID = itemID;
    }

    abstract double calculateSalesAmount();

    @Override
    public String toString(){
        return ""; 
    }
}

class CD extends RetailItem{
    private String title;
    private int quantity;
    private double price;

    CD(){}

    public void setTitle(String title){
        this.title = title;
    }

    public void setQuantity(int quantity){
        this.quantity = quantity;
    }

    public void setprice(double price){
        this.price = price;
    }

    @Override
    public double calculateSalesAmount(){
        return quantity * price;
    }

    @Override
    public String toString(){
        return "Item ID: " + itemID + "\nTitle: " + title + "\nQuantity: " + quantity + "\nPrice: " + price + "\nTotal Sales: " + calculateSalesAmount(); 
    }
}

public class Test{
    public static void main(String[] args) {
        CD test1 = new CD();
        test1.setItemID("A123");
        test1.setTitle("Harry Potter");
        test1.setQuantity(5);
        test1.setprice(15.30);

        System.out.println(test1.toString());
    }
}