import javax.swing.JOptionPane;

public class Input {
    public static void main(String[] args) {
        showOption();
    }
    public static void showOption() {
        double radius = 0 , area = 0, circumference = 0;
        String input;

        input = JOptionPane.showInputDialog(null, "Insert Radius: ", "Radius input", JOptionPane.QUESTION_MESSAGE);
        radius = Double.parseDouble(input);

        area = Math.PI * Math.pow(radius, 2);
        circumference = 2 * Math.PI * radius;
        JOptionPane.showMessageDialog(null, "Area:"+ area + "\nCircumference: " + circumference, "Result", JOptionPane.INFORMATION_MESSAGE);
    }
}
