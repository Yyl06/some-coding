package Admin;

import java.awt.*;
import java.sql.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class ManageStudentPanel extends JPanel {
    private JTable studentTable;
    private DefaultTableModel tableModel;
    private JTextField nameField, matricField, ageField, courseIdField;

    public ManageStudentPanel() {
        setLayout(new BorderLayout());

        // Table setup
        tableModel = new DefaultTableModel(new String[]{"Student ID", "Name", "Matric", "Age", "Course ID"}, 0);
        studentTable = new JTable(tableModel);
        add(new JScrollPane(studentTable), BorderLayout.CENTER);

        // Input fields panel
        JPanel formPanel = new JPanel();
        formPanel.setLayout(new GridLayout(4, 2, 10, 10));
        nameField = new JTextField();
        matricField = new JTextField();
        ageField = new JTextField();
        courseIdField = new JTextField();

        formPanel.add(new JLabel("Name:"));
        formPanel.add(nameField);
        formPanel.add(new JLabel("Matric:"));
        formPanel.add(matricField);
        formPanel.add(new JLabel("Age:"));
        formPanel.add(ageField);
        formPanel.add(new JLabel("Course ID:"));
        formPanel.add(courseIdField);

        // Buttons panel
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton addButton = new JButton("Add Student");
        JButton removeButton = new JButton("Remove Selected");

        addButton.addActionListener(e -> addStudent());
        removeButton.addActionListener(e -> removeSelectedStudent());

        buttonPanel.add(addButton);
        buttonPanel.add(removeButton);

        // Combine form and buttons into bottom panel
        JPanel southPanel = new JPanel();
        southPanel.setLayout(new BorderLayout(10, 10));
        southPanel.add(formPanel, BorderLayout.CENTER);
        southPanel.add(buttonPanel, BorderLayout.SOUTH);

        add(southPanel, BorderLayout.SOUTH);
        loadStudents();
    }

    private void loadStudents() {
        tableModel.setRowCount(0);
        String sql = "SELECT * FROM students";

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                ArrayList<Object> row = new ArrayList<>();
                row.add(rs.getInt("student_id"));
                row.add(rs.getString("name"));
                row.add(rs.getString("Matric"));
                row.add(rs.getInt("age"));
                row.add(rs.getInt("course_id"));
                tableModel.addRow(row.toArray());
            }

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Error loading students: " + e.getMessage(), "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void addStudent() {
        String name = nameField.getText().trim();
        String matric = matricField.getText().trim();
        String ageText = ageField.getText().trim();
        String courseIdText = courseIdField.getText().trim();

        if (name.isEmpty() || matric.isEmpty() || ageText.isEmpty() || courseIdText.isEmpty()) {
            JOptionPane.showMessageDialog(this, "All fields must be filled.", "Validation Error", JOptionPane.WARNING_MESSAGE);
            return;
        }

        int age, courseId;
        try {
            age = Integer.parseInt(ageText);
            courseId = Integer.parseInt(courseIdText);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Age and Course ID must be numeric.", "Input Error", JOptionPane.WARNING_MESSAGE);
            return;
        }

        String sql = "INSERT INTO students (name, Matric, age, course_id) VALUES (?, ?, ?, ?)";

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, name);
            stmt.setString(2, matric);
            stmt.setInt(3, age);
            stmt.setInt(4, courseId);
            stmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "Student added successfully!");
            clearFormFields();
            loadStudents();

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to add student: " + e.getMessage(), "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void removeSelectedStudent() {
        int selectedRow = studentTable.getSelectedRow();

        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Select a student to remove.", "No Selection", JOptionPane.WARNING_MESSAGE);
            return;
        }

        int studentId = (int) tableModel.getValueAt(selectedRow, 0);
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to remove this student?", "Confirm Removal", JOptionPane.YES_NO_OPTION);

        if (confirm != JOptionPane.YES_OPTION) return;

        String sql = "DELETE FROM students WHERE student_id = ?";

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, studentId);
            stmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "Student removed successfully.");
            loadStudents();

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to remove student: " + e.getMessage(), "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void clearFormFields() {
        nameField.setText("");
        matricField.setText("");
        ageField.setText("");
        courseIdField.setText("");
    }
}
