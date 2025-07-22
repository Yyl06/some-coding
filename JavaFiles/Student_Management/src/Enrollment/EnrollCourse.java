package Enrollment;

import java.awt.*;
import java.sql.*;
import java.util.ArrayList;
import javax.swing.*;

public class EnrollCourse extends JFrame {
    private int studentId;
    private JComboBox<String> courseComboBox;
    private ArrayList<Integer> courseIds = new ArrayList<>();

    public EnrollCourse(int studentId) {
        this.studentId = studentId;

        setTitle("📘 Enroll in Course");
        setSize(450, 250);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        // Main panel with padding
        JPanel mainPanel = new JPanel();
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 25, 20, 25));
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));

        // Label with bigger font
        JLabel label = new JLabel("Select a Course to Enroll:");
        label.setFont(new Font("SansSerif", Font.BOLD, 16));
        label.setAlignmentX(Component.CENTER_ALIGNMENT);

        courseComboBox = new JComboBox<>();
        courseComboBox.setFont(new Font("SansSerif", Font.PLAIN, 14));
        courseComboBox.setMaximumSize(new Dimension(300, 30));

        JButton enrollButton = new JButton("✅ Enroll");
        enrollButton.setBackground(new Color(0, 120, 215));
        enrollButton.setForeground(Color.WHITE);
        enrollButton.setFocusPainted(false);
        enrollButton.setFont(new Font("SansSerif", Font.BOLD, 14));
        enrollButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        enrollButton.setPreferredSize(new Dimension(200, 40));
        enrollButton.addActionListener(e -> enrollInSelected());

        // Load courses into combo box
        loadCourses();

        // Add components to panel
        mainPanel.add(label);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        mainPanel.add(courseComboBox);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        mainPanel.add(enrollButton);

        // Add to frame
        add(mainPanel);
        setVisible(true);
    }

    private void loadCourses() {
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT course_id, course_name FROM course")) {
            while (rs.next()) {
                int id = rs.getInt("course_id");
                String name = rs.getString("course_name");
                courseIds.add(id);
                courseComboBox.addItem(name);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error loading courses: " + e.getMessage());
        }
    }

    private void enrollInSelected() {
        int index = courseComboBox.getSelectedIndex();
        if (index == -1) {
            JOptionPane.showMessageDialog(this, "❌ No course selected.");
            return;
        }

        int courseId = courseIds.get(index);
        String sql = "INSERT INTO enrollments(student_id, course_id) VALUES (?, ?)";

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            if (isAlreadyEnrolled(conn, studentId, courseId)) {
                JOptionPane.showMessageDialog(this, "⚠️ You are already enrolled in this course.");
                return;
            }

            stmt.setInt(1, studentId);
            stmt.setInt(2, courseId);
            stmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "✅ Enrolled successfully!");
            dispose();
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error enrolling in course: " + e.getMessage());
        }
    }

    private boolean isAlreadyEnrolled(Connection conn, int studentId, int courseId) throws SQLException {
        String checkSql = "SELECT * FROM enrollments WHERE student_id = ? AND course_id = ?";
        try (PreparedStatement checkStmt = conn.prepareStatement(checkSql)) {
            checkStmt.setInt(1, studentId);
            checkStmt.setInt(2, courseId);
            ResultSet rs = checkStmt.executeQuery();
            return rs.next();
        }
    }
}
