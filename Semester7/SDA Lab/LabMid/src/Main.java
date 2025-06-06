import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/SimpleBankingSystem";
    private static final String USER = "root";
    private static final String PASS = "ihatemysql";

    public static void main(String[] args) {
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             Scanner scanner = new Scanner(System.in)) {
            String accountNumber;
            double balance;
            Bank bank = new Bank("Simple Bank");
            bank.getAlreadyUsers(conn);

            System.out.println("Welcome to " + bank.getName());

            while (true) {
                System.out.println("\n1. Create Account");
                System.out.println("2. Deposit");
                System.out.println("3. Withdraw");
                System.out.println("4. Current Balance");
                System.out.println("5. View User Transaction History");
                System.out.println("6. Exit");
                System.out.print("Choose an option: ");
                int choice = scanner.nextInt(); //  nextInt() is causing java.util.InputMismatchException error sometimes

                try {
                    switch (choice) {
                        case 1:
                            System.out.print("Enter account number: ");
                            accountNumber = scanner.next();
                            System.out.print("Enter name: ");
                            String name = scanner.next();
                            System.out.print("Enter initial balance: ");
                            balance = scanner.nextDouble();
                            try {
                                User user = new User(accountNumber, name, balance);
                                user.saveToDatabase(conn);
                                bank.addUser(user);
                                System.out.println("Account created successfully for " + name + ".");
                            } catch (SQLException e) {
                                Logger.logError("Error storing user : " + e.getMessage());
                                System.out.println("Failed to create account. Please try again.");
                            }
                            break;

                        case 2:
                            System.out.print("Enter account number: ");
                            accountNumber = scanner.next();
                            System.out.print("Enter deposit amount: ");
                            double depositAmount = scanner.nextDouble();

                            User depositUser = findUserByAccountNumber(bank, accountNumber);
                            if (depositUser != null) {
                                try {
                                    Transaction deposit = new Transaction("DEPOSIT", depositAmount, depositUser);
                                    deposit.saveToDatabase(conn);
                                    depositUser.addTransaction(deposit);
                                    balance = bank.getCurrentBalance(conn, accountNumber);
                                    System.out.println("Deposit of " + depositAmount + " successful. Current balance: " + balance);
                                } catch (Exception e) {
                                    System.out.println("Deposit failed: " + e.getMessage());
                                }
                            } else {
                                System.out.println("Account not found.");
                            }
                            break;

                        case 3:
                            System.out.print("Enter account number: ");
                            accountNumber = scanner.next();
                            System.out.print("Enter withdrawal amount: ");
                            double withdrawAmount = scanner.nextDouble();

                            User withdrawUser = findUserByAccountNumber(bank, accountNumber);
                            if (withdrawUser != null) {
                                try {
                                    Transaction withdrawal = new Transaction("WITHDRAWAL", withdrawAmount, withdrawUser);
                                    withdrawal.saveToDatabase(conn);
                                    withdrawUser.addTransaction(withdrawal);
                                    balance = bank.getCurrentBalance(conn, accountNumber);
                                    System.out.println("Withdrawal of " + withdrawAmount + " successful. Current balance: " + balance);
                                } catch (Exception e) {
                                    System.out.println("Withdrawal failed: " + e.getMessage());
                                }
                            } else {
                                System.out.println("Account not found.");
                            }
                            break;

                        case 4:
                            System.out.print("Enter account number: ");
                            accountNumber = scanner.next();
                            balance = bank.getCurrentBalance(conn, accountNumber);
                            if (balance != -1) {
                                System.out.println("Current balance for account " + accountNumber + " is: " + balance);
                            } else {
                                System.out.println("Unable to get balance.");
                            }
                            break;

                        case 5:
                            System.out.print("Enter account number: ");
                            accountNumber = scanner.next();

                            List<Transaction> userTransactions = bank.getAlreadyTransactions(conn, accountNumber);
                            if (!userTransactions.isEmpty()) {
                                System.out.println("Transaction History for account " + accountNumber + ":");
                                for (Transaction transaction : userTransactions) {
                                    System.out.println(transaction.getType() + " of " +
                                            transaction.getAmount() + " on " + transaction.getDate());
                                }
                            } else {
                                System.out.println("No transactions found for account " + accountNumber + ".");
                            }
                            break;

                        case 6:
                            System.out.println("Exiting...");
                            return;

                        default:
                            System.out.println("Wrong option. Try again.");
                    }
                } catch (Exception e) {
                    Logger.logError(e.getMessage());
                    System.out.println("Error: " + e.getMessage());
                }
            }
        } catch (SQLException e) {
            System.err.println("Database error");
            Logger.logError("Database connection error: " + e.getMessage());
        }
    }

    // utils
    private static User findUserByAccountNumber(Bank bank, String accountNumber) {
        for (User user : bank.getUsers()) {
            if (user.getAccountNumber().equals(accountNumber)) {
                return user;
            }
        }
        return null;
    }
}
