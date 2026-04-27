import Accounts.LoginFrame;
import javax.swing.SwingUtilities;

public class UIMain {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new LoginFrame().setVisible(true);
        });
    }
}