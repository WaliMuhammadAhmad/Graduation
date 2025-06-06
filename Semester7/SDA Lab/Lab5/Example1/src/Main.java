public class Main{
    public static void main(String[] args){
        try {
            int[] numbers= {1,2,3,4};
            System.out.println(numbers[5]);
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index out of Bounds");
        } finally {
            System.out.println("I'm gonna run!");
        }
    }
}