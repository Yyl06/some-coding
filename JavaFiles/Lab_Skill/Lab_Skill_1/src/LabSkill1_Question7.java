
import javax.swing.JOptionPane;

/*Lab Skill 1 - Question 7
Name        : YONG YUAN LIN
Date        : 6 AUGUST 2025*/

public class LabSkill1_Question7 {
    public static void main(String[] args) {
        StringBuilder allNum = new StringBuilder();
        for(int i = 1 ; i < 21 ; i++){
            allNum.append("Number: ").append(i).append("\n");
        }
        JOptionPane.showMessageDialog(null, allNum.toString(), "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
