public interface Vehicle {

    // Abstract method
    void startEngine();

    // default method
    default void stopEngine() {
        System.out.println("The vehicle engine is stopped.");
    }

    // static method
    static void displayVehicleInfo() {
        System.out.println("Vehicles are used for transportation.");
    }
}