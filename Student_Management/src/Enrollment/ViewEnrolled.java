package Enrollment;

import java.awt.*;
import java.sql.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

public class ViewEnrolled extends JFrame {
    private int studentId;
    private JTable table;
    private JTextField searchField;
    private JButton searchBtn, dropCourseBtn;

    public ViewEnrolled(int studentId) {
        this.studentId = studentId;
        setTitle("📘 My Enrolled Courses");
        setSize(600, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        setLayout(new BorderLayout(10, 10));
        JPanel contentPane = new JPanel(new BorderLayout(10, 10));
        contentPane.setBorder(new EmptyBorder(10, 10, 10, 10));
        add(contentPane);

        // Top Panel
        JPanel topPanel = new JPanel();
        topPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        topPanel.add(new JLabel("🔍 Search:"));

        searchField = new JTextField(20);
        searchBtn = new JButton("Search");
        topPanel.add(searchField);
        topPanel.add(searchBtn);

        contentPane.add(topPanel, BorderLayout.NORTH);

        // Table Setup
        table = new JTable();
        table.setRowHeight(25);
        table.setFillsViewportHeight(true);
        table.setSelectionBackground(new Color(173, 216, 230)); // light blue
        table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        JScrollPane scrollPane = new JScrollPane(table);
        contentPane.add(scrollPane, BorderLayout.CENTER);

        // Bottom Panel
        dropCourseBtn = new JButton("❌ Drop Selected Course");
        JPanel bottomPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        bottomPanel.add(dropCourseBtn);

        contentPane.add(bottomPanel, BorderLayout.SOUTH);

        // Load Data
        loadEnrollCourses("");

        // Button Actions
        searchBtn.addActionListener(e -> {
            String keyword = searchField.getText().trim();
            loadEnrollCourses(keyword);
        });

        dropCourseBtn.addActionListener(e -> dropSelectedCourse());

        setVisible(true);
    }

    private void loadEnrollCourses(String keyword) {
        String[] columns = { "Course ID", "Course Code", "Course Name" };
        DefaultTableModel model = new DefaultTableModel(columns, 0);

        String sql = """
            SELECT c.course_id, c.course_code, c.course_name
            FROM enrollments e
            JOIN course c ON e.course_id = c.course_id
            WHERE e.student_id = ?
            AND (c.course_name LIKE ? OR c.course_code LIKE ?)
        """;

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, studentId);
            stmt.setString(2, "%" + keyword + "%");
            stmt.setString(3, "%" + keyword + "%");

            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                int id = rs.getInt("course_id");
                String code = rs.getString("course_code");
                String name = rs.getString("course_name");
                model.addRow(new Object[]{ id, code, name });
            }
            table.setModel(model);
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "❌ Failed to load enrolled courses.");
        }
    }

    private void dropSelectedCourse() {
        int selectedRow = table.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "⚠️ Please select a course to drop.");
            return;
        }

        int courseId = (int) table.getValueAt(selectedRow, 0);
        int confirm = JOptionPane.showConfirmDialog(this,
                "Are you sure you want to drop Course ID: " + courseId + "?",
                "Confirm Drop", JOptionPane.YES_NO_OPTION);

        if (confirm == JOptionPane.YES_OPTION) {
            String sql = "DELETE FROM enrollments WHERE student_id = ? AND course_id = ?";

            try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
                 PreparedStatement stmt = conn.prepareStatement(sql)) {

                stmt.setInt(1, studentId);
                stmt.setInt(2, courseId);
                int rowsAffected = stmt.executeUpdate();

                if (rowsAffected > 0) {
                    JOptionPane.showMessageDialog(this, "✅ Course dropped successfully.");
                    loadEnrollCourses(searchField.getText().trim());
                } else {
                    JOptionPane.showMessageDialog(this, "❌ Failed to drop course.");
                }
            } catch (SQLException e) {
                e.printStackTrace();
                JOptionPane.showMessageDialog(this, "⚠️ Database error occurred.");
            }
        }
    }
}
