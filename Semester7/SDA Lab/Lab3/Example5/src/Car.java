class Car extends Vehicle{
    int door;
    int year;

    public Car(String model, String engine, int door){
        super(model, engine);
        this.door=door;
    }

    @Override
    public void start(){
        super.start();
        System.out.println("The car has " + door + " doors.");
    }
}
