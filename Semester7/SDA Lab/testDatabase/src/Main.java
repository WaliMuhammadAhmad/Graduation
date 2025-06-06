import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class Main {
    private static final String URL = "jdbc:mysql://localhost:3306/testDB";
    private static final String USER = "root";
    private static final String PASSWORD = "ihatemysql";

    public static void main(String[] args) {
        try {
            // load and register JDBC driver for MySQL
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
            System.out.println("Connected to the database!");

            // Create operation
            String insertSQL = "INSERT INTO users (name, email) VALUES (?, ?)";
            PreparedStatement insertStatement = connection.prepareStatement(insertSQL);
            insertStatement.setString(1, "Mark Spencer");
            insertStatement.setString(2, "mark.spencer@example.com");
            int rowsInserted = insertStatement.executeUpdate();
            System.out.println(rowsInserted + " row(s) inserted.");
            insertStatement.close();

            // Read operation
            String selectSQL = "SELECT * FROM users";
            Statement selectStatement = connection.createStatement();
            ResultSet resultSet = selectStatement.executeQuery(selectSQL);
            System.out.println("Reading users from the database:");
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                String email = resultSet.getString("email");
                System.out.println("ID: " + id + ", Name: " + name + ", Email: " + email);
            }
            resultSet.close();
            selectStatement.close();

            // Update operation
            String updateSQL = "UPDATE users SET name = ? WHERE email = ?";
            PreparedStatement updateStatement = connection.prepareStatement(updateSQL);
            updateStatement.setString(1, "Mark S.");
            updateStatement.setString(2, "mark.spencer@example.com");
            int rowsUpdated = updateStatement.executeUpdate();
            System.out.println(rowsUpdated + " row(s) updated.");
            updateStatement.close();

            // Delete operation
            String deleteSQL = "DELETE FROM users WHERE email = ?";
            PreparedStatement deleteStatement = connection.prepareStatement(deleteSQL);
            deleteStatement.setString(1, "mark.spencer@example.com");
            int rowsDeleted = deleteStatement.executeUpdate();
            System.out.println(rowsDeleted + " row(s) deleted.");
            deleteStatement.close();

            connection.close();
            System.out.println("Database operations completed and connection closed.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
