package Student_Management.Admin;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.*;
import java.util.Vector;
import java.util.jar.JarEntry;

public class ManageStudentPanel extends JPanel{
    private JTable studentTable;
    private DefaultTableModel tableModel;
    private JTextField nameField, matricField, ageField, courseIdField;

    public ManageStudentPanel(){
        setLayout(new BorderLayout());

        tableModel = new DefaultTableModel(new String[]{"Student ID", "Name", "Matric", "Age", "Course ID",}, 0);
        studentTable = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(studentTable);
        add(scrollPane, BorderLayout.CENTER);

        JPanel formPanel = new JPanel(new GridLayout(5, 2, 5, 5));
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

        JButton addButton = new JButton("Add Student");
        JButton removeButton = new JButton("Remove Selected");

        addButton.addActionListener(e -> addStudent());
        removeButton.addActionListener(e -> removeSelectedStudent());

        formPanel.add(addButton);
        formPanel.add(removeButton);

        add(formPanel, BorderLayout.SOUTH);

        loadStudents();
    }

    private void loadStudents(){
        tableModel.setRowCount(0);
        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM students")){
            while(rs.next()){
                Vector<Object> row = new Vector<>();
                row.add(rs.getInt("student_id"));
                row.add(rs.getString("name"));
                row.add(rs.getString("Matric"));
                row.add(rs.getInt("age"));
                row.add(rs.getInt("course_id"));
                tableModel.addRow(row);
            }
        }catch(SQLException e){
            JOptionPane.showMessageDialog(this, "Failed to load students: " + e.getMessage());
        }
    }

    private void addStudent(){
        String name = nameField.getText();
        String matric = matricField.getText();
        String ageText = ageField.getText();
        String courseIdText = courseIdField.getText();

        if(name.isEmpty() || matric.isEmpty() || ageText.isEmpty() || courseIdText.isEmpty()){
            JOptionPane.showMessageDialog(this, "Please Fill in All the Fields.");
            return;
        }

        try {
            int age = Integer.parseInt(ageText);
            int courseId = Integer.parseInt(courseIdText);

            try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
            PreparedStatement stmt = conn.prepareStatement("INSERT INTO Students (name, Matric, age, course_id) VALUES (?, ?, ?, ?)")){
                stmt.setString(1, name);
                stmt.setString(2, matric);
                stmt.setInt(3, age);
                stmt.setInt(4, courseId);
                stmt.executeUpdate();

                JOptionPane.showMessageDialog(this, "Student Added Successfully!");
                loadStudents();
            }catch(NumberFormatException nfe){
                JOptionPane.showMessageDialog(studentTable, "Age and Course must be numbers.");
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Failed to add Student: " + e.getMessage());
        }
    }

    private void removeSelectedStudent(){
        int SelectedRow = studentTable.getSelectedRow();
        if(SelectedRow == -1){
            JOptionPane.showMessageDialog(this, "Please Select a Student to Remove.");
            return;
        }

        int studentId = (int) tableModel.getValueAt(SelectedRow, 0);
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure want to remove this student?");
        if(confirm != JOptionPane.YES_OPTION) return;

        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        PreparedStatement stmt = conn.prepareStatement("DELETE FROM students where student_id = ?")){
            stmt.setInt(1, studentId);
            stmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Student removed successfully.");
            loadStudents();
        }catch(SQLException e){
            JOptionPane.showMessageDialog(this, "Failed to remove student" + e.getMessage());
        }
    }
}
