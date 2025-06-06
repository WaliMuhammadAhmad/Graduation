public class Main {
    public static void main(String[] args){
      try {
          int num = Integer.parseInt("WALI");
      } catch (NumberFormatException e){
          System.out.println("Invalid format");
      } catch (Exception e){
          System.out.println("An exception occured!");
      } finally {
          System.out.println("This block always run");
      }
    }
}