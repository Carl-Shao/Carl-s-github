public class Employee {

    private String firstName;

    private String lastName;

    private double monthlySalary;

    private static double raisePercentage;

    // Constructor Function
    Employee(String firstName, String lastName, double monthlySalary) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.monthlySalary = monthlySalary;
    }

    // GETTER function for each member
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public double getMonthlySalary() {
        return monthlySalary;
    }

    // static getter function
    public static double getRaisePercentage() {
        return raisePercentage;
    }

    // SETTER function for each member;
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setMonthlySalary(double monthlySalary) {
        // if month salary is not positive
        // set it to be 0.0
        if (monthlySalary < 0.0) {
            monthlySalary = 0.0;
        }
        this.monthlySalary = monthlySalary;
    }

    // static setter function
    public static void setRaisePercentage(double raisePercentage) {
        Employee.raisePercentage = raisePercentage;
    }

    public double getYearlySalary() {
        return monthlySalary * 12;
    }

    public void applyRaise() {
        setMonthlySalary(monthlySalary * (1 + raisePercentage / 100.0));
    }
}
