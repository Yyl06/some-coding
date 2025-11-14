import javax.swing.JOptionPane;

public class Exercise5_YongYuanLin{
    public static int findNumberOfDigits(String msg){
        int count = 0;
        char op;
        for(int i = 0 ; i < msg.length() ; i++){
            op = msg.charAt(i);
            if(Character.isDigit(op)){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        String InputNum1, InputNum2;
        InputNum1 = JOptionPane.showInputDialog("Enter Number 1: ");
        int num1 = Integer.parseInt(InputNum1);

        InputNum2 = JOptionPane.showInputDialog("Enter Number 2: ");
        int num2 = Integer.parseInt(InputNum2);

        StringBuilder sb = new StringBuilder();
        for(int i = 1 ; i <= num2 ; i++){
            int ans = num1*i;
            sb.append(num1).append("x").append(i).append("=").append(ans).append("\n");
        }
        JOptionPane.showMessageDialog(null, sb.toString(), "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
