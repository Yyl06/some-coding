package Accounts;

import java.awt.*;
import java.sql.*;
import javax.swing.*;

public class RegisterFrame extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JComboBox<String> roleBox;

    public RegisterFrame() {
        setTitle("User Registration");
        setSize(400, 270);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        String[] roles = {"Student", "Admin"};
        roleBox = new JComboBox<>(roles);
        usernameField = new JTextField(15);
        passwordField = new JPasswordField(15);
        JButton regButton = new JButton("Register");

        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.anchor = GridBagConstraints.WEST;

        gbc.gridx = 0; gbc.gridy = 0; panel.add(new JLabel("Username:"), gbc);
        gbc.gridx = 1; panel.add(usernameField, gbc);

        gbc.gridx = 0; gbc.gridy = 1; panel.add(new JLabel("Password:"), gbc);
        gbc.gridx = 1; panel.add(passwordField, gbc);

        gbc.gridx = 0; gbc.gridy = 2; panel.add(new JLabel("Role:"), gbc);
        gbc.gridx = 1; panel.add(roleBox, gbc);

        gbc.gridx = 1; gbc.gridy = 3;
        gbc.anchor = GridBagConstraints.CENTER;
        panel.add(regButton, gbc);

        regButton.addActionListener(e -> handleRegistration());

        add(panel);
    }

    private void handleRegistration() {
        String username = usernameField.getText().trim();
        String password = new String(passwordField.getPassword()).trim();
        String role = (String) roleBox.getSelectedItem();

        if (username.isEmpty() || password.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Fields can't be empty.");
            return;
        }

        if (username.length() < 3 || password.length() < 5) {
            JOptionPane.showMessageDialog(this, "Username or password too short.");
            return;
        }

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(
                     "INSERT INTO users (username, password, role) VALUES (?, ?, ?)", Statement.RETURN_GENERATED_KEYS)) {

            stmt.setString(1, username);
            stmt.setString(2, password);
            stmt.setString(3, role);
            stmt.executeUpdate();

            ResultSet rs = stmt.getGeneratedKeys();
            if (rs.next() && "Student".equals(role)) {
                int userId = rs.getInt(1);
                registerStudentDetails(conn, userId);
            }

            JOptionPane.showMessageDialog(this, "Registration successful!");
            dispose();
            new LoginFrame().setVisible(true);

        } catch (SQLIntegrityConstraintViolationException e) {
            JOptionPane.showMessageDialog(this, "Username already exists.", "Error", JOptionPane.ERROR_MESSAGE);
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Database error: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void registerStudentDetails(Connection conn, int userId) throws SQLException {
        String name = JOptionPane.showInputDialog(this, "Enter full name:");
        String matric = JOptionPane.showInputDialog(this, "Enter matric number:");
        String ageStr = JOptionPane.showInputDialog(this, "Enter age:");

        if (name == null || matric == null || ageStr == null) return;

        int age;
        try {
            age = Integer.parseInt(ageStr);
            if (age < 10 || age > 100) throw new NumberFormatException();
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Invalid age entered.");
            return;
        }

        int courseId = 1; // default

        String sql = "INSERT INTO students (name, Matric, age, course_id, user_id) VALUES (?, ?, ?, ?, ?)";
        try (PreparedStatement studentStmt = conn.prepareStatement(sql)) {
            studentStmt.setString(1, name);
            studentStmt.setString(2, matric);
            studentStmt.setInt(3, age);
            studentStmt.setInt(4, courseId);
            studentStmt.setInt(5, userId);
            studentStmt.executeUpdate();
        }
    }
}
