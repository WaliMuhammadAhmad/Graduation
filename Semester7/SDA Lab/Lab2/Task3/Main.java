package Task3;

import java.util.Scanner;

public class Main {
    

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter 1st number of sequence:");
        int firstNum = input.nextInt();
        System.out.println("Enter 2nd number of sequence:");
        int secondNum = input.nextInt();
        System.out.println("Enter the limit of the sequence:");
        int limitOfSequence = input.nextInt();
        
        if(limitOfSequence >= 1){
            System.out.print(firstNum);
        }

        if(limitOfSequence >= 2){
            System.out.print(", " + secondNum);
        }

        for (int i = 0; i < limitOfSequence - 2; i++) {
            int total = firstNum + secondNum;
            System.out.print(", " + total);
            firstNum = secondNum;
            secondNum = total;
        }
    }
}
