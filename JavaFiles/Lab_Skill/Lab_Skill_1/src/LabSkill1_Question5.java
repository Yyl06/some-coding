
import java.text.DecimalFormat;
import javax.swing.JOptionPane;

/*Lab Skill 1 - Question 5
Name        : YONG YUAN LIN
Date        : 6 AUGUST 2025*/

public class LabSkill1_Question5 {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("0.00");
        String title = JOptionPane.showInputDialog(null, "Enter Book Title :", "Input", JOptionPane.QUESTION_MESSAGE);
        String quantityString = JOptionPane.showInputDialog(null, "Enter Quantity: ", "Input", JOptionPane.QUESTION_MESSAGE);
        String unitPriceString = JOptionPane.showInputDialog(null, "Enter Unit Price: ", "Input", JOptionPane.QUESTION_MESSAGE);

        int quantity = Integer.parseInt(quantityString);
        double unitPrice = Double.parseDouble(unitPriceString);

        double grossPrice = quantity * unitPrice;
        double discount = grossPrice * 0.10;
        double paymentDue = grossPrice - discount;

        String result = "Gross price: RM" + df.format(grossPrice) +
                        "\nDiscounted Price: RM" + df.format(discount) +
                        "\nPayment Due: RM" + df.format(paymentDue);
                        
        JOptionPane.showMessageDialog(null, result, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
