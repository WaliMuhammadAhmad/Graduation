import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Bank {
    private String name;
    // Aggregation
    private List<User> users;

    public Bank(String name) {
        this.name = name;
        this.users = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    public List<User> getUsers() {return users;}
    public String getName() {return this.name;}

    public void getAlreadyUsers(Connection conn) throws SQLException {
        String query = "SELECT account_number, name, balance FROM Accounts";
        try (PreparedStatement stmt = conn.prepareStatement(query);
             ResultSet rs = stmt.executeQuery()) {

            while (rs.next()) {
//                System.out.println(rs.getString("account_number"));
//                User user = new User(rs.getString("account_number"), rs.getString("account_number"), rs.getDouble("balance"));

                String accountNumber = rs.getString("account_number");
                String name = rs.getString("name");
                double balance = rs.getDouble("balance");
                User user = new User(accountNumber, name, balance);
                users.add(user);
            }

        } catch (SQLException e) {
            Logger.logError("Error fetching users from database: " + e.getMessage());
            System.out.println("Failed to fetch users from database.");
        }
    }

    public List<Transaction> getAlreadyTransactions(Connection conn, String accountNumber) {
        String query = "SELECT t.transaction_type, t.amount, t.transaction_date " +
                "FROM Transactions t JOIN Accounts a ON t.account_id = a.account_id " +
                "WHERE a.account_number = ?";
        List<Transaction> transactions = new ArrayList<>();
        try (PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, accountNumber);
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                String type = rs.getString("transaction_type");
                double amount = rs.getDouble("amount");
                String date = rs.getTimestamp("transaction_date").toString();
                transactions.add(new Transaction(type, amount, date));
            }
        } catch (SQLException e) {
            Logger.logError("Error fetching transactions for account: " + accountNumber + " - " + e.getMessage());
            System.err.println("Failed to fetch transactions.");
        }
        return transactions;
    }

    public double getCurrentBalance(Connection conn, String accountNumber) {
        String query = "SELECT balance FROM Accounts WHERE account_number = ?";
        try (PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, accountNumber);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                return rs.getDouble("balance");
            } else {
                System.out.println("Account not found for account number: " + accountNumber);
                Logger.logError("Attempted to fetch balance for non-existent account: " + accountNumber);
            }
        } catch (SQLException e) {
            Logger.logError("Error fetching balance for account: " + accountNumber + " - " + e.getMessage());
            System.err.println("Failed to fetch balance.");
        }
        return -1;
    }

}
