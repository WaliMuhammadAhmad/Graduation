public class AirportEmployees extends Employees {
    private String designation;
    private String department;

    public AirportEmployees(int employeeId, String employeeName, double employeeSalary, String designation, String department) {
        super(employeeId, employeeName, employeeSalary);
        this.designation = designation;
        this.department = department;
    }

    @Override
    public void employeeDetails() {
        System.out.println("Airport Employee: " + employeeName + ", Designation: " + designation + ", Department: " + department);
    }

    // Getters
    public String getDesignation(){
        return  this.designation;
    }
    public String getDepartment(){
        return  this.department;
    }

    // Setters
    public void setDesignation(String designation){
        this.designation = designation;
    }
    public void getDepartment(String department){
        this.department = department;
    }
}
