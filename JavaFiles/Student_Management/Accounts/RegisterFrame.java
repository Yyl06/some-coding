package Student_Management.Accounts;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class RegisterFrame extends JFrame {

    private JTextField usernameField;
    private JPasswordField passwordField;

    public RegisterFrame() {
        setTitle("User Registration");
        setSize(400, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(null);

        JLabel userLabel = new JLabel("Username:");
        userLabel.setBounds(50, 40, 100, 30);
        panel.add(userLabel);

        usernameField = new JTextField();
        usernameField.setBounds(150, 40, 180, 30);
        panel.add(usernameField);

        JLabel passLabel = new JLabel("Password:");
        passLabel.setBounds(50, 90, 100, 30);
        panel.add(passLabel);

        passwordField = new JPasswordField();
        passwordField.setBounds(150, 90, 180, 30);
        panel.add(passwordField);

        JLabel roleLabel = new JLabel("Role:");
        roleLabel.setBounds(50, 130, 100, 30);
        panel.add(roleLabel);

        String[] roles = {"Student", "Admin"};
        JComboBox<String> roleBox = new JComboBox<>(roles);
        roleBox.setBounds(150, 130, 180, 30);
        panel.add(roleBox);

        JButton regButton = new JButton("Register");
        regButton.setBounds(150, 170, 100, 30);
        panel.add(regButton);

        regButton.addActionListener(e -> {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());
            String role = (String) roleBox.getSelectedItem();

            if (username.isEmpty() || password.isEmpty()) {
                JOptionPane.showMessageDialog(this, "Fields can't be empty");
                return;
            }

            try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
                PreparedStatement stmt = conn.prepareStatement("INSERT INTO users (username, password, role) VALUES (?, ?, ?)",
                PreparedStatement.RETURN_GENERATED_KEYS)) {

                stmt.setString(1, username);
                stmt.setString(2, password);
                stmt.setString(3, role);
                stmt.executeUpdate();

                ResultSet rs = stmt.getGeneratedKeys();
                int userId = -1;
                if (rs.next()) {
                    userId = rs.getInt(1);
                }

                if ("Student".equals(role) && userId != -1) {
                    String name = JOptionPane.showInputDialog(this, "Enter full name:");
                    String matric = JOptionPane.showInputDialog(this, "Enter matric number:");
                    String ageStr = JOptionPane.showInputDialog(this, "Enter age:");

                    int age;
                    try {
                        age = Integer.parseInt(ageStr);
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(this, "Invalid age entered.");
                        return;
                    }

                    // Default course_id = 1 for now
                    int courseId = 1;

                    String insertStudentSQL = "INSERT INTO students (name, Matric, age, course_id, user_id) VALUES (?, ?, ?, ?, ?)";
                    try (PreparedStatement studentStmt = conn.prepareStatement(insertStudentSQL)) {
                        studentStmt.setString(1, name);
                        studentStmt.setString(2, matric);
                        studentStmt.setInt(3, age);
                        studentStmt.setInt(4, courseId);
                        studentStmt.setInt(5, userId);
                        studentStmt.executeUpdate();
                    }
                }

                JOptionPane.showMessageDialog(this, "Registration Successful!");
                dispose();
                new LoginFrame().setVisible(true);

            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(this, "Registration Failed: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        add(panel);
    }
}