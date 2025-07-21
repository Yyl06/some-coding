package Admin;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.SQLIntegrityConstraintViolationException;
import java.sql.Statement;
import java.sql.ResultSet;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

public class CoursePanel extends JPanel {
    JTable courseTable;
    DefaultTableModel tableModel;

    private JTextField nameField, codeField, capacityField;
    private JButton addButton;

    public CoursePanel() {
        setLayout(new BorderLayout());

        JTabbedPane tabs = new JTabbedPane();
        tabs.addTab("Add Course", addCourse());
        tabs.addTab("View Courses", viewCourse());
        tabs.addTab("Remove Course", removeCourse());
        add(tabs, BorderLayout.CENTER);
    }

    private JPanel addCourse(){
        JPanel panel = new JPanel(new GridLayout(5, 2, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 50, 20, 50));

        codeField = new JTextField();
        nameField = new JTextField();
        capacityField = new JTextField();
        JButton addButton = new JButton("Add Course");

        panel.add(new JLabel("Course Code: "));
        panel.add(codeField);
        panel.add(new JLabel("Course Name: "));
        panel.add(nameField);
        panel.add(new JLabel("Capacity: "));
        panel.add(capacityField);
        panel.add(new JLabel());
        panel.add(addButton);

        addButton.addActionListener(e -> {
            String name = nameField.getText().trim();
            String code = codeField.getText().trim();
            int capacity;

            try {
                capacity = Integer.parseInt(capacityField.getText().trim());
            } catch (NumberFormatException nfe) {
                JOptionPane.showMessageDialog(this, "Invalid Capacity! ", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            String sql = "INSERT INTO course (course_code, course_name, capacity) VALUES (?, ?, ?)";
            try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", ""); 
            PreparedStatement stmt = conn.prepareStatement(sql)) {
                stmt.setString(1, code);
                stmt.setString(2, name);
                stmt.setInt(3, capacity);
                stmt.executeUpdate();

                JOptionPane.showMessageDialog(this, "Course Addded Successfully!");
                refreshTable();

            } catch (SQLIntegrityConstraintViolationException dup) {
                JOptionPane.showMessageDialog(this, "Course code already exists!", "Duplicate Entry", JOptionPane.WARNING_MESSAGE);
            } catch (SQLException ex) {
                ex.printStackTrace();
                JOptionPane.showMessageDialog(this, "Database Error: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
        return panel;
    }

    private JPanel viewCourse(){
        JPanel panel = new JPanel(new BorderLayout());

        tableModel = new DefaultTableModel();
        tableModel.setColumnIdentifiers(new String[]{"Course ID", "Code", "Name", "Capacity"});

        courseTable = new JTable(tableModel);
        refreshTable();

        JScrollPane scrollPane = new JScrollPane(courseTable);
        panel.add(scrollPane, BorderLayout.CENTER);

        return panel;
    }

    private JPanel removeCourse(){
        JPanel panel = new JPanel(new BorderLayout());

        JButton deleteButton = new JButton("Delete Selected Course");

        tableModel = new DefaultTableModel();
        tableModel.setColumnIdentifiers(new String[]{"Course ID", "Code", "Name", "Capacity"});

        courseTable = new JTable(tableModel);
        refreshTable();

        deleteButton.addActionListener(e -> {
            int selected = courseTable.getSelectedRow();
            if(selected == -1){
                JOptionPane.showMessageDialog(this, "Select a Course to Delete.");
                return;
            }
            int courseId = (int) courseTable.getValueAt(selected, 0);
            int confirm = JOptionPane.showConfirmDialog(this, "Delete this Course?", "Confirm", JOptionPane.YES_NO_OPTION);
            if(confirm != JOptionPane.YES_OPTION){
                return;
            }

            String sql = "DELETE FROM course WHERE course_id = ?";

            try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
            PreparedStatement stmt = conn.prepareStatement(sql)){
                stmt.setInt(1, courseId);
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Course Deleted.");
                refreshTable();
            }catch(SQLException ex){
                JOptionPane.showMessageDialog(this, "Error Deleting Course.");
                ex.printStackTrace();
            }
        });
        panel.add(new JScrollPane(courseTable), BorderLayout.CENTER);
        panel.add(deleteButton, BorderLayout.SOUTH);

        return panel;
    }

    private void refreshTable(){
        if(tableModel == null) return;
        tableModel.setRowCount(0);

        String sql = "SELECT * FROM course";

        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(sql)){
            while(rs.next()){
                tableModel.addRow(new Object[]{
                    rs.getInt("course_id"),
                    rs.getString("course_code"),
                    rs.getString("course_name"),
                    rs.getInt("capacity")
                });
            }
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}