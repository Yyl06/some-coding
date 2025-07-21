package Student_Management.Enrollment;

import javax.swing.JFrame;
import javax.swing.JTable;

public class ViewEnrolled extends JFrame{
    private int studentId;
    private JTable table;

    public ViewEnrolled(int studentId){
        this.studentId = studentId;
        setTitle("My Enrolled Courses");
        setSize(500, 300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        table = new JTable();
        loadEnrollCourses();
    }
}
