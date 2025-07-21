public class inputMsgBox {
    public static void main(String[] args) {
        // Display a message dialog with an input field
        String input = javax.swing.JOptionPane.showInputDialog(null, "Please enter your name:", "Input Dialog", javax.swing.JOptionPane.QUESTION_MESSAGE);
        
        // Check if input is not null (user didn't cancel)
        if (input != null) {
            // Display the input back to the user
            javax.swing.JOptionPane.showMessageDialog(null, "Hello, " + input + "!", "Greeting", javax.swing.JOptionPane.INFORMATION_MESSAGE);
        } else {
            // User cancelled the input dialog
            javax.swing.JOptionPane.showMessageDialog(null, "No input provided.", "Cancelled", javax.swing.JOptionPane.WARNING_MESSAGE);
        }
    }
}
