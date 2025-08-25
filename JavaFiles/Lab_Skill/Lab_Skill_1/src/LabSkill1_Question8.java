
import java.text.DecimalFormat;
import javax.swing.JOptionPane;

/*Lab Skill 1 - Question 8
Name        : YONG YUAN LIN
Date        : 6 AUGUST 2025*/
public class LabSkill1_Question8 {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("0.00");
        String[] productData = new String[2];

        productData[0] = JOptionPane.showInputDialog(null, "Enter Product Name:");
        productData[1] = JOptionPane.showInputDialog(null, "Enter Product Price:");

        double price = Double.parseDouble(productData[1]);
        double taxRate;
        if(price <= 499){
            taxRate = 0.02;
        }else if(price >= 500 || price < 2500){
            taxRate = 0.08;
        }else{
            taxRate = 0.2;
        }

        double taxAmount = price * taxRate;
        double totalPrice = price + taxAmount;
        System.out.println("Product Name   : " + productData[0]);
        System.out.println("Original Price : RM " + df.format(price));
        System.out.println("Tax Charges    : RM " + df.format(taxAmount));
        System.out.println("Price After Tax: RM " + df.format(totalPrice));
    }
}
