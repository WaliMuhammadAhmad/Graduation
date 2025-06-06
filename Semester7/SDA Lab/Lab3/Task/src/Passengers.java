public class Passengers {
    private int passengerId;
    private String passengerName;
    private int passengerAge;
    private int ticketId;
    private int luggageId;

    public Passengers(int passengerId, String passengerName, int passengerAge, int ticketId, int luggageId) {
        this.passengerId = passengerId;
        this.passengerName = passengerName;
        this.passengerAge = passengerAge;
        this.ticketId = ticketId;
        this.luggageId = luggageId;
    }

    public void passengerDetails() {
        System.out.println("Passenger: " + passengerName + ", Age: " + passengerAge);
    }

    public void checkIn() {
        System.out.println("Passenger checked in");
    }
}
