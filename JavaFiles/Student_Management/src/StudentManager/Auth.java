package StudentManager;
import static Syntaxes.println.*;

import java.sql.*;

public class Auth {
    public String Authenticator(String username, String password){
        String query = "SELECT role FROM users WHERE username = ? AND password = ?";
        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student", "root", "");
        PreparedStatement stmt = conn.prepareStatement(query)){

            stmt.setString(1, username);
            stmt.setString(2, password);
            ResultSet rs = stmt.executeQuery();

            if(rs.next()){
                return rs.getString("role");
            }
        } catch (SQLException e){
            error("Login db Error" + e.getMessage());
        }
        return null;
    }
}
