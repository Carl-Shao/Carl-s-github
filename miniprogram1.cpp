#include <iostream>
#include <cstring>

// create structure to store all information of shipments and packages
struct Date{
    int day;
    int month;
    int year;
};

struct Location{
    // C-string to store the location (city and country)
    char city[50];
    char country[50];
};

struct Package{
    char discription[100];
    double weight;
    double price;
};

struct ShipmentStatus{
    char disciption[100];
    Date updateDate;
    Location location;
};

struct Shipment{
    long ShipmentID;
    // a dynamically allocated array of packages
    Package* packages;
    int PackageNumber;
    Location SourceLocation;
    Location Destination;
    ShipmentStatus* shipmenthistory;
    int statusupdate;
    Date shipmentDate;
};

void cleanInput();
void inputDate(Date* date);
void inputLocation(Location* location);
void inputPackage(Package* package);
void inputShipment(Shipment* shipment);
void addPackage(Shipment* shipment);
void updateStatus(Shipment* shipment);
void displayShipment(const Shipment* shipment);
Shipment* searchShipmentByID(Shipment* shipments, int shipmentsNumber,int ID);
Shipment* searchShipmentByDes(Shipment* shipments, int shipmentsNumber,Location destination);
void deallocatedShipments(Shipment* shipments, int shipmentsNumber);

int main()
{
    std::cout << "====== Secure Logistics and Shipment Tracking System ======\n";
    int ShipmentNumber;
    std::cout << "Enter the number of shipment: ";
    while(!(std::cin >> ShipmentNumber) || ShipmentNumber < 0){
        std::cout << "Input Invalid ! Enter an integer again: ";
        cleanInput();
    }
    cleanInput();

    // a dynamically allocated array of shipments
    Shipment* shipments = new Shipment[ShipmentNumber];

    // enter information for shipments and packages
    for(int i = 0; i < ShipmentNumber; i++){
        std::cout << "Enter information for shipment " << (i + 1) << "\n";
        inputShipment(&shipments[i]);
        addPackage(&shipments[i]);
        updateStatus(&shipments[i]);
    }

    // display all the shipments
    std::cout << "\n------- All Shipments Display -------\n";
    for(int i = 0; i < ShipmentNumber; i++){
        displayShipment(&shipments[i]);
        std::cout << "--------------------------------------\n";
    }

    // Search shipment by ID and destination
    int section;
    while(1){
        std::cout << "\nSearch Way\n";
        std::cout << "1.Search by Shipment ID\n";
        std::cout << "2.Search by Shipment Destination\n";
        std::cout << "3.Exit the Search\n";
        std::cin >> section;

        // Search by shipment ID
        if(section == 1){
            int ID;
            std::cout << "Enter Shipment ID: ";
            std::cin >> ID;
            Shipment* found = searchShipmentByID(shipments, ShipmentNumber, ID);
            if(found){
                std::cout << "[Found By ID]\n";
                displayShipment(found);
            }
            else{
                std::cout << "Shipment ID " << ID << " is not found.\n";
            }
        }

        // Search shipment by destination
        else if(section == 2){
            Location destination;
            std::cout << "Enter Shipment Destination: ";
            std::cin.ignore();
            inputLocation(&destination);
            Shipment* found = searchShipmentByDes(shipments, ShipmentNumber, destination);
            if(found){
                std::cout << "[Found By Destination]\n";
                displayShipment(found);
            }
            else{
                std::cout << "No Shipment Destination is " << destination.city << "," << destination.country << "\n";
            }
        }

        // Exit Searching
        else if (section == 3){ break; }

        else{
            std::cout << "Invalid Selection! Try again: ";
        }
    }

    // Deallocated all the dynamic memory used pointer
    deallocatedShipments(shipments, ShipmentNumber);
    delete[] shipments;
    shipments = nullptr;

    return 0;
}

// to proper handling input
void cleanInput(){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void inputDate(Date* date){
    std::cout << "\nEnter the date: (day/month/year)";
    while(!(std::cin >> date->day >> date->month >> date->year)){
        std::cout << "\nInvalid Date Format! Try again: ";
        cleanInput();
    }
    cleanInput();
}

void inputLocation(Location* location){
    std::cout << "\nEnter city: ";
    std::cin.getline(location->city, sizeof(location->city));
    std::cout << "\nEnter country: ";
    std::cin.getline(location->country, sizeof(location->country));
}

void inputPackage(Package* package){
    std::cout << "Enter discription of the package: ";
    std::cin.getline(package->discription, sizeof(package->discription));
    std::cout << "Weight: ";
    while(!(std::cin >> package->weight) || package->weight < 0){
        std::cout << "Invalid weight input! Please enter again: ";
        cleanInput();
    }
    std::cout << "Price: ";
    while(!(std::cin >> package->price) || package->price < 0){
        std::cout << "Invald price input! Please enter again: ";
        cleanInput();
    }
    cleanInput();
}

// enter the basic information to the structure Shipment
void inputShipment(Shipment* shipment){
    std::cout << "Shipment ID: ";
    std::cin >> shipment->ShipmentID;

    std::cout << "Source Location: ";
    std::cin.ignore();
    inputLocation(&shipment->SourceLocation);

    std::cout << "Destination: ";
    inputLocation(&shipment->Destination);

    std::cout << "Shipment Date: ";
    inputDate(&shipment->shipmentDate);

    // initialize the package in the shipment
    shipment->PackageNumber = 0;
    shipment->packages = nullptr;
    shipment->shipmenthistory = nullptr;
    shipment->statusupdate = 0;
}

// enter every package information to the shipment
void addPackage(Shipment* shipment){
    int packageNum;
    std::cout << "How many package you wanna add: ";
    while(!(std::cin >> packageNum) || packageNum < 0){
        std::cout << "Invalid Package Number! Please enter again: ";
        cleanInput();
    }
    cleanInput();

    if (packageNum == 0){
        shipment->PackageNumber = 0;
        shipment->packages = nullptr;
        return;
    }

    shipment->packages = new Package[packageNum];
    shipment->PackageNumber = packageNum;

    for(int i = 0; i < packageNum; i++){
        std::cout << "\nPackage " << (i + 1) << "\n";
        // parameter the array name package as pointer to the function
        inputPackage(shipment->packages + i); 
    }
}

// update status information of package to the shipment
void updateStatus(Shipment* shipment){
    int updateNumber;
    std::cout << "How many status update do you have: ";
    while(!(std::cin >> updateNumber) || updateNumber < 0){
        std::cout << "Invalid Number of Package! Please enter again: ";
        cleanInput();
    }
    cleanInput();

    if(updateNumber == 0){
        shipment->shipmenthistory = nullptr;
        shipment->statusupdate = 0;
        return;
    }

    shipment->shipmenthistory = new ShipmentStatus[updateNumber];
    shipment->statusupdate = updateNumber;
    
    for(int i = 0; i < updateNumber; i++){
        std::cout << "\nStatus Update For The Package " << (i + 1) << ":\n";
        std::cout << "Enter the discription for the update status: ";
        std::cin.getline(shipment->shipmenthistory[i].disciption, sizeof(shipment->shipmenthistory[i].disciption));
        std::cout << "Update Location: ";
        inputLocation(&shipment->shipmenthistory[i].location);
        std::cout << "Update Date: ";
        inputDate(&shipment->shipmenthistory[i].updateDate);
    }
}

void displayShipment(const Shipment* shipment){
    std::cout << "Shipment ID: " << shipment->ShipmentID << "\n";
    std::cout << "Shipment Date: " << shipment->shipmentDate.year << "/"
              << shipment->shipmentDate.month << "/" << shipment->shipmentDate.day << "\n";
    std::cout << "Source Location: " << shipment->SourceLocation.city
              << "," << shipment->SourceLocation.country << "\n";
    std::cout << "Destination: " << shipment->Destination.city << "," << shipment->Destination.country << "\n";
    // display packages
    std::cout << shipment->PackageNumber << " Package\n";
    if (shipment->PackageNumber > 0){
        for(int i = 0; i < shipment->PackageNumber; i++){
            Package* p = shipment->packages + i;
            std::cout << "[" << (i + 1) << "]" << p->discription
                      << " | weight: " << p->weight << " kg"
                      << " | price: $" << p->price << "\n";
        }
    }
    else{
        std::cout << "No Package\n";
    }

    // display supdate status
    std::cout << shipment->statusupdate << "Status History\n";
    if(shipment->statusupdate > 0){
        for(int i = 0; i < shipment->statusupdate; i++){
            ShipmentStatus* status = shipment->shipmenthistory + i;
            std::cout << "[" << (i + 1) << "]" << status->disciption << "\n"
                      << "Location: " << status->location.city << "," << status->location.country << "\n"
                      << "Date: " << status->updateDate.year << "/" << status->updateDate.month
                      << "/" << status->updateDate.day << "\n";
        }
    }
    else{
        std::cout << "No status now\n";
    }
}

Shipment* searchShipmentByID(Shipment* shipments, int count,int ID){
    for(int i = 0; i < count; i++){
        if(shipments[i].ShipmentID == ID){
            return &shipments[i];
        }
    }
    return nullptr;
}

Shipment* searchShipmentByDes(Shipment* shipments, int count,Location destination){
    for(int i = 0; i < count; i++){
        if(strcmp(shipments[i].Destination.city, destination.city)){
            return &shipments[i];
        }
    }
    return nullptr;
}

void deallocatedShipments(Shipment* shipments, int shipmentsNumber){
    for(int i = 0; i < shipmentsNumber; i++){
        // deallocated packages
        if(shipments[i].packages != nullptr){
            delete[] shipments[i].packages;
            shipments[i].packages = nullptr;
        }

        // deallocated update status
        if(shipments[i].shipmenthistory != nullptr){
            delete[] shipments[i].shipmenthistory;
            shipments[i].shipmenthistory = nullptr;
        }
    }
}