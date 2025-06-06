public class Main {
    public static void main(String[] args) {
        House house = new House("123 Main St, NYC");
        house.addRoom("Living Room");
        house.addRoom("Dining Room");
        house.addRoom("Gaming Room");
        house.addRoom("Studying Room");

        house.showHouse();
    }
}