/*Lab Skill 4 - Question 3
Name		: Yong Yuan Lin
Date		: 10 October 2025*/

abstract class Stock{
    protected String partNumber;

    public Stock(String partNumber){
        this.partNumber = partNumber;
    }

    abstract public double getTotalCost();
}

class Item extends Stock implements Comparable<Object>{
    private int quantity;
    private double pricePerItem;

    public Item(String partNumber, int quantity, double pricePerItem){
        super(partNumber);
        this.quantity = quantity;
        this.pricePerItem = pricePerItem;
    }

    public double getPricePerItem(){
        return pricePerItem;
    }

    @Override
    public double getTotalCost(){
        return quantity * pricePerItem;
    }

    @Override
    public String toString(){
        return "Part Number: " + partNumber + "\nQuantity: " + quantity + "\nPrice Per Item: " + pricePerItem
        + "\nTotal Cost: " + getTotalCost();
    }

    @Override
    public int compareTo(Object o){
        if (o instanceof Item other){
            return Double.compare(this.getTotalCost(), other.getTotalCost());
        }
        return -1;
    }
}

public class TestProgram{
    public static void main(String[] args) {
        Item[] Comparison = new Item[2];
        Comparison[0] = new Item("A124", 10, 10.20);
        Comparison[1] = new Item("B555", 5, 1.59);

        for(Object o : Comparison){
            System.out.println(((Item)o).toString());
            System.out.println("");
        }

        int result = Comparison[0].compareTo(Comparison[1]);
        System.out.println("Result Comparison: " + result);
    }
}
