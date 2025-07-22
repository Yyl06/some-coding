package Accounts;

import Dashboard.AdminDashboard;
import Dashboard.StudentDashboard;
import java.awt.*;
import java.sql.*;
import javax.swing.*;

public class LoginFrame extends JFrame {

    private JTextField usernameField;
    private JPasswordField passwordField;

    public LoginFrame() {
        setTitle("Student Management System - Login");
        setSize(420, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        JLabel userLabel = new JLabel("Username:");
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(userLabel, gbc);

        usernameField = new JTextField(20);
        gbc.gridx = 1;
        gbc.gridy = 0;
        panel.add(usernameField, gbc);

        JLabel passLabel = new JLabel("Password:");
        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(passLabel, gbc);

        passwordField = new JPasswordField(20);
        gbc.gridx = 1;
        gbc.gridy = 1;
        panel.add(passwordField, gbc);

        // Optional: Show Password Checkbox
        JCheckBox showPass = new JCheckBox("Show Password");
        gbc.gridx = 1;
        gbc.gridy = 2;
        panel.add(showPass, gbc);

        showPass.addActionListener(e -> {
            passwordField.setEchoChar(showPass.isSelected() ? (char) 0 : '•');
        });

        JButton loginButton = new JButton("Login");
        JButton registerButton = new JButton("Register");

        JPanel btnPanel = new JPanel();
        btnPanel.add(loginButton);
        btnPanel.add(registerButton);

        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 2;
        panel.add(btnPanel, gbc);

        add(panel);

        // Trigger login on Enter key
        passwordField.addActionListener(e -> loginAction());

        loginButton.addActionListener(e -> loginAction());
        registerButton.addActionListener(e -> {
            dispose();
            new RegisterFrame().setVisible(true);
        });
    }

    private void loginAction() {
        String user = usernameField.getText().trim();
        String pass = new String(passwordField.getPassword()).trim();
        String role = authenticateUser(user, pass);

        if (role != null) {
            JOptionPane.showMessageDialog(this, "Login Successful!");
            dispose();

            if (role.equalsIgnoreCase("Admin")) {
                new AdminDashboard().setVisible(true);
            } else {
                new StudentDashboard(user).setVisible(true);
            }
        } else {
            JOptionPane.showMessageDialog(this, "Invalid username or password.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public String authenticateUser(String username, String password) {
        String sql = "SELECT password, role FROM users WHERE username = ?";

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                String dbPass = rs.getString("password");
                if (password.equals(dbPass)) {
                    return rs.getString("role");
                }
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Database Error: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
        return null;
    }
}
