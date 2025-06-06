public class Main {
    public static void main(String[] args) {
        AirportManagement airport = new AirportManagement("Allama Iqbal International", "Lahore", "Cantt");
        airport.open();

        TicketCounter ticketCounter = new TicketCounter(1, 101, "Lahore", "Montreal", 900.50, 909);
        ticketCounter.ticketDetails();
        ticketCounter.bookTicket();

        Passengers passenger = new Passengers(101, "Wali Muhammad", 19, 1, 1);
        passenger.passengerDetails();
        passenger.checkIn();

        Flight flight = new Flight(909, "Flight 909", 200, "10:00 AM", "1:00 PM", "Lahore", "Montreal", 900.50);
        flight.flightDetails();

        Luggage luggage = new Luggage(1, 101, 909, 2);
        luggage.luggageDetails();
        luggage.luggageStatus();

        Runway runway = new Runway(1, "Flight 909", false);
        runway.runwayDetails();
        System.out.println("Is runway occupied: " + runway.isOccupied());

        Employees emp1 = new AirportEmployees(1, "Ali", 50000, "Manager", "Operations");
        emp1.employeeDetails();

        Employees emp2 = new AirplaneEmployees(2, "Ahmad", 60000, "Pilot");
        emp2.employeeDetails();

        NoticeBoard noticeBoard = new NoticeBoard(201, "Flight 909", "9:00 AM", "10:00 AM", "Lahore", "Montreal");
        noticeBoard.details();
        noticeBoard.flightStatus();
    }
}