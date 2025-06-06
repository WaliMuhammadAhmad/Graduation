import java.io.FileWriter;
import java.io.IOException;

public class Logger {
    private static final String TRANSACTION_LOG_FILE = "transactions.log";
    private static final String ERROR_LOG_FILE = "error.log";

    public static void logTransaction(String message) {
        try (FileWriter fw = new FileWriter(TRANSACTION_LOG_FILE, true)) {
            fw.write(message + "\n");
        } catch (IOException e) {
            logError("Error writing to transaction log: " + e.getMessage());
        }
    }

    public static void logError(String message) {
        try (FileWriter fw = new FileWriter(ERROR_LOG_FILE, true)) {
            fw.write(message + "\n");
        } catch (IOException e) {
            System.err.println("Error writing to error log: " + e.getMessage());
        }
    }
}
