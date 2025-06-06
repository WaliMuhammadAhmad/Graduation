import java.util.ArrayList;
import java.util.List;

public class Dept {
    private String DepartmentName;
    private List<Employee> employees;

    Dept(String departmentName){
        this.DepartmentName = departmentName;
        this.employees = new ArrayList<>();
    }

    public void addEmployee(Employee em){
        employees.add(em);
    }

    public void showDeptDetail(){
        System.out.println("Department name:"+this.DepartmentName);
        for(Employee emp:employees){
            emp.showEmployeeDetail();
        }
    }
}
