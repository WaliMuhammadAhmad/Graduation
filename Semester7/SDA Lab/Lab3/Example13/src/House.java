import java.util.ArrayList;
import java.util.List;

public class House {
    private String address;
    private List<Room> rooms;

    House(String add)
    {
        this.address = add;
        this.rooms = new ArrayList<>();
    }

    public void addRoom(String name){
        rooms.add(new Room(name));
    }

    public void showHouse(){
        System.out.println("House Location :"+this.address);
        for (Room r:rooms){
            r.showRoom();
        }
    }
}
