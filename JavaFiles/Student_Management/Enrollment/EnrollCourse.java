package Student_Management.Enrollment;

import javax.swing.*;

import java.awt.*;
import java.sql.*;
import java.time.chrono.ThaiBuddhistChronology;
import java.util.ArrayList;

public class EnrollCourse extends JFrame{
    private int studentId;
    private JComboBox<String> courseComboBox;
    private ArrayList<Integer> courseIds = new ArrayList<>();

    public EnrollCourse(int studentId){
        this.studentId = studentId;

        setTitle("Enroll In Course");
        setSize(400,200);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JLabel label = new JLabel("Select a Course to Enroll:");
        courseComboBox = new JComboBox<>();

        JButton enrollButton = new JButton("Enroll");
        enrollButton.addActionListener(e->enrollInSelected());
        loadCourses();

        JPanel panel = new JPanel(new GridLayout(3, 1, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        panel.add(label);
        panel.add(courseComboBox);
        panel.add(enrollButton);

        add(panel);
        setVisible(true);
    }

    private void loadCourses(){
        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT course_id, course_name FROM course")){
            while(rs.next()){
                int id = rs.getInt("course_id");
                String name = rs.getString("course_name");
                courseIds.add(id);
                courseComboBox.addItem(name);
            }
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    private void enrollInSelected(){
        int index = courseComboBox.getSelectedIndex();
        if(index == -1){
            JOptionPane.showMessageDialog(this, "No Course Selected.");
            return;
        }

        int courseId = courseIds.get(index);

        String sql = "INSERT INTO enrollments(student_id, course_id) VALUES (?, ?)";
        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        PreparedStatement stmt = conn.prepareStatement(sql)){
            if(isAlreadyEnrolled(conn, studentId, courseId)){
                JOptionPane.showMessageDialog(this, "You are already enrolled in this course.");
                return;
            }

            stmt.setInt(1, studentId);
            stmt.setInt(2, courseId);
            stmt.executeUpdate();

            JOptionPane.showMessageDialog(this, "Enrolled Successfully!");
            dispose();
        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    private boolean isAlreadyEnrolled(Connection conn, int studentId, int courseId) throws SQLException{
        String checkSql = "SELECT * FROM enrollments WHERE student_id = ? AND course_id = ?";
        try(PreparedStatement checkStmt = conn.prepareStatement(checkSql)){
            checkStmt.setInt(1, studentId);
            checkStmt.setInt(2, courseId);
            ResultSet rs = checkStmt.executeQuery();
            return rs.next();
        }
    }
}
