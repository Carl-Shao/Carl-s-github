#include <iostream>
#include <string>

// Basic class
class Vehicle{
protected:
    std::string make;
    std::string model;
    int year;

public:

    // constructure the class of Vehicle
    Vehicle(const std::string make_r, const std::string model_r, int year_r):make(make_r), model(model_r), year(year_r){}
    
    // use virtual funciton to realize Polymorphism
    virtual std::string get_info() const {
        return "Make: " + make + ", Model: " + model + ", Year: " + std::to_string(year);
    }
};

// Derived class Car
class Car : public Vehicle{
private:
    // added member: the number of door
    short num_doors;

public:

    // constructure the class of Car
    Car(const std::string make_r, const std::string model_r, int year_r, short doorNumber):
    Vehicle(make_r, model_r, year_r), num_doors(doorNumber) {}

    // overloading the function get information
    std::string get_info() const {
        return Vehicle::get_info() + ", Door Number: " + std::to_string(num_doors);
    }
};

// Derived class Motocycle
class Motocycle : public Vehicle{
private:
    // added member: does it have side car
    bool has_sidecar;

public:
    // constructure the class of Motocycle
    Motocycle(const std::string make_r, const std::string model_r, int year_r, bool hasSideCar):
    Vehicle(make_r, model_r, year_r), has_sidecar(hasSideCar) {}

    // overloading the function get information
    std::string get_info() const {
        return Vehicle::get_info() + ", Has Sider: " + std::to_string(has_sidecar);
    }
};

// Derived class Truck
class Truck : public Vehicle{
private:
    // added member: capacity
    float cargo_capacity;

public:
    // constructure the class of Truck
    Truck(const std::string make_r, const std::string model_r, int year_r, float cargoCapacity):
    Vehicle(make_r, model_r, year_r), cargo_capacity(cargoCapacity) {}

    // overloading the function get information
    std::string get_info() const {
        return Vehicle::get_info() + ", Cargo Capacity: " + std::to_string(cargo_capacity);
    }
};

// overloading function to print information 
// this function recieve any pointer
void display_vehicle_info(const Vehicle& vehicle) {
    std::cout << "\n" << vehicle.get_info() << "\n\n";
}

void cleanInput();

int main(){
    short choice = 0;
    do {
        std::cout << "Welcome to Vehicle!\n";
        std::cout << "1.Car\n";
        std::cout << "2.Motocycle\n";
        std::cout << "3.Truck\n";
        std::cout << "4.Exit\n";
        std::cout << "Enter your choice:";
        while(!(std::cin >> choice || choice > 4 || choice < 1)) {
            std::cout << "Invalid Input! Try again.\n";
            cleanInput();
        }
        cleanInput();
        switch (choice)
        {
            // Initialize the class Car and print info
            case 1:{
                std::string make_car;
                std::cout << "Enter the make of Car: ";
                getline(std::cin, make_car);
                std::string model_car;
                std::cout << "Enter the model of Car: ";
                getline(std::cin, model_car);
                int year_car;
                std::cout << "Enter the year of Car: ";
                while(!(std::cin >> year_car) || year_car < 1000 || year_car > 2026) {
                    std::cout << "Invalid year! Try again.\n";
                    cleanInput();
                }
                cleanInput();
                short door_car;
                std::cout << "Enter the door number of Car: ";
                while(!(std::cin >> door_car) || door_car < 0 || door_car > 100) {
                    std::cout << "Invalid door number! Try again.\n";
                    cleanInput();
                }
                cleanInput();

                Car car(make_car, model_car, year_car, door_car);
                display_vehicle_info(car);

                break;
            }

            // Initialize class of Motocycle and print info
            case 2:{
                std::string make_moto;
                std::cout << "Enter the make of Motocycle: ";
                getline(std::cin, make_moto);
                std::string model_moto;
                std::cout << "Enter the model of Motocycle: ";
                getline(std::cin, model_moto);
                int year_moto;
                std::cout << "Enter the year of Motocycle: ";
                while(!(std::cin >> year_moto) || year_moto < 1000 || year_moto > 2026) {
                    std::cout << "Invalid year! Try again.\n";
                    cleanInput();
                }
                cleanInput();
                bool side_car;
                std::cout << "Enter whether there are side car: (true/false) ";
                while(!(std::cin >> std::boolalpha >> side_car)) {
                    std::cout << "Invalid! Try again.\n";
                    cleanInput();
                }
                cleanInput();

                Motocycle moto(make_moto, model_moto, year_moto, side_car);
                display_vehicle_info(moto);

                break;
            }

            // Initialize class of Truck and print info
            case 3:{
                std::string make_truck;
                std::cout << "Enter the make of Truck: ";
                getline(std::cin, make_truck);
                std::string model_truck;
                std::cout << "Enter the model of Truck: ";
                getline(std::cin, model_truck);
                int year_truck;
                std::cout << "Enter the year of Truck: ";
                while(!(std::cin >> year_truck) || year_truck < 1000 || year_truck > 2026) {
                    std::cout << "Invalid year! Try again.\n";
                    cleanInput();
                }
                cleanInput();
                float cargo;
                std::cout << "Enter thr cargo capacity of the Truck: ";
                while(!(std::cin >> cargo)) {
                    std::cout << "Invalid! Try again.\n";
                    cleanInput();
                }
                cleanInput();

                Truck truck(make_truck, model_truck, year_truck, cargo);
                display_vehicle_info(truck);

                break;
            }

            case 4:{
                std::cout << "Exit!\n";
                break;
            }

            default:{
                std::cout << "\nINVALID! Try again.\n\n";
                break;
            }
        }    
    } while(choice != 4);
    return 0;
}

// clean the cin when invalid variable enter
void cleanInput(){
    std::cin.clear();
    std::cin.ignore(1000000, '\n');
}
