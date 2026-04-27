package Admin;

import java.awt.*;
import java.sql.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

public class CoursePanel extends JPanel {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/student";
    private static final String DB_USER = "root";
    private static final String DB_PASS = "";

    private JTable courseTable;
    private DefaultTableModel tableModel;

    private JTextField nameField, codeField, capacityField;

    public CoursePanel() {
        setLayout(new BorderLayout());

        // Setup Tabs
        JTabbedPane tabs = new JTabbedPane();
        tabs.addTab("➕ Add Course", createAddPanel());
        tabs.addTab("📋 View Courses", createViewPanel());
        tabs.addTab("❌ Remove Course", createDeletePanel());

        add(tabs, BorderLayout.CENTER);
    }

    private JPanel createAddPanel() {
        JPanel panel = new JPanel(new GridLayout(5, 2, 10, 10));
        panel.setBorder(new EmptyBorder(20, 50, 20, 50));

        nameField = new JTextField();
        codeField = new JTextField();
        capacityField = new JTextField();
        JButton addButton = new JButton("➕ Add Course");

        panel.add(new JLabel("Course Code:"));
        panel.add(codeField);
        panel.add(new JLabel("Course Name:"));
        panel.add(nameField);
        panel.add(new JLabel("Capacity:"));
        panel.add(capacityField);
        panel.add(new JLabel()); // Empty label for spacing
        panel.add(addButton);

        addButton.addActionListener(e -> addCourse());

        return panel;
    }

    private JPanel createViewPanel() {
        JPanel panel = new JPanel(new BorderLayout());
        setupTable();
        JScrollPane scrollPane = new JScrollPane(courseTable);
        panel.add(scrollPane, BorderLayout.CENTER);
        return panel;
    }

    private JPanel createDeletePanel() {
        JPanel panel = new JPanel(new BorderLayout());

        JButton deleteButton = new JButton("🗑 Delete Selected Course");
        setupTable();

        deleteButton.addActionListener(e -> deleteCourse());

        panel.add(new JScrollPane(courseTable), BorderLayout.CENTER);
        panel.add(deleteButton, BorderLayout.SOUTH);

        return panel;
    }

    private void setupTable() {
        if (tableModel == null) {
            tableModel = new DefaultTableModel(new String[]{"Course ID", "Code", "Name", "Capacity"}, 0);
            courseTable = new JTable(tableModel);
        }
        refreshTable();
    }

    private void addCourse() {
        String code = codeField.getText().trim();
        String name = nameField.getText().trim();
        String capacityStr = capacityField.getText().trim();

        if (code.isEmpty() || name.isEmpty() || capacityStr.isEmpty()) {
            JOptionPane.showMessageDialog(this, "All fields are required.", "Input Error", JOptionPane.WARNING_MESSAGE);
            return;
        }

        int capacity;
        try {
            capacity = Integer.parseInt(capacityStr);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Capacity must be a valid number.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String sql = "INSERT INTO course (course_code, course_name, capacity) VALUES (?, ?, ?)";
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, code);
            stmt.setString(2, name);
            stmt.setInt(3, capacity);
            stmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "✅ Course added successfully.");
            refreshTable();
            clearFields();

        } catch (SQLIntegrityConstraintViolationException dup) {
            JOptionPane.showMessageDialog(this, "❗ Course code already exists!", "Duplicate Entry", JOptionPane.WARNING_MESSAGE);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "❌ Database error:\n" + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            e.printStackTrace();
        }
    }

    private void deleteCourse() {
        int selectedRow = courseTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Please select a course to delete.");
            return;
        }

        int courseId = (int) tableModel.getValueAt(selectedRow, 0);
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to delete this course?", "Confirm", JOptionPane.YES_NO_OPTION);

        if (confirm != JOptionPane.YES_OPTION) return;

        String sql = "DELETE FROM course WHERE course_id = ?";
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, courseId);
            stmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "✅ Course deleted.");
            refreshTable();

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "❌ Error deleting course:\n" + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            e.printStackTrace();
        }
    }

    private void refreshTable() {
        if (tableModel == null) return;

        tableModel.setRowCount(0);

        String sql = "SELECT * FROM course";
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                tableModel.addRow(new Object[]{
                        rs.getInt("course_id"),
                        rs.getString("course_code"),
                        rs.getString("course_name"),
                        rs.getInt("capacity")
                });
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void clearFields() {
        nameField.setText("");
        codeField.setText("");
        capacityField.setText("");
    }
}
