import java.io.File;
import java.io.IOException;

public class Main {
    public  static void validateFile() throws IOException {
        File file = new File("sample.txt");
        if (!file.exists())
            throw new IOException("File doesnt exits!");

    }

    public static void main(String[] args){
        try{
            validateFile();
        } catch (IOException e){
            System.out.println("IOException occurred!");
        }
    }
}