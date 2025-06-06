public class Employees {
    protected int employeeId;
    protected String employeeName;
    protected double employeeSalary;

    public Employees(int employeeId, String employeeName, double employeeSalary) {
        this.employeeId = employeeId;
        this.employeeName = employeeName;
        this.employeeSalary = employeeSalary;
    }

    public void employeeDetails() {
        System.out.println("Employee: " + employeeName + ", Salary: " + employeeSalary);
    }

    // Getters
    public int getEmployeeId(){
        return  this.employeeId;
    }
    public String getEmployeeName(){
        return  this.employeeName;
    }
    public double getEmployeeSalary(){
        return this.employeeSalary;
    }

    // Setters
    public void setEmployeeId(int employeeId){
        this.employeeId = employeeId;
    }
    public void setEmployeeName(String employeeName){
        this.employeeName = employeeName;
    }
    public void setEmployeeSalary(double employeeSalary){
        this.employeeSalary = employeeSalary;
    }
}
