public class Luggage {
    private int luggageId;
    private int passengerId;
    private int flightId;
    private int numberOfLuggages;

    public Luggage(int luggageId, int passengerId, int flightId, int numberOfLuggages) {
        this.luggageId = luggageId;
        this.passengerId = passengerId;
        this.flightId = flightId;
        this.numberOfLuggages = numberOfLuggages;
    }

    public void luggageDetails() {
        System.out.println("Luggage: " + luggageId + ", Passenger: " + passengerId);
    }

    public void luggageStatus() {
        System.out.println("Luggage checked in");
    }
}
