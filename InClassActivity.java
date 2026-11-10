
// base class
class Vehicle {

    // member in class
    protected String brand;
    protected int year;

    // construct function
    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }

    public void displayInfo() {
        System.out.print("Brand: " + brand + ", Year: " + year);
    }
}

// Level 1 subclass
class Car extends Vehicle {
    protected int doors;

    // construct function of subclass
    public Car(String brand, int year, int doors) {
        super(brand, year);
        this.doors = doors;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.print(", Doors: " + doors);
    }
}

// Level 2 subclass
class ElectricCar extends Car {
    private int batteryCapacity;

    public ElectricCar(String brand, int years, int doors, int batteryCapacity) {
        super(brand, years, doors);
        this.batteryCapacity = batteryCapacity;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println(", Battery Capacity: " + batteryCapacity + " kWh");
    }
}

public class InClassActivity {
    public static void main(String[] args) {
        ElectricCar tesla = new ElectricCar("Tesla", 2024, 4, 85);
        tesla.displayInfo();
    }
}
