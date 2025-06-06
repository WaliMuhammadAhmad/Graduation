public class AirplaneEmployees extends Employees {
    private String designation;

    public AirplaneEmployees(int employeeId, String employeeName, double employeeSalary, String designation) {
        super(employeeId, employeeName, employeeSalary);
        this.designation = designation;
    }

    @Override
    public void employeeDetails() {
        System.out.println("Airplane Employee: " + employeeName + ", Designation: " + designation);
    }

    // Getters
    public String getDesignation(){
        return  this.designation;
    }

    // Setters
    public void setDesignation(String designation){
        this.designation = designation;
    }
}
