public class Main {
    public static void main(String[] args) {
        Animal animal = new Animal();
        animal.sound();
        Dog dog = new Dog();
        dog.sound();
        //Overloading
        Animal newDog = new Dog();
        newDog.sound();
    }
}