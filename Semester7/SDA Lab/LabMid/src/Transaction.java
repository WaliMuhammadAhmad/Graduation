import java.sql.Connection;
import java.sql.*;

public class Transaction {
    private String type; // DEPOSIT or WITHDRAWAL
    private double amount;
    private String date;
    private User user;

    public Transaction(String type, double amount, User user) {
        this.type = type;
        this.amount = amount;
        this.user = user;
    }
    public Transaction(String type, double amount, String date) {
        this.type = type;
        this.amount = amount;
        this.date = date;
    }

    public String getType() { return type;}
    public double getAmount() {return amount;}
    public String getDate() {return date;}

    public void saveToDatabase(Connection conn) throws SQLException {
        String selectBalanceQuery = "SELECT balance FROM Accounts WHERE account_number = ?";
        String updateBalanceQuery = "UPDATE Accounts SET balance = ? WHERE account_number = ?";
        String insertTransactionQuery = "INSERT INTO Transactions (account_id, transaction_type, amount) " +
                "VALUES ((SELECT account_id FROM Accounts WHERE account_number = ?), ?, ?)";

        try (PreparedStatement selectStmt = conn.prepareStatement(selectBalanceQuery);
             PreparedStatement updateStmt = conn.prepareStatement(updateBalanceQuery);
             PreparedStatement insertStmt = conn.prepareStatement(insertTransactionQuery)) {

            selectStmt.setString(1, user.getAccountNumber());
            ResultSet rs = selectStmt.executeQuery();

            if (rs.next()) {
                double currentBalance = rs.getDouble("balance");
                double newBalance;

                // logic
                if ("DEPOSIT".equals(this.type)) {
                    if (this.amount <= 0) {
                        throw new IllegalArgumentException("Deposit amount must be greater than zero.");
                    }
                    newBalance = currentBalance + this.amount;
                } else if ("WITHDRAWAL".equals(this.type)) {
                    if (this.amount > currentBalance) {
                        throw new IllegalArgumentException("Insufficient funds for withdrawal.");
                    }
                    newBalance = currentBalance - this.amount;
                } else {
                    throw new IllegalArgumentException("Invalid transaction type.");
                }

                updateStmt.setDouble(1, newBalance);
                updateStmt.setString(2, user.getAccountNumber());
                updateStmt.executeUpdate();

                // Insert into the Transactions table also
                insertStmt.setString(1, user.getAccountNumber());
                insertStmt.setString(2, this.type);
                insertStmt.setDouble(3, this.amount);
                insertStmt.executeUpdate();

                Logger.logTransaction(this.type + " of " + this.amount + " for account " + user.getAccountNumber());
            } else {
                throw new IllegalArgumentException("Account not found for account number: " + user.getAccountNumber());
            }
        } catch (IllegalArgumentException e) {
            Logger.logError("Transaction failed: " + e.getMessage());
            throw e;
        } catch (SQLException e) {
            Logger.logError("Database error during transaction: " + e.getMessage());
            throw e;
        }
    }
}
