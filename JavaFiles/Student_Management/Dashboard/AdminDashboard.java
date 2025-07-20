package Student_Management.Dashboard;

import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import Student_Management.Admin.CoursePanel;


public class AdminDashboard extends JFrame{
    public AdminDashboard(){
        setTitle("Admin Dashboard");
        setSize(400,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 1, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(30, 50, 30, 50));

        JButton viewStudentsButton = new JButton("View All Students");
        JButton manageAllCourses = new JButton("Manage Courses");
        JButton addStudentButton = new JButton("Add New Student");
        JButton removeStudentButton = new JButton("Remove Student");
        JButton logOut = new JButton("Logout");

        panel.add(viewStudentsButton);
        panel.add(manageAllCourses);
        panel.add(addStudentButton);
        panel.add(removeStudentButton);
        panel.add(logOut);

        manageAllCourses.addActionListener(e->{
            JFrame courseFrame = new JFrame("Course Management");
            courseFrame.setSize(600, 300);
            courseFrame.setLocationRelativeTo(null);
            courseFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

            courseFrame.add(new CoursePanel());
            courseFrame.setVisible(true);
        });


        logOut.addActionListener(e->{
            dispose();
            JOptionPane.showMessageDialog(null, "Logged Out.");
        });
        add(panel);
    }
}