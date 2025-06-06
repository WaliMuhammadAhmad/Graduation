import java.io.IOException;

public class Main{
    public static void methodA() throws IOException {
        methodB();
    }
    public static void methodB() throws IOException {
        throw new IOException("File not found");
    }

    public static void main(String[] args){
        try {
            methodA();
        } catch (IOException e){
            System.out.println("Exception handled in main "+e.getMessage());
        }
    }
}