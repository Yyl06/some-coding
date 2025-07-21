package Student_Management.Dashboard;

import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import Student_Management.Admin.CoursePanel;
import Student_Management.Admin.ViewStudentPanel;
import Student_Management.Admin.ManageStudentPanel;


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
        JButton manageStudentButton = new JButton("Manage Students");
        JButton logOut = new JButton("Logout");

        panel.add(viewStudentsButton);
        panel.add(manageAllCourses);
        panel.add(manageStudentButton);
        panel.add(logOut);

        viewStudentsButton.addActionListener(e->{
            JFrame studentFrame = new JFrame("View Students");
            studentFrame.setSize(600, 300);
            studentFrame.setLocationRelativeTo(null);
            studentFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

            studentFrame.add(new ViewStudentPanel());
            studentFrame.setVisible(true);
        });

        manageAllCourses.addActionListener(e->{
            JFrame courseFrame = new JFrame("Course Management");
            courseFrame.setSize(600, 300);
            courseFrame.setLocationRelativeTo(null);
            courseFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

            courseFrame.add(new CoursePanel());
            courseFrame.setVisible(true);
        });

        manageStudentButton.addActionListener(e->{
            JFrame manageFrame = new JFrame("Manage Students");
            manageFrame.setSize(600, 300);
            manageFrame.setLocationRelativeTo(null);
            manageFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

            manageFrame.add(new ManageStudentPanel());
            manageFrame.setVisible(true);
        });


        logOut.addActionListener(e->{
            dispose();
            JOptionPane.showMessageDialog(null, "Logged Out.");
        });
        add(panel);
    }
}