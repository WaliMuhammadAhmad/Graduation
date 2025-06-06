package Task2;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);

        String filename;
        System.out.println("Enter the filename:");
        filename = input.nextLine();

        File file = new File(filename);

        if(!file.exists()){
            System.out.printf("%s not found", filename);
            return;
        }

        Scanner reader = new Scanner(new FileReader(file));
        int num, evenSum = 0, oddSum = 0;

        while(reader.hasNext()){
            num = reader.nextInt();

            if(num%2==0) evenSum += num;
            else oddSum += num;
        }

        reader.close();

        System.out.println("Even Sum: " + evenSum);
        System.out.println("Odd Sum: " + oddSum);
    }
}
