
public class EmployeeTest {
    public static void main(String[] args) {
        // create object
        Employee employee1 = new Employee("Mike", "Jones", 2875.00);
        Employee employee2 = new Employee("Suzan", "Bob", 3150.75);

        // print detail of project
        System.out.printf("Employee 1: %s; Yearly Salary: %.2f%n",
                employee1, employee1.getYearlySalary());
        System.out.printf("Employee 2: %s; Yearly Salary: %.2f%n",
                employee2, employee2.getYearlySalary());

        // set raise and apply this change
        Employee.setRaisePercentage(10.0);

        employee1.applyRaise();
        employee2.applyRaise();

        System.out.println();
        System.out.println("Increasing employee salaries by " + Employee.getRaisePercentage() + "%");

        // print detail again
        System.out.printf("Employee 1: %s; Yearly Salary: %.2f%n",
                employee1, employee1.getYearlySalary());
        System.out.printf("Employee 2: %s; Yearly Salary: %.2f%n",
                employee2, employee2.getYearlySalary());
    }
}