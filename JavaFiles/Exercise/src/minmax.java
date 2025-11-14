
import javax.swing.JOptionPane;

public class minmax {
    public static void main(String[] args) {
        int[] numbers = new int[5];
        for(int i = 0; i < numbers.length; i++){
            String input = JOptionPane.showInputDialog(null, "Enter Number: ");
            numbers[i] = Integer.parseInt(input);
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < numbers.length; i++){
            sb.append("Numbers Entered: ").append(numbers[i]).append("\n");
        }
        JOptionPane.showMessageDialog(null, sb.toString(), "Numbers Entered: ", JOptionPane.INFORMATION_MESSAGE);

        int highestNum = numbers[0];
        int lowestNum = numbers[0];
        for(int i = 0; i < numbers.length; i++){
            if(numbers[i] > highestNum){
                highestNum = numbers[i];
            }if(numbers[i] < lowestNum){
                lowestNum = numbers[i];
            }
        }
        JOptionPane.showMessageDialog(null, highestNum, "Highest Number: ", JOptionPane.INFORMATION_MESSAGE);
        JOptionPane.showMessageDialog(null, lowestNum, "Lowest Number: ", JOptionPane.INFORMATION_MESSAGE);
        }
}
