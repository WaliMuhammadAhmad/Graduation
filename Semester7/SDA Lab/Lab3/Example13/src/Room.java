public class Room {
    private String roomName;

    Room(String room){
        this.roomName = room;
    }

    public void showRoom(){
        System.out.println("Room Name: "+this.roomName);
    }
}
