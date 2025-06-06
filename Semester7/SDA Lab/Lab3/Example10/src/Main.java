public class Main {
    public static void main(String[] args) {
        Teacher teacher = new Teacher("Ma'am Alina Munir");
        Classroom classroom = new Classroom("G-19",teacher);
        classroom.classDetail();
    }
}