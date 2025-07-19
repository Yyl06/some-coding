package Student_Management.StudentManager;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import Student_Management.Course.Course;
import Student_Management.Student.Student;

public class StudentManager{
    private Connection conn;

    public StudentManager(){
        try{
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        }catch(SQLException e){
            System.err.println("Failed to connect to database: " + e.getMessage());
            System.err.println("Please check if MySQL server is running and database exists.");
            e.printStackTrace();
        }
    }

    public void addStudent(Student s){
        try {
            String sql = "INSERT INTO Students(student_id, name, matric, age, course_id) VALUES (?, ?, ?, ?, ?)";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1, s.getId());
            ps.setString(2, s.getName());
            ps.setString(3, s.getMatric());
            ps.setInt(4, s.getAge());
            ps.setInt(5, s.getCourse().getId());
            ps.executeUpdate();
            System.out.println("Student Added Sucessfully!");
        } catch(SQLException e){
            System.out.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public void removeStudent(int id){
        try {
            String sql = "DELETE FROM Students WHERE student_id = ?";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1, id);
            ps.executeUpdate();
            System.out.println("Student Removed Sucessfully!");
        } catch(SQLException e){
            System.out.println("Error: " + e.getMessage());
        }
    }

    public void displayAllStudents(){
        try {
            String sql = "SELECT s.student_id, s.name, s.matric, s.age, c.course_id, c.course_name " +
            "FROM students s JOIN course c ON s.course_id = c.course_id";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            while(rs.next()){
                Course course = new Course(rs.getInt("course_id"), rs.getString("course_name"));
                Student s = new Student(rs.getInt("student_id"), rs.getString("name"), rs.getString("matric"), rs.getInt("age"), course);
                s.displayInfo();
            }
        } catch (SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public Student findStudent(int id){
        try {
            String sql = "SELECT s.id, s.name, s.matric, s.age, c.course_id, c.course_name " +
            "FROM Students s JOIN course ON s.course_id = c.course_id";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1,id);
            ResultSet rs = ps.executeQuery();
            if(rs.next()){
                Course course = new Course(rs.getInt("course_id"), rs.getString("course_name"));
                Student s = new Student(rs.getInt("student_id"), rs.getString("name"), rs.getString("matric"), rs.getInt("age"), course);
                s.displayInfo();
                return s;
            }
        } catch (SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
        System.out.println("Student Not Found.");
        return null;
    }

    public Course findCourse(int id){
        try {
            String sql = "SELECT * FROM Course WHERE course_id = ?";
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1, id);
            ResultSet rs = ps.executeQuery();
            if(rs.next()){
                return new Course(rs.getInt("course_id"), rs.getString("course_name"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}
