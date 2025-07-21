package Dashboard;

import java.awt.BorderLayout;
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
import javax.swing.SwingConstants;

import Enrollment.EnrollCourse;
import Enrollment.ViewEnrolled;

public class StudentDashboard extends JFrame {

    private int studentId;

    public StudentDashboard(String username) {
        setTitle("Student Dashboard");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        studentId = fetchStudentId(username);

        JLabel label = new JLabel("Welcome, " + username + "!", SwingConstants.CENTER);

        JButton enrollButton = new JButton("Enroll in Course");
        JButton viewEnrollButton = new JButton("View Enrolled Courses");

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

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(enrollButton);
        buttonPanel.add(viewEnrollButton);

        setLayout(new BorderLayout());
        add(label, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
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
