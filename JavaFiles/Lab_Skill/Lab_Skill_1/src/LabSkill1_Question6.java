/*Lab Skill 1 - Question 6
Name        : YONG YUAN LIN
Date        : 6 AUGUST 2025*/
import java.text.DecimalFormat;
import java.util.Scanner;

public class LabSkill1_Question6 {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("0.00");
        Scanner s = new Scanner(System.in);

        System.out.print("Enter tax: ");
        double price = s.nextDouble();
        if(price >= 150 || price < 500){
            double taxRate = price * 0.05;
            double totalTax = price + taxRate;
            System.out.println("Tax entered: " + df.format(price) + "\nYour tax: " + df.format(taxRate) + "\nTotal Price to Pay: " + df.format(totalTax));
        }else if(price >= 500 || price < 1200){
            double taxRate = price * 0.10;
            double totalTax = price + taxRate;
            System.out.println("Tax entered: " + df.format(price) + "\nYour tax: " + df.format(taxRate) + "\nTotal Price to Pay: " + df.format(totalTax));
        }else if(price >= 1200){
            double taxRate = price * 0.15;
            double totalTax = price + taxRate;
            System.out.println("Tax entered: " + df.format(price) + "\nYour tax: " + df.format(taxRate) + "\nTotal Price to Pay: " + df.format(totalTax));
        }else{
            System.err.println("Please enter a valid number.");
        }
        s.close();
    }
}