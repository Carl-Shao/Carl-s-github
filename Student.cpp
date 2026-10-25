#include <iostream>
#include "Student.h"

//--------------------------------------------------
// Task 1
//default constructor
Student::Student() : id(0), name("Unknown"), gpa(0.0), major("Unknown") {}

// constructor with  new params
Student::Student(int id, std::string name, float gpa, std::string major) : id(id), name(name), gpa(gpa), major(major) {}

// constructor using explicit
Student::Student(int id) : id(id), name("Unknown"), gpa(0.0), major("Unknown") {}

// print function
void Student::printDetails() const {
    std::cout << "id: " << id << "\n";
    std::cout << "name: " << name << "\n";
    std::cout << "gpa: " << gpa << "\n";
    std::cout << "----------------------------\n";
}

// implement NEW FUNCTION
void Student::printFullDetails() const {
    std::cout << "id: " << id << "\n";
    std::cout << "name: " << name << "\n";
    std::cout << "gpa: " << gpa << "\n";
    std::cout << "major: " << major << "\n";
    std::cout << "----------------------------\n";
}


//---------------------------------------------------
// Task 2
// Getter Function
int Student::getId() const {
    return id;
}
std::string Student::getName() const {
    return name;
}
float Student::getGpa() const {
    return gpa;
}
// implement new get function of new member: major
std::string Student::getMajor() const {
    return major;
}

// Setter Function
void Student::setId(int id) {
    this->id = id;
}

void Student::setName(std::string name) {
    this->name = name;
}

void Student::setGpa(float gpa) {
    this->gpa = gpa;
}

// implement new set function of new member: major
void Student::setMajor(std::string major) {
    this->major = major;
}

int
main()
{
    Student student1;
    student1.printDetails();

    Student student2(106, "Clark Kent", 3.8, "Journalism");
    student2.printFullDetails();

    std::cin.get();
    std::cin.ignore();
    return 0;
}
