package Student_Management;
import javax.swing.SwingUtilities;

import Student_Management.Accounts.LoginFrame;

public class UIMain {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new LoginFrame().setVisible(true); // Launch GUI
        });
    }
}