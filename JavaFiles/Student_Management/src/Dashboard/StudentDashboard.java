package Dashboard;

import Enrollment.EnrollCourse;
import Enrollment.ViewEnrolled;
import java.awt.*;
import java.sql.*;
import javax.swing.*;

public class StudentDashboard extends JFrame {

    private int studentId;

    public StudentDashboard(String username) {
        setTitle("Student Dashboard");
        setSize(450, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        studentId = fetchStudentId(username);

        // Title Label
        JLabel welcomeLabel = new JLabel("Welcome, " + username + "!", SwingConstants.CENTER);
        welcomeLabel.setFont(new Font("SansSerif", Font.BOLD, 20));
        welcomeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

        // Buttons
        JButton enrollButton = new JButton("Enroll in Course");
        JButton viewEnrollButton = new JButton("View Enrolled Courses");

        enrollButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        viewEnrollButton.setAlignmentX(Component.CENTER_ALIGNMENT);

        enrollButton.setPreferredSize(new Dimension(200, 40));
        viewEnrollButton.setPreferredSize(new Dimension(200, 40));

        enrollButton.addActionListener(e -> {
            if (studentId != -1) {
                new EnrollCourse(studentId).setVisible(true);
            } else {
                JOptionPane.showMessageDialog(this, "Student ID Not Found!");
            }
        });

        viewEnrollButton.addActionListener(e -> {
            if (studentId != -1) {
                new ViewEnrolled(studentId).setVisible(true);
            } else {
                JOptionPane.showMessageDialog(this, "Student ID Not Found!");
            }
        });

        // Panel with vertical layout
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBorder(BorderFactory.createEmptyBorder(30, 50, 30, 50));

        contentPanel.add(welcomeLabel);
        contentPanel.add(Box.createVerticalStrut(30));
        contentPanel.add(enrollButton);
        contentPanel.add(Box.createVerticalStrut(20));
        contentPanel.add(viewEnrollButton);

        add(contentPanel);
    }

    private int fetchStudentId(String username) {
        int id = -1;
        String query = """
            SELECT s.student_id
            FROM students s
            JOIN users u ON s.user_id = u.user_id
            WHERE u.username = ?
        """;

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(query)) {

            stmt.setString(1, username);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                id = rs.getInt("student_id");
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return id;
    }
}
