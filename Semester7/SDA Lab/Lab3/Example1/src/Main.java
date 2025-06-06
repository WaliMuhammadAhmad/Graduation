public class Main {
    public static double larger(double a, double b){
        double max;

        if (a>=b){
            max=a;
        }
        else
            max=b;

        return max;
    }

    public static void main(String[] args) {
        System.out.println(larger(5,12));
    }
}