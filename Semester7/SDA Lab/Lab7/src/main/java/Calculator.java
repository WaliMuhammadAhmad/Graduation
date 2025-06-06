public class Calculator {
    public double add (double a, double b) { return a + b;
    }
    public double subtract (double a, double b) { return a-b;
    }
    public double multiply (double a, double b) {
        return a*b;
    }
    public double divide (double a, double b) throws ArithmeticException {
        if (b == 0) {
            throw new ArithmeticException("Division by zero is not allowed.");
        }
        return a/b;
    }
    public double power (double base, double exponent) {
        return Math.pow(base, exponent);
    }
    public double squareRoot(double a) throws IllegalArgumentException {
        if (a < 0) {
            throw new IllegalArgumentException("Square root of a negative number is not real.");
        }
        return Math.sqrt(a);
    }
}
