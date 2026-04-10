// Secure Logistics and Shipment Tracking System
// Mini-Project 1 - C++ Implementation (No STL, No std::string)
// Author: Top Programmer
// Date: 2026-03-24

#include <iostream>
#include <cstring> // for strcpy, strcmp, strlen
using namespace std;

// Structure definitions as per requirements

struct Date {
    int day;
    int month;
    int year;
};

struct Location {
    char city[50];
    char country[50];
};

struct Package {
    char description[100];
    double weight;   // in kg
    double value;    // in USD
};

struct ShipmentStatus {
    char statusDesc[30]; // e.g., "Pending", "Shipped", "Delivered"
    Date updateDate;
    Location location;
};

struct Shipment {
    int shipmentID;
    Package* packages;           // dynamically allocated array
    int numPackages;
    Location source;
    Location destination;
    ShipmentStatus* statusHistory; // dynamically allocated array
    int numStatusUpdates;
    Date shipmentDate;
};

// Function declarations
void inputDate(Date* d);
void inputLocation(Location* loc);
void inputPackage(Package* pkg);
void inputShipment(Shipment* s);
void addPackagesToShipment(Shipment* s);
void addStatusUpdates(Shipment* s);
void displayShipment(const Shipment* s);
Shipment* searchByShipmentID(Shipment* shipments, int count, int id);
Shipment* searchByDestinationCity(Shipment* shipments, int count, const char* city);
void deallocateShipments(Shipment* shipments, int count);

// Helper functions
void clearInputBuffer();

int main() {
    cout << "=== Secure Logistics and Shipment Tracking System ===" << endl;

    int numShipments;
    cout << "Enter number of shipments: ";
    while (!(cin >> numShipments) || numShipments <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
        clearInputBuffer();
    }
    clearInputBuffer(); // consume newline

    // Dynamically allocate array of shipments
    Shipment* shipments = new Shipment[numShipments];

    // Input each shipment
    for (int i = 0; i < numShipments; ++i) {
        cout << "\n--- Entering details for Shipment #" << (i + 1) << " ---" << endl;
        inputShipment(&shipments[i]);
        addPackagesToShipment(&shipments[i]);
        addStatusUpdates(&shipments[i]);
    }

    // Display all shipments
    cout << "\n\n=== All Shipments ===" << endl;
    for (int i = 0; i < numShipments; ++i) {
        displayShipment(&shipments[i]);
        cout << "----------------------------------------\n";
    }

    // Search functionality
    int choice;
    do {
        cout << "\nSearch Options:\n";
        cout << "1. Search by Shipment ID\n";
        cout << "2. Search by Destination City\n";
        cout << "3. Exit Search\n";
        cout << "Choose an option: ";
        cin >> choice;
        clearInputBuffer();

        if (choice == 1) {
            int id;
            cout << "Enter Shipment ID: ";
            cin >> id;
            clearInputBuffer();
            Shipment* found = searchByShipmentID(shipments, numShipments, id);
            if (found) {
                cout << "\n[Found by ID]\n";
                displayShipment(found);
            } else {
                cout << "Shipment with ID " << id << " not found.\n";
            }
        }
        else if (choice == 2) {
            char city[50];
            cout << "Enter Destination City: ";
            cin.getline(city, sizeof(city));
            Shipment* found = searchByDestinationCity(shipments, numShipments, city);
            if (found) {
                cout << "\n[Found by Destination City '" << city << "']\n";
                displayShipment(found);
            } else {
                cout << "No shipment found with destination city '" << city << "'.\n";
            }
        }
        else if (choice != 3) {
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    // Deallocate all memory
    deallocateShipments(shipments, numShipments);
    delete[] shipments;
    shipments = nullptr;

    cout << "\nAll memory deallocated. Program ended safely.\n";
    return 0;
}

// ------------------ FUNCTION IMPLEMENTATIONS ------------------

void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

void inputDate(Date* d) {
    cout << "  Enter date (DD MM YYYY): ";
    while (!(cin >> d->day >> d->month >> d->year)) {
        cout << "  Invalid date format. Try again (DD MM YYYY): ";
        clearInputBuffer();
    }
    clearInputBuffer();
}

void inputLocation(Location* loc) {
    cout << "  Enter city: ";
    cin.getline(loc->city, sizeof(loc->city));
    cout << "  Enter country: ";
    cin.getline(loc->country, sizeof(loc->country));
}

void inputPackage(Package* pkg) {
    cout << "    Description: ";
    cin.getline(pkg->description, sizeof(pkg->description));
    cout << "    Weight (kg): ";
    while (!(cin >> pkg->weight) || pkg->weight < 0) {
        cout << "    Invalid weight. Enter non-negative number: ";
        clearInputBuffer();
    }
    cout << "    Value (USD): ";
    while (!(cin >> pkg->value) || pkg->value < 0) {
        cout << "    Invalid value. Enter non-negative number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
}

void inputShipment(Shipment* s) {
    cout << "Shipment ID: ";
    cin >> s->shipmentID;
    clearInputBuffer();

    cout << "Source Location:\n";
    inputLocation(&s->source);

    cout << "Destination Location:\n";
    inputLocation(&s->destination);

    cout << "Shipment Date:\n";
    inputDate(&s->shipmentDate);

    s->numPackages = 0;
    s->packages = nullptr;
    s->numStatusUpdates = 0;
    s->statusHistory = nullptr;
}

void addPackagesToShipment(Shipment* s) {
    int n;
    cout << "How many packages to add? ";
    while (!(cin >> n) || n < 0) {
        cout << "Invalid number. Enter non-negative integer: ";
        clearInputBuffer();
    }
    clearInputBuffer();

    if (n == 0) {
        s->packages = nullptr;
        s->numPackages = 0;
        return;
    }

    // Allocate dynamic array
    s->packages = new Package[n];
    s->numPackages = n;

    // Use pointer arithmetic to fill packages
    for (int i = 0; i < n; ++i) {
        cout << "\nPackage #" << (i + 1) << ":\n";
        // Equivalent to &s->packages[i], but using pointer arithmetic
        inputPackage(s->packages + i);
    }
}

void addStatusUpdates(Shipment* s) {
    int n;
    cout << "How many status updates to add? ";
    while (!(cin >> n) || n < 0) {
        cout << "Invalid number. Enter non-negative integer: ";
        clearInputBuffer();
    }
    clearInputBuffer();

    if (n == 0) {
        s->statusHistory = nullptr;
        s->numStatusUpdates = 0;
        return;
    }

    s->statusHistory = new ShipmentStatus[n];   
    s->numStatusUpdates = n;

    for (int i = 0; i < n; ++i) {
        cout << "\nStatus Update #" << (i + 1) << ":\n";
        cout << "  Status (e.g., Pending/Shipped/Delivered): ";
        cin.getline(s->statusHistory[i].statusDesc, sizeof(s->statusHistory[i].statusDesc));

        cout << "  Update Location:\n";
        inputLocation(&s->statusHistory[i].location);

        cout << "  Update Date:\n";
        inputDate(&s->statusHistory[i].updateDate);
    }
}

void displayShipment(const Shipment* s) {
    cout << "Shipment ID: " << s->shipmentID << endl;
    cout << "Shipment Date: " << s->shipmentDate.day << "/"
         << s->shipmentDate.month << "/" << s->shipmentDate.year << endl;
    cout << "Source: " << s->source.city << ", " << s->source.country << endl;
    cout << "Destination: " << s->destination.city << ", " << s->destination.country << endl;

    cout << "Packages (" << s->numPackages << "):\n";
    if (s->numPackages > 0) {
        for (int i = 0; i < s->numPackages; ++i) {
            // Using pointer arithmetic for demonstration
            Package* pkg = s->packages + i;
            cout << "  [" << (i+1) << "] " << pkg->description
                 << " | Weight: " << pkg->weight << " kg"
                 << " | Value: $" << pkg->value << endl;
        }
    } else {
        cout << "  [No packages]\n";
    }

    cout << "Status History (" << s->numStatusUpdates << "):\n";
    if (s->numStatusUpdates > 0) {
        for (int i = 0; i < s->numStatusUpdates; ++i) {
            ShipmentStatus* st = &s->statusHistory[i];
            cout << "  [" << (i+1) << "] " << st->statusDesc
                 << " on " << st->updateDate.day << "/"
                 << st->updateDate.month << "/" << st->updateDate.year
                 << " at " << st->location.city << ", " << st->location.country << endl;
        }
    } else {
        cout << "  [No status updates]\n";
    }
}

Shipment* searchByShipmentID(Shipment* shipments, int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (shipments[i].shipmentID == id) {
            return &shipments[i];
        }
    }
    return nullptr;
}

Shipment* searchByDestinationCity(Shipment* shipments, int count, const char* city) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(shipments[i].destination.city, city) == 0) {
            return &shipments[i];
        }
    }
    return nullptr;
}

void deallocateShipments(Shipment* shipments, int count) {
    for (int i = 0; i < count; ++i) {
        // Deallocate packages
        if (shipments[i].packages != nullptr) {
            delete[] shipments[i].packages;
            shipments[i].packages = nullptr;
        }
        // Deallocate status history
        if (shipments[i].statusHistory != nullptr) {
            delete[] shipments[i].statusHistory;
            shipments[i].statusHistory = nullptr;
        }
    }
}