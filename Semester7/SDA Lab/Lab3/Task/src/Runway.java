public class Runway {
    private int runwayNumber;
    private String flightName;
    private boolean occupiedStatus;

    public Runway(int runwayNumber, String flightName, boolean occupiedStatus) {
        this.runwayNumber = runwayNumber;
        this.flightName = flightName;
        this.occupiedStatus = occupiedStatus;
    }

    public void runwayDetails() {
        System.out.println("Runway: " + runwayNumber + ", Flight: " + flightName);
    }

    public boolean isOccupied() {
        return occupiedStatus;
    }

    public int getRunwayNumber(){
        return this.runwayNumber;
    }
    public String getFlightName(){
        return this.flightName;
    }

    public void setRunwayNumber(int runwayNumber){
        this.runwayNumber = runwayNumber;
    }
    public void setFlightName(String flightName){
        this.flightName = flightName;
    }
}
