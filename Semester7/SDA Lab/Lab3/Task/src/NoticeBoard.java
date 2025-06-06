public class NoticeBoard {
    private int flightId;
    private String flightName;
    private String arrivalTime;
    private String departureTime;
    private String source;
    private String destination;

    public NoticeBoard(int flightId, String flightName, String arrivalTime, String departureTime, String source, String destination) {
        this.flightId = flightId;
        this.flightName = flightName;
        this.arrivalTime = arrivalTime;
        this.departureTime = departureTime;
        this.source = source;
        this.destination = destination;
    }
    // Notice Board display
    public void details() {
        System.out.println("Notice for Flight " + flightId + ": " + flightName + ", Arrival: " + arrivalTime + ", Departure: " + departureTime);
    }

    public void flightStatus() {
        System.out.println("Flight status: On time");
    }
}
