/*Lab Skill 2 - Question 2
Name        : Yong Yuan Lin
Date        : 21 August 2025*/


public class Sales {
    private int quantity;
    private double price;
    private double totalPrice;
    private double tax;
    private double nettPrice;

    public Sales() {
        this.quantity = 10;
        this.price = 5.5;
    }

    public Sales(int quantity, double price){
        this.quantity = quantity;
        this.price = price;
    }

    public static void main(String[] args) {
        Sales sales1 = new Sales();
        sales1.setQuantity(50);
        sales1.setPrice(20.5);

        Sales sales2 = new Sales(20, 10.5);
    }

    public int getQuantity(){
        return quantity;
    }
    
    public void setQuantity(int quantity){
        this.quantity = quantity;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double price){
        this.price = price;
    }

    public double getTax(){
        return tax;
    }

    public double getNettPrice(){
        return nettPrice;
    }

    public double displaySales(){
        return totalPrice;
    }
}
