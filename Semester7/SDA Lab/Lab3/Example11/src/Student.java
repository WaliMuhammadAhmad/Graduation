import java.util.ArrayList;
import java.util.List;

public class Student {
    String name;
    List<Courses> courses;

    Student(String name){
        this.name=name;
        this.courses = new ArrayList<>();
    }

    void enrollCourse(Courses course){
        this.courses.add(course);
    }

    void showCourse(){
        System.out.println("Student name "+this.name);
        for(Courses course: courses){
            System.out.println("Course name " + course);
        }
    }
}
