package Task5;
import java.util.Scanner;

public class IncomeAndExpenditureCalculatorClass {
    private double payRate;
    private double totalHours;
    private double incomeBeforeTax;
    private double incomeAfterTax;
    private double remainingIncome;
    private double clothesAndAccessoriesAmount;
    private double schoolSuppliesAmount;
    private double savingsBondsAmount;
    private double parentsSavingsBondsAmount;

    private static final Scanner sin = new Scanner(System.in);
    private static final double taxRate = 0.14f;
    private static final double clothesAndAccessoriesRate = 0.10f;
    private static final double schoolSuppliesRate = 0.01f;
    private static final double savingsBondsRate = 0.25f;
    private static final double parentsSavingsBondsRate = 0.50f;

    public IncomeAndExpenditureCalculatorClass(){
        payRate = 0;
        totalHours = 0;
        incomeBeforeTax = 0;
        incomeAfterTax = 0;
        remainingIncome = 0;
        clothesAndAccessoriesAmount = 0;
        schoolSuppliesAmount = 0;
        savingsBondsAmount = 0;
        parentsSavingsBondsAmount = 0;
    }

    public void calculateAndDisplayResults() {
        inputHourlyRate();
        calculateIncome();
        calculateExpenditures();

        System.out.printf("Income before taxes: $%.2f%n", incomeBeforeTax);
        System.out.printf("Income after taxes: $%.2f%n", incomeAfterTax);
        System.out.printf("Money spent on clothes and accessories: $%.2f%n", clothesAndAccessoriesAmount);
        System.out.printf("Money spent on school supplies: $%.2f%n", schoolSuppliesAmount);
        System.out.printf("Money spent on savings bonds: $%.2f%n", savingsBondsAmount);
        System.out.printf("Money parents spend to buy additional savings bonds: $%.2f%n", parentsSavingsBondsAmount);
    }

    private void inputHourlyRate(){
        System.out.print("Enter your hourly pay rate: ");
        payRate = sin.nextDouble();

        for (int week = 1; week <= 5; week++) {
            System.out.print("Enter hours worked for week " + week + ": ");
            totalHours += sin.nextDouble();
        }

        sin.close();
    }

    private void calculateIncome(){
        incomeBeforeTax = payRate * totalHours;

        double taxAmount = taxRate * incomeBeforeTax;
        incomeAfterTax = incomeBeforeTax - taxAmount;
    }

    private void calculateExpenditures() {
        clothesAndAccessoriesAmount = clothesAndAccessoriesRate * incomeAfterTax;
        schoolSuppliesAmount = schoolSuppliesRate * incomeAfterTax;

        remainingIncome = incomeAfterTax - (clothesAndAccessoriesAmount + schoolSuppliesAmount);

        savingsBondsAmount = savingsBondsRate * remainingIncome;
        parentsSavingsBondsAmount = parentsSavingsBondsRate * savingsBondsAmount;
    }
}
