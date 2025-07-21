package Student_Management.Enrollment;

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
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

public class ViewEnrolled extends JFrame{
    private int studentId;
    private JTable table;
    JTextField searchField = new JTextField(15);
    JButton searchBtn = new JButton("Search");
    JButton dropCourseBtn = new JButton("Drop Selected Course");

    public ViewEnrolled(int studentId){
        this.studentId = studentId;
        setTitle("My Enrolled Courses");
        setSize(500, 300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        table = new JTable();
        searchField = new JTextField(15);
        searchBtn = new JButton("Search");

        JPanel topPanel = new JPanel();
        topPanel.add(new JLabel("Search:"));
        topPanel.add(searchField);
        topPanel.add(searchBtn);
        add(topPanel, BorderLayout.NORTH);

        loadEnrollCourses("");

        searchBtn.addActionListener(e -> {
            String keyword = searchField.getText().trim();
            loadEnrollCourses(keyword);
        });

        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane, BorderLayout.CENTER);
        setVisible(true);

        dropCourseBtn.addActionListener(e -> dropSelectedCourse());
        JPanel bottomPanel = new JPanel();
        bottomPanel.add(dropCourseBtn);
        add(bottomPanel, BorderLayout.SOUTH);

    }

    private void loadEnrollCourses(String keyword){
        String[] columns = {"Course ID", "Course Name"};
        DefaultTableModel model = new DefaultTableModel(columns, 0);

        String sql = """
            SELECT c.course_id, c.course_code, c.course_name
            FROM enrollments e
            JOIN course c ON e.course_id = c.course_id
            WHERE e.student_id = ?
            AND (c.course_name LIKE ? OR c.course_code LIKE ?)
        """;

        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        PreparedStatement stmt = conn.prepareStatement(sql)){
            stmt.setInt(1, studentId);
            stmt.setString(2, "%" + keyword + "%");
            stmt.setString(3, "%" + keyword + "%");

            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                int id = rs.getInt("course_id");
                String code = rs.getString("course_code");
                String name = rs.getString("course_name");
                model.addRow(new Object[]{id, code, name});
            }
            table.setModel(model);
        }catch(SQLException e){
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to load Enrolled Courses.");
        }
    }

    private void dropSelectedCourse(){
        int selectedRow = table.getSelectedRow();
        if(selectedRow == -1){
            JOptionPane.showMessageDialog(this, "Please Select a course to Drop.");
            return;
        }

        int courseId = (int) table.getValueAt(selectedRow, 0);

        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to drop Course ID: " + courseId + "?",
        "Confirm Drop", JOptionPane.YES_NO_OPTION);
        if(confirm == JOptionPane.YES_OPTION){
            String sql = "DELETE FROM enrollments WHERE student_id = ? AND course_id = ?";
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
            PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, studentId);
            stmt.setInt(2, courseId);
            int rowsAffected = stmt.executeUpdate();
            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(this, "Course dropped successfully.");
                loadEnrollCourses(searchField.getText().trim());
            } else {
                JOptionPane.showMessageDialog(this, "Failed to drop course.");
            }
        }catch(SQLException e){
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Database error occurred.");
        }
    }
}
}