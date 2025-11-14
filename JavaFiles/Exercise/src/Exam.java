
import javax.swing.JOptionPane;

public class Exam{
    public static void main(String[] args){
        int[] marks = new int[10];
        String[] name = new String[10];
        int total = 0, highest, lowest;
        double average;
        int count = 0;

        for(int i = 0 ; i < marks.length ; i++){
            String msg = JOptionPane.showInputDialog("Enter Student Marks: ");
            marks[i] = Integer.parseInt(msg);
            name[i] = JOptionPane.showInputDialog("Enter Student Name: ");
            total += marks[i];
            count++;
        }
        average = total/count;
        count = 0;
        highest = marks[0];
        lowest = marks[0];
        for(int i = 0; i < marks.length ; i++){
            if(highest < marks[i]){
                highest = marks[i];
            }if(lowest > marks[i]){
                lowest = marks[i];
            }
            if(marks[i] > average){
                count++;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < marks.length; i++){
            sb.append("Student Name: ").append(name[i]).append("\nMarks: ").append(marks[i]);
        }
        sb.append("\nTotal Marks: ").append(total).append("\nHighest").append(highest).append("\nLowest: ").append(lowest).append("\nAverage: ");
        sb.append(average).append("Number of Students passed average: ").append(count);

        JOptionPane.showMessageDialog(null, sb.toString(), "Information", JOptionPane.INFORMATION_MESSAGE);
    }
}