package Task4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sin = new Scanner(System.in);

        System.out.println("Enter the original price of the item (in Rs.):");
        float originalPrice = sin.nextFloat();
        System.out.println("Enter the markup rate (in %):");
        float markupRate = sin.nextFloat();
        System.out.println("Enter the sales tax rate (in %):");
        float salesTaxRate = sin.nextFloat();

        System.out.println("Original Price = " + originalPrice + " Rs.");
        System.out.println("Markup Rate = " + markupRate + "%");
        float markupAmount = originalPrice * (markupRate / 100);
        System.out.printf("Markup Amount = %.2f Rs.\n", markupAmount);
        System.out.println("Sales Tax Rate = " + salesTaxRate + "%");
        float salesTaxAmount = originalPrice * (salesTaxRate / 100);
        System.out.printf("Sales Tax Amount = %.2f Rs.\n", salesTaxAmount);
        float finalPrice = originalPrice + markupAmount + salesTaxAmount;
        System.out.printf("Final Price = %.2f Rs.\n", finalPrice);
    }
}
