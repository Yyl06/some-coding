package Student_Management.Accounts;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import Student_Management.Dashboard.AdminDashboard;
import Student_Management.Dashboard.StudentDashboard;
import Student_Management.Accounts.LoginFrame;


public class LoginFrame extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;

    public LoginFrame() {
        setTitle("Student Management System - Login");
        setSize(400, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(null);

        JLabel userLabel = new JLabel("Username: ");
        userLabel.setBounds(50, 40, 100, 30);
        panel.add(userLabel);

        usernameField = new JTextField();
        usernameField.setBounds(150, 40, 180, 30);
        panel.add(usernameField);

        JLabel passLabel = new JLabel("Password: ");
        passLabel.setBounds(50, 90, 100, 30);
        panel.add(passLabel);

        passwordField = new JPasswordField();
        passwordField.setBounds(150, 90, 180, 30);
        panel.add(passwordField);

        JButton loginButton = new JButton("Login");
        loginButton.setBounds(150, 140, 100, 30);
        panel.add(loginButton);

        JButton registerButton = new JButton("Register");
        registerButton.setBounds(260, 140, 100, 30);
        panel.add(registerButton);

        add(panel);
            

        loginButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String user = usernameField.getText();
                String pass = new String(passwordField.getPassword());
                String role = authenticateUser(user, pass);
                if(role != null){
                    JOptionPane.showMessageDialog(null, "Login Successful!");
                    dispose();

                    if(role.equals("Admin")){
                        new AdminDashboard().setVisible(true);
                    }else{
                        new StudentDashboard(user).setVisible(true);
                    }
                }else{
                    JOptionPane.showMessageDialog(null, "Invalid Username or Password.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        registerButton.addActionListener(e-> {
            dispose();
            new RegisterFrame().setVisible(true);
        });
    }

    public String authenticateUser(String username, String password){
        String sql = "SELECT password, role FROM users WHERE username = ?";

        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        PreparedStatement stmt = conn.prepareStatement(sql)){

            stmt.setString(1, username);
            ResultSet rs = stmt.executeQuery();

            if(rs.next()){
                String dbpass = rs.getString("password");
                if(password.equals(dbpass)){
                    return rs.getString("role");
                }
            }
        }catch(SQLException e){
            e.printStackTrace();
        }
        return null;
    }
}

