public class CustomException {
    public  static void validateAge(int age) throws InvalidAge {
        throw new InvalidAge("Age must be 18!");
    }

    public static void main(String[] args){
        try{
            validateAge(16);
        } catch (InvalidAge e){
            System.out.println("Custom Exception"+ e.getMessage());
        }
    }
}
