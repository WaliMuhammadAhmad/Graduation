public class Main {
    public static void main(String[] args) {
        Employee emp1 = new Employee("John","Professor");
        emp1.showEmployeeDetail();
        Employee emp2 = new Employee("Jack","Assistant Professor");
        emp2.showEmployeeDetail();

        Dept dept = new Dept("Computer Science");
        dept.addEmployee(emp1);
        dept.addEmployee(emp2);
        dept.showDeptDetail();
    }
}