public class Car {
    String model;
    String color;
    int year;

    Car(String model, String color, int year){
        this.model=model;
        this.color=color;
        this.year=year;
    }

    void displayDetails(){
        System.out.println("Model :"+this.model);
        System.out.println("Color :"+this.color);
        System.out.println("Year :"+this.year);
    }
}
