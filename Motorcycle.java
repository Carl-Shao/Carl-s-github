public class Motorcycle implements Vehicle {

    private String brand;


    // construct function
    public Motorcycle(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return brand;
    }

    // override function in interface
    @Override
    public void startEngine() {
        System.out.println("The motorcycle engine is starting...");
    }
}
