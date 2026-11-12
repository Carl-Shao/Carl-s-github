

// abstract class
abstract class Employee {
    protected String name;
    protected int id;

    // construct function
    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }


    public void displayInfo() {
        System.out.println("Employee ID: " + id + ", Name: " + name);
    }


    // abstract function
    public abstract double calculateSalary();
    public abstract double calculatePerformanceScore();
}

// subclass
class Manager extends Employee {

    protected double bonus;

    // Construct function
    Manager(String name, int id, double bonus) {
        super(name, id);
        this.bonus = bonus;
    }

    @Override
    public double calculateSalary() {
        return 5000 + bonus;
    }

    @Override
    public double calculatePerformanceScore() {
        return bonus / 100;
    }
}


class TeamLead extends Manager {

    private int teamSize;

    // construct function
    public TeamLead(String name, int id, double bonus, int teamSize) {
        super(name, id, bonus);
        this.teamSize = teamSize;
    }

    @Override
    public double calculateSalary() {
        // Manager salary + (teamSize * 100)
        return super.calculateSalary() + (teamSize * 100);
    }

    @Override
    public double calculatePerformanceScore() {
        // (bonus / 100) + (teamSize * 0.5)
        return (bonus / 100) + (teamSize * 0.5);
    }
}


public class Main {

    public static void main(String[] args) {
        // create array of employee
        Employee[] employees = new Employee[] {
                new Manager("Alice", 101, 2000),
                new TeamLead("Bob", 102, 2000, 7)
        };

        for (Employee emp : employees) {
            emp.displayInfo();
            System.out.println("Class: " + emp.getClass().getSimpleName());
            System.out.println("Salary: $" + emp.calculateSalary());
            System.out.println("Performance Score: " + emp.calculatePerformanceScore());
            System.out.println();
        }
    }
}
