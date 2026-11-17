public class Car implements Vehicle {


    private String brand;

    // construct function
    public Car(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return brand;
    }

    // Override function in interface class
    @Override
    public void startEngine() {
        System.out.println("The car engine is starting...");
    }

}
