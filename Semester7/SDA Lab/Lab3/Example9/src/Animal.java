public interface Animal {
    void sound();

    default void sleep(){
        System.out.println("Animal is sleeping.");
    }
}
