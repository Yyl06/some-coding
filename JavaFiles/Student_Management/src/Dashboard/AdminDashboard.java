package Dashboard;

import Accounts.LoginFrame;
import Admin.CoursePanel;
import Admin.ManageStudentPanel;
import Admin.ViewStudentPanel;
import java.awt.BorderLayout;
import javax.swing.*;

public class AdminDashboard extends JFrame {
    public AdminDashboard() {
        setTitle("Admin Dashboard");
        setSize(800, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Tabbed navigation
        JTabbedPane tabbedPane = new JTabbedPane();
        tabbedPane.addTab("View Students", new ViewStudentPanel());
        tabbedPane.addTab("Manage Courses", new CoursePanel());
        tabbedPane.addTab("Manage Students", new ManageStudentPanel());

        // Logout Button at the bottom
        JButton logoutButton = new JButton("Logout");
        logoutButton.addActionListener(e -> {
            dispose();
            JOptionPane.showMessageDialog(null, "Logged Out.");
            new LoginFrame().setVisible(true);
        });

        JPanel bottomPanel = new JPanel();
        bottomPanel.add(logoutButton);

        // Add everything
        add(tabbedPane, BorderLayout.CENTER);
        add(bottomPanel, BorderLayout.SOUTH);
    }
}
