public class Classroom {
    String roomNumber;
    Teacher t;

    Classroom(String roomNumber, Teacher teacher){
        this.roomNumber = roomNumber;
        this.t=teacher;
    }

    void classDetail(){
        System.out.println("Class is in "+this.roomNumber);
        t.teach();
    }
}
