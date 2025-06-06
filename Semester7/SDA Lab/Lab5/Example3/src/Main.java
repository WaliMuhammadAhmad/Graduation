import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            File file = new File("sample.txt");
            if (file.createNewFile()){
                System.out.println("File created : " + file.getName());
            }

            FileWriter writer = new FileWriter("sample.txt");
            writer.write("lorem ispum");
            writer.write("Java is actually bad!");
            writer.close();

            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()){
                String data = scanner.nextLine();
                System.out.println(data);
            }
            scanner.close();
        } catch (IOException e){
            System.out.println("Error occured while file handling!");
            e.printStackTrace();
        }
    }
}