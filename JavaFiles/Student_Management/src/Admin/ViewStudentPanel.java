package Admin;

import java.awt.*;
import java.sql.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

public class ViewStudentPanel extends JPanel {
    private JTable studentTable;
    private DefaultTableModel tableModel;
    private JTextField searchField;
    private JButton searchButton;

    public ViewStudentPanel() {
        setLayout(new BorderLayout(10, 10));
        setBorder(new EmptyBorder(10, 10, 10, 10)); // Padding

        // 🔍 Top Panel: Search Section
        JPanel topPanel = new JPanel(new GridBagLayout());
        topPanel.setBorder(BorderFactory.createTitledBorder("Search Student"));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5); // Margin between components

        JLabel searchLabel = new JLabel("Search (Username or ID):");
        searchField = new JTextField(20);
        searchButton = new JButton("Search");

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.WEST;
        topPanel.add(searchLabel, gbc);

        gbc.gridx = 1;
        topPanel.add(searchField, gbc);

        gbc.gridx = 2;
        topPanel.add(searchButton, gbc);

        add(topPanel, BorderLayout.NORTH);

        // 📋 Table for student data
        tableModel = new DefaultTableModel(
            new String[]{"Student ID", "Name", "Matric", "Age", "Course ID", "Username"}, 0
        );
        studentTable = new JTable(tableModel);
        studentTable.setFillsViewportHeight(true);
        studentTable.setRowHeight(24);
        studentTable.getTableHeader().setReorderingAllowed(false);

        JScrollPane scrollPane = new JScrollPane(studentTable);
        scrollPane.setBorder(BorderFactory.createTitledBorder("Student List"));
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        add(scrollPane, BorderLayout.CENTER);

        // 🔄 Load All Students initially
        loadStudentData("");

        // 🎯 Add ActionListener
        searchButton.addActionListener(e -> {
            String keyword = searchField.getText().trim();
            loadStudentData(keyword);
        });
    }

    private void loadStudentData(String keyword) {
        tableModel.setRowCount(0); // Clear existing rows

        String query;
        boolean isNumeric = keyword.matches("\\d+");

        if (keyword.isEmpty()) {
            query = """
                    SELECT s.student_id, s.name, s.Matric, s.age, s.course_id, u.username
                    FROM students s
                    JOIN users u ON s.student_id = u.user_id
                """;
        } else if (isNumeric) {
            query = """
                    SELECT s.student_id, s.name, s.Matric, s.age, s.course_id, u.username
                    FROM students s
                    JOIN users u ON s.student_id = u.user_id
                    WHERE s.student_id = ?
                """;
        } else {
            query = """
                    SELECT s.student_id, s.name, s.Matric, s.age, s.course_id, u.username
                    FROM students s
                    JOIN users u ON s.student_id = u.user_id
                    WHERE u.username LIKE ?
                """;
        }

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
             PreparedStatement stmt = conn.prepareStatement(query)) {

            if (!keyword.isEmpty()) {
                if (isNumeric) {
                    stmt.setInt(1, Integer.parseInt(keyword));
                } else {
                    stmt.setString(1, "%" + keyword + "%");
                }
            }

            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                Object[] row = {
                    rs.getInt("student_id"),
                    rs.getString("name"),
                    rs.getString("Matric"),
                    rs.getInt("age"),
                    rs.getInt("course_id"),
                    rs.getString("username")
                };
                tableModel.addRow(row);
            }

        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error loading students: " + e.getMessage(), "Database Error", JOptionPane.ERROR_MESSAGE);
        }
    }
}
