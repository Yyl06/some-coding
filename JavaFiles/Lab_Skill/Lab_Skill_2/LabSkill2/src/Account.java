/*Lab Skill 2 - Question 4
Name        : Yong Yuan Lin
Date        : 21 August 2025*/

public class Account {
    private String id;
    private String name;
    private double balance;

    public Account(String id, String name) {
        this.id = id; 
        this.name = name;
    }

    public Account(String id, String name, double balance){
        this.id = id;
        this.name = name;
        this.balance = balance;
    }

    public static void main(String[] args) {
        Account acc1 = new Account("AC01", "Ahmad", 1260.00);
        System.out.println(acc1.toString() + "\n");

        System.out.println("Debit from AC01 RM 1500.00");
        acc1.debit(1500.00);
        System.out.println("Credit to account AC01 Rm 1500.00");
        acc1.credit(1500.00);

        System.out.println("AC01 New Balance: RM " + acc1.getBalance());

        Account acc2 = new Account("AC02", "Aisyah", 7300.00);
        System.out.println(acc2.toString());
        System.out.println("\nTransfer RM 1000 from AC02 to AC01");
        acc2.transferTo(acc1, 1000.00);

        System.out.println("\n===== Final Balance =====");
        System.out.println("AC01 new balance: RM " + acc1.getBalance());
        System.out.println("AC02 new balance: RM " + acc2.getBalance());
    }

    public String getID(){
        return id;
    }

    public String getName(){
        return name;
    }
    
    public double getBalance(){
        return balance;
    }

    public double credit(double amount){
        balance += amount;
        return balance;
    }

    public double debit(double amount){
        if(amount <= balance){
            balance -= amount;
            return balance;
        }else{
            System.err.println("Amount Exceeded! ");
        }
        return balance;
    }

    public double transferTo(Account acc, double amount){
        if(amount <= balance){
            balance -= amount;
            return balance;
        }else{
            System.err.println("Amount Exceeded! ");
        }
        return balance;
    }

    @Override
    public String toString(){
        return "\n=== Account Info ===" + 
        "\nAccount Id: " + getID() +
        "\nName: " + getName() +
        "\nBalance: " + getBalance() +
        "\n=== End Info ===";
    }
}
