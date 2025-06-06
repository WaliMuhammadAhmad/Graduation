public class Main {
    public static void main(String[] args) {
        Student std1 = new Student("Ali");
        Student std2 = new Student("Wali");

        Courses c1 = new Courses("NLP");
        Courses c2 = new Courses("CV");

        std1.enrollCourse(c1);
        std1.enrollCourse(c2);
        std2.enrollCourse(c1);

        c1.addStudent(std1);
        c2.addStudent(std2);
        c1.addStudent(std1);

        c1.showStudents();
        c2.showStudents();

        std1.showCourse();
        std2.showCourse();
    }
}