import javax.swing.JOptionPane;

public class dialogMsgBox {
    public static void main(String[] args) {
        // WARNING_MESSAGE
        JOptionPane.showMessageDialog(null, "This is a warning!", "Warning", JOptionPane.WARNING_MESSAGE);

        // QUESTION_MESSAGE
        JOptionPane.showMessageDialog(null, "Is this a question?", "Question", JOptionPane.QUESTION_MESSAGE);

        // INFORMATION_MESSAGE
        JOptionPane.showMessageDialog(null, "This is just some info.", "Information", JOptionPane.INFORMATION_MESSAGE);

        // ERROR_MESSAGE
        JOptionPane.showMessageDialog(null, "An error has occurred!", "Error", JOptionPane.ERROR_MESSAGE);

        // PLAIN_MESSAGE (no icon)
        JOptionPane.showMessageDialog(null, "Just plain text. No icon.", "Plain", JOptionPane.PLAIN_MESSAGE);
    }
}
