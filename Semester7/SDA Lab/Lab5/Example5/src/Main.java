import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args){
        try(FileWriter writer = new FileWriter("sample.txt")) {
            writer.write("Java is actually bad!");
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}