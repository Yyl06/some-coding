
import java.util.ArrayList;
import java.util.Scanner;

abstract class Product{
    protected String ID;
    protected String name;
    protected double price;

    public Product(String ID, String name, double price){
        this.ID = ID;
        this.name = name;
        this.price = price;
    }

    public String getName(){
        return name;
    }
    
    public abstract void display();
}

class Books extends Product{
    private String author;
    
    public Books(String ID, String name, double price, String author){
        super(ID, name, price);
        this.author = author;
    }

    @Override
    public void display(){
        System.out.println("ID: " + ID + "\nName: " + name + "\nPrice: RM" + price + "\nAuthor: " + author);
    }
}

class Electronics extends Product{
    private String brand;

    public Electronics(String ID, String name, double price, String brand){
        super(ID, name, price);
        this.brand = brand;
    }

    @Override
    public void display(){
        System.out.println("Electronics ID: " + ID + "\nName: " + name +"\nPrice: RM" + price + "\nBrand: " + brand);
    }

}

public class Inventory{
    public static void main(String[] args) {
        ArrayList<Product> Inventory = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        while (true) { 
            System.out.println("\n--- Inventory Management System ---");
            System.out.println("1. Add Book");
            System.out.println("2. Add Electronics");
            System.out.println("3. Display All Products");
            System.out.println("4. Search Product by Name");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");

            int choice = sc.nextInt();
            sc.nextLine();

            switch(choice){
                case 1: 
                    System.out.print("Enter ID: ");
                    String bookId = sc.nextLine();
                    System.out.print("Enter Name: ");
                    String bookName = sc.nextLine();
                    System.out.print("Enter Price: ");
                    double bookPrice = sc.nextDouble(); sc.nextLine();
                    System.out.print("Enter Author: ");
                    String author = sc.nextLine();

                    Inventory.add(new Books(bookId, bookName, bookPrice, author));
                    System.out.println("Book added!");
                    break;

                case 2:
                    System.out.print("Enter ID: ");
                    String elecId = sc.nextLine();
                    System.out.print("Enter Name: ");
                    String elecName = sc.nextLine();
                    System.out.print("Enter Price: ");
                    double elecPrice = sc.nextDouble(); sc.nextLine();
                    System.out.print("Enter Brand: ");
                    String brand = sc.nextLine();

                    Inventory.add(new Electronics(elecId, elecName, elecPrice, brand));
                    System.out.println("Electronics added!");
                    break;

                case 3:
                    System.out.println("\n--- Product List ---");
                    if (Inventory.isEmpty()) {
                        System.out.println("No products in inventory.");
                    } else {
                        for (Product p : Inventory) {
                            p.display();
                        }
                    }
                    break;

                case 4:
                    System.out.print("Enter product name to search: ");
                    String searchName = sc.nextLine();
                    boolean found = false;
                    for (Product p : Inventory) {
                        if (p.getName().equalsIgnoreCase(searchName)) {
                            p.display();
                            found = true;
                        }
                    }
                    if (!found) {
                        System.out.println("Product not found.");
                    }
                    break;

                case 5:
                    System.out.println("Exiting system. Goodbye!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}
