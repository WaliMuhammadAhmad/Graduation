import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to the Calculator!");
        System.out.println("Choose an operation:");
        System.out.println("1: Addition\n2: Subtraction\n3: Multiplication\n4: Division"); System.out.println("5: Power\n");
        try {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: // Addition
                    System.out.print ("Enter two numbers: ");
                    System.out.println("Result: " + calculator.add(scanner.nextDouble(), scanner.nextDouble()));
                    break;
                case 2: // Subtraction
                    System.out.print("Enter two numbers: ");
                    System.out.println("Result: "+ calculator.subtract (scanner.nextDouble(), scanner.nextDouble()));
                    break;
                case 3: // Multiplication
                    System.out.print("Enter two numbers: ");
                    System.out.println("Result: " + calculator.multiply (scanner.nextDouble(), scanner.nextDouble()));
                    break;
                case 4: // Division
                    System.out.print("Enter two numbers: ");
                    System.out.println("Result: " + calculator.divide (scanner.nextDouble(), scanner.nextDouble()));
                    break;
                case 5: // Power
                    System.out.print("Enter base and exponent: ");
                    System.out.println("Result: " + calculator.power (scanner.nextDouble(), scanner.nextDouble()));
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
