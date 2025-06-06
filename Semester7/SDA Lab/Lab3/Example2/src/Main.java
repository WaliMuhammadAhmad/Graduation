public class Main {
    public static void printStarts(int blanks, int starsInLine){
        int count = 1;
        for(;count<=blanks;count++)
            System.out.print(" ");

        for(count = 1;count<=starsInLine;count++)
            System.out.print("*");

        System.out.println();
    }

    public static void main(String[] args) {
        printStarts(2,5);
    }
}