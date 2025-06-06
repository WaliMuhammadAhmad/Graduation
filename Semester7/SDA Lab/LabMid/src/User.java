import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class User {
    private String accountNumber;
    private String name;
    private double balance;
    // Composition
    private List<Transaction> transactions;

    public User(String accountNumber, String name, double balance) {
        this.accountNumber = accountNumber;
        this.name = name;
        this.balance = balance;
        this.transactions = new ArrayList<>();
    }

    public String getAccountNumber() {return accountNumber;}
    public String getName() {return name;}
    public double getBalance() {return balance;}
    public List<Transaction> getTransactions() {
        return transactions;
    }
    public void addTransaction(Transaction transaction) {
        transactions.add(transaction);
    }

    public void saveToDatabase(Connection conn) throws SQLException {
        String query = "INSERT INTO Accounts (account_number, name, balance) VALUES (?, ?, ?)";
        try (var stmt = conn.prepareStatement(query)) {
            stmt.setString(1, this.accountNumber);
            stmt.setString(2, this.name);
            stmt.setDouble(3, this.balance);
            stmt.executeUpdate();
        } catch (SQLException e) {
            Logger.logError("Error storing Users in Database : "+e.getMessage());
        }
    }
}

