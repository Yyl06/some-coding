package Dashboard;

import Accounts.LoginFrame;
import Admin.CoursePanel;
import Admin.ManageStudentPanel;
import Admin.ViewStudentPanel;
import java.awt.*;
import javax.swing.*;

public class AdminDashboard extends JFrame {

    public AdminDashboard() {
        setTitle("Admin Dashboard");
        setSize(900, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Main tab panel
        JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
        tabbedPane.setFont(new Font("Segoe UI", Font.PLAIN, 14));
        tabbedPane.addTab("View Students", new ViewStudentPanel());
        tabbedPane.addTab("Manage Courses", new CoursePanel());
        tabbedPane.addTab("Manage Students", new ManageStudentPanel());

        // Logout button
        JButton logoutButton = new JButton("Logout");
        logoutButton.setFocusPainted(false);
        logoutButton.setFont(new Font("Segoe UI", Font.BOLD, 14));
        logoutButton.addActionListener(e -> {
            dispose();
            JOptionPane.showMessageDialog(null, "Logged out successfully.");
            new LoginFrame().setVisible(true);
        });

        JPanel bottomPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        bottomPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        bottomPanel.add(logoutButton);

        // Layout
        setLayout(new BorderLayout(10, 10));
        add(tabbedPane, BorderLayout.CENTER);
        add(bottomPanel, BorderLayout.SOUTH);
    }
}
