public class Employee {
    String name;
    String Occupation;

    Employee(String name, String Occ){
        this.name = name;
        this.Occupation = Occ;
    }

    public void showEmployeeDetail(){
        System.out.println("Employee name: "+this.name);
        System.out.println("Employee occupation: "+this.Occupation);
    }
}
