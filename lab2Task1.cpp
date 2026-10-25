#include <iostream>

class Student {

// member of class
private:
    int id;
    std::string name;
    float gpa;

public:
    //--------------------------------------------------
    // Task 1
    //default constructor
    Student() : id(0), name("Unknown"), gpa(0.0) {}

    // constructor with params
    Student(int id, std::string name, float gpa) : id(id), name(name), gpa(gpa) {}

    // constructor using explicit
    explicit Student(int id) : id(id), name("Unknown"), gpa(0.0) {}

    // print function
    void printDetails() const {
        std::cout << "id: " << id << "\n";
        std::cout << "name: " << name << "\n";
        std::cout << "gpa: " << gpa << "\n";
        std::cout << "----------------------------\n";
    }
};


int
main()
{
    std::cout << "----------------------------\n";

    Student defaultStudent;
    defaultStudent.printDetails();

    Student student1(101, "Alice Johnson", 3.9);
    student1.printDetails();

    Student student2(102);
    student2.printDetails();

    std::cin.get();
    std::cin.ignore();
    return 0;
}