public class Vehicle {
    String model;
    String engine;

    Vehicle(String model, String engine){
        this.model = model;
        this.engine = engine;
    }

    public void start(){
        System.out.println(engine + " Started!");
    }
}
