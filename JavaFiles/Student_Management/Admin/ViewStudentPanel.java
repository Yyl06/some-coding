package Student_Management.Admin;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

public class ViewStudentPanel extends JPanel{
    private JTable studentTable;
    private DefaultTableModel tableModel;
    private JTextField searchField;
    private JButton searchButton;

    public ViewStudentPanel(){
        setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout(FlowLayout.LEFT));

        searchField = new JTextField(20);
        searchButton = new JButton("Search");
        panel.add(new JLabel("Search (Username or ID)"));
        panel.add(searchField);
        panel.add(searchButton);

        add(panel, BorderLayout.NORTH);

        tableModel = new DefaultTableModel(new String[]{"Student ID", "Name", "Matric", "Age", "Course ID", "Username"}, 0);
        studentTable = new JTable(tableModel);
        add(new JScrollPane(studentTable), BorderLayout.CENTER);

        loadStudentData("");
        
        searchButton.addActionListener(e->{
            String keyword = searchField.getText().trim();
            loadStudentData(keyword);
        });
    }

    private void loadStudentData(String keyword) {
        tableModel.setRowCount(0);

        String query;
        boolean isNumeric = keyword.matches("\\d+");

        if(keyword.isEmpty()){
            query = """
            SELECT s.student_id, s.name, s.Matric, s.age, s.course_id, u.username
            FROM students s
            JOIN users u ON s.student_id = u.user_id
        """;
        }else if(isNumeric){
            query = """
            SELECT s.student_id, s.name, s.Matric, s.age, s.course_id, u.username
            FROM students s
            JOIN users u ON s.student_id = u.user_id
            WHERE s.student_id = ?
        """;
        }else{
            query = """
            SELECT s.student_id, s.name, s.Matric, s.age, s.course_id, u.username
            FROM students s
            JOIN users u ON s.student_id = u.user_id
            WHERE u.username LIKE ?
        """;
        }

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
            PreparedStatement stmt = conn.prepareStatement(query)) {

        if (!keyword.isEmpty()) {
            if (isNumeric) {
                stmt.setInt(1, Integer.parseInt(keyword));
            } else {
                stmt.setString(1, "%" + keyword + "%");
            }
        }

            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                Object[] row = {
                        rs.getInt("student_id"),
                        rs.getString("name"),
                        rs.getString("Matric"),
                        rs.getInt("age"),
                        rs.getInt("course_id"),
                        rs.getString("username")
                };
                tableModel.addRow(row);
            }
        }catch (SQLException e){
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error loading students: " + e.getMessage());
        }
    }
}