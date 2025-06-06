import java.sql.*;

public class MySQLConnection {
    public static void main(String[] args) {
        String host = "jdbc:mysql://localhost:3306/testDB";
        String username = "root";
        String password = "ihatemysql";
        try {
            Connection conn = DriverManager.getConnection(host, username, password);
            System.out.println("Connected to MySQL database");
        } catch (SQLException e) {
            System.out.println("Failed to connect to MySQL database");
            e.printStackTrace();
        }
    }
}