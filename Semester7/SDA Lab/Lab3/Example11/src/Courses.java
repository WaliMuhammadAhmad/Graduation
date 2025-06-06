import java.util.ArrayList;
import java.util.List;

public class Courses {
    String courseName;
    List<Student> students;

    Courses(String courseName){
        this.courseName = courseName;
        this.students = new ArrayList<>();
    }

    void addStudent(Student student){
        students.add(student);
    }

    void showStudents(){
        System.out.println("Course name : " + this.courseName);
        for(Student student: students){
            System.out.println("Student "+student.name);
        }
    }
}
