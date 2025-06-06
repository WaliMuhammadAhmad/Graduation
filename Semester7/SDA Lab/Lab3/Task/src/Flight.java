public class Flight {
    private int flightId;
    private String flightName;
    private int capacity;
    private String startingTime;
    private String reachingTime;
    private String source;
    private String destination;
    private double price;

    public Flight(int flightId, String flightName, int capacity, String startingTime, String reachingTime, String source, String destination, double price) {
        this.flightId = flightId;
        this.flightName = flightName;
        this.capacity = capacity;
        this.startingTime = startingTime;
        this.reachingTime = reachingTime;
        this.source = source;
        this.destination = destination;
        this.price = price;
    }

    public void flightDetails() {
        System.out.println("Flight: " + flightId + " from " + source + " to " + destination);
    }
}
