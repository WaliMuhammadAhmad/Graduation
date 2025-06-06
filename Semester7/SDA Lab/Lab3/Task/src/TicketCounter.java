public class TicketCounter {
    private int ticketId;
    private int passengerId;
    private String source;
    private String destination;
    private double price;
    private int flightId;

    public TicketCounter(int ticketId, int passengerId, String source, String destination, double price, int flightId) {
        this.ticketId = ticketId;
        this.passengerId = passengerId;
        this.source = source;
        this.destination = destination;
        this.price = price;
        this.flightId = flightId;
    }

    public void ticketDetails() {
        System.out.println("Ticket Details: " + ticketId + ", Flight: " + flightId + ", Passenger: " + passengerId);
    }

    public void bookTicket() {
        System.out.println("Ticket booked for flight: " + flightId);
    }
}
