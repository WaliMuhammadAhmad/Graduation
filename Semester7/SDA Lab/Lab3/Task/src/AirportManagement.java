public class AirportManagement {
    private String airportName;
    private String cityName;
    private String area;

    public AirportManagement(String airportName, String cityName, String area) {
        this.airportName = airportName;
        this.cityName = cityName;
        this.area = area;
    }

    public void open() {
        System.out.println("Airport is now open.");
    }

    // Getters
    public String getAirportName(){
        return  this.airportName;
    }
    public String getCityName(){
        return  this.cityName;
    }
    public String getArea(){
        return  this.area;
    }

    // Setters
    public void setAirportName(String airportName){
        this.airportName = airportName;
    }
    public void setCityName(String cityName){
        this.cityName = cityName;
    }
    public void setArea(String area){
        this.area = area;
    }
}
