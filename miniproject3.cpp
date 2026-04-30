#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Base Class Person for all college students
class Person {
protected:
    std::string name;
    int id;
    std::string email;

public:
    // constructure the Person class
    Person(const std::string Name, const int ID, const std::string Email) : 
    name(Name), id(ID), email(Email) {}

    // virtual function to display information of students
    // It will override in the derived class
    virtual void displayInfo() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Email: " << email << "\n";
    }
};

class Student : public Person {
private:
    // class Student inherrited protected in Person become private
    std::string major;
    float gpa;

public:
    // constructure the Student class
    Student(const std::string Name, const int ID, const std::string Email, const std::string Major, const float GPA):
    Person(Name, ID, Email), major(Major), gpa(GPA) {}

    // override function of displayInfo
    void displayInfo() const {
        std::cout << "\nType: Student\n";
        Person::displayInfo();
        std::cout << "Major: " << major << "\n";
        std::cout << "GPA: " << gpa << "\n";
    }
};

class Employee : public Person {
protected:
    // nature of employee in university
    std::string position;
    float salary;

public:
    // constructure the Employee class
    Employee(const std::string Name = "", const int ID = 0, const std::string Email = "", 
        const std::string Position = "", const float Salary = 0.0):
    Person(Name, ID, Email), position(Position), salary(Salary) {}

    // override print position and salary
    void displayInfo() const {
        std::cout << "\nType: Employee\n";
        Person::displayInfo();
        std::cout << "Position: " << position << "\n";
        std::cout << "Salary: " << salary << "\n";
    }
};

// virtual inherits from Employee avoid conflics in Dean
class Professor : virtual public Employee {
protected:
    // nature of professor in university
    std::string department;
    std::vector<std::string>  courseTaught;

public:
    // constructure the Employee class
    Professor(const std::string Name, const int ID, const std::string Email, const std::string Position, const float Salary,
    const std::string Department, const std::vector<std::string> CourseTaught):
    Employee(Name, ID, Email, Position, Salary), department(Department), courseTaught(CourseTaught) {}

    // override print department and course taught
    void displayInfo() const {
        std::cout << "\nType: Professor\n";
        Person::displayInfo();
        std::cout << "Position: " << position << "\n";
        std::cout << "Salary: " << salary << "\n";
        std::cout << "Department: " << department << "\n";
        for(int i = 0; i < courseTaught.size(); i++) {
            std::cout << courseTaught[i] << "\n";
        }
    }
};

// virtual inherits from Employee avoid conflicts in Dean
class AdministrativeStaff : virtual public Employee {
protected:
    // nature of professor in university
    std::string officeLocation;
    std::string supervisor;

public:
    // constructure the Employee class
    AdministrativeStaff(const std::string Name, const int ID, const std::string Email, const std::string Position, 
    const float Salary, const std::string OfficeLocation, const std::string Supervisor):
    Employee(Name, ID, Email, Position, Salary), officeLocation(OfficeLocation), supervisor(Supervisor) {}

    // override print office location and super visor
    void displayInfo() const {
        std::cout << "\nType: AdministrativeStaff\n";
        Person::displayInfo();
        std::cout << "Position: " << position << "\n";
        std::cout << "Salary: " << salary << "\n";
        std::cout << "Office Location: " << officeLocation << "\n";
        std::cout << "Super Visor: " << supervisor << "\n";
    }
};

// multiple inherits from Frofesspr and AdministrativeStaff
class Dean : public Professor, public AdministrativeStaff {
protected:
    float budget;
    std::string academicVision;

public:
    // constructure the Dean class
    Dean(const std::string Name, const int ID, const std::string Email, const std::string Position, const float Salary,
    const std::string Department, const std::vector<std::string> CourseTaught, 
    const std::string OfficeLocation, const std::string Supervisor, const float Budget, const std::string AcademicVision) :
    Employee(Name, ID, Email, Position, Salary), 
    Professor(Name, ID, Email, Position, Salary, Department, CourseTaught), 
    AdministrativeStaff(Name, ID, Email, Position, Salary, OfficeLocation, Supervisor), 
    budget(Budget), academicVision(AcademicVision) {}

    // override print budget and academic vision
    void displayInfo() const {
        std::cout << "\nType: Dean\n";
        Person::displayInfo();
        std::cout << "Position: " << position << "\n";
        std::cout << "Salary: " << salary << "\n";
        std::cout << "Department: " << department << "\n";
        for(int i = 0; i < courseTaught.size(); i++) {
            std::cout << courseTaught[i] << "\n";
        }
        std::cout << "Office Location: " << officeLocation << "\n";
        std::cout << "Super Visor: " << supervisor << "\n";
        std::cout << "Budget: " << budget << "\n";
        std::cout << "Academic Vision: " << academicVision << "\n";
    }
};

class VicePresident : public Dean {
private:
    std::string regionalArea;

public:
    // constructure the VicePresident class
    VicePresident(const std::string Name, const int ID, const std::string Email, const std::string Position, 
    const float Salary, const std::string Department, const std::vector<std::string> CourseTaught, 
    const std::string OfficeLocation, const std::string Supervisor, 
    const float Budget, const std::string AcademicVison, const std::string RegionalArea) : 
    Dean(Name, ID, Email, Position, Salary, Department, CourseTaught, OfficeLocation, Supervisor, Budget, AcademicVison), 
    regionalArea(RegionalArea) {}

    // override print region area
    void displayInfo() const override final {
        std::cout << "\nType: Vice President\n";
        Person::displayInfo();
        std::cout << "Position: " << position << "\n";
        std::cout << "Salary: " << salary << "\n";
        std::cout << "Department: " << department << "\n";
        for(int i = 0; i < courseTaught.size(); i++) {
            std::cout << courseTaught[i] << "\n";
        }
        std::cout << "Office Location: " << officeLocation << "\n";
        std::cout << "Super Visor: " << supervisor << "\n";
        std::cout << "Budget: " << budget << "\n";
        std::cout << "Academic Vision: " << academicVision << "\n";
        std::cout << "Regional Area: " << regionalArea << "\n";
    }
};

// function claim
void cleanInput();
std::string getStringInput(const std::string& prompt);
int getIntegerInput(const std::string& prompt);
float getFloatingInput(const std::string& prompt);

int main(){
    std::vector<std::unique_ptr<Person>> person;
    short choice;

    do{
        // print basic information of system and provide choice
        std::cout << "\n========= University Management System =========\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Professor\n";
        std::cout << "3. Add Administraitive Staff\n";
        std::cout << "4. Add Dean\n";
        std::cout << "5. Add Vice President\n";
        std::cout << "6. Display All Personnel\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        while(!(std::cin >> choice) || choice > 7 || choice < 1) {
            std::cout << "Invalid Input! Try agian.\n";
            cleanInput();
        }
        cleanInput();

        switch(choice) {
            case 1: {
                // Enter basic information
                std::string name = getStringInput("Enter the student name: ");
                int id = getIntegerInput("Enter the student id: ");
                std::string email = getStringInput("Enter the student eamil: ");
                std::string major = getStringInput("Enter the student major: ");
                float gpa = getFloatingInput("Enter the student GPA: ");

                person.push_back(std::make_unique<Student>(name, id, email, major, gpa));
                std::cout << "Add successfully.\n";
                break;
            }

            case 2: {
                // Enter basic information
                std::string name = getStringInput("Enter the professor name: ");
                int id = getIntegerInput("Enter the professor id: ");
                std::string email = getStringInput("Enter the professor eamil: ");
                std::string position = getStringInput("Enter the professor position: ");
                float salary = getFloatingInput("Enter the professor salary: ");
                std::string department = getStringInput("Enter the professor department: ");

                // Enter the cource
                int courseNumber;
                std::cout << "Enter the course number: ";
                std::cin >> courseNumber;
                std::vector<std::string> courses;
                for(int i = 0; i < courseNumber; i++) {
                    std::cout << "Enter the courses\n";
                    std::cout << "Course " << (i + 1) << ": ";
                    std::string course;
                    std::cin.ignore();
                    std::getline(std::cin, course);
                    courses.push_back(course);
                }

                person.push_back(std::make_unique<Professor>(name, id, email, position, salary, department, courses));
                std::cout << "Add successfully.\n";
                break;
            }

            case 3: {
                // Enter basic information
                std::string name = getStringInput("Enter the administraitive name: ");
                int id = getIntegerInput("Enter the administraitive id: ");
                std::string email = getStringInput("Enter the administraitive eamil: ");
                std::string position = getStringInput("Enter the professor position: ");
                float salary = getFloatingInput("Enter the professor salary: ");
                std::string officeLocation = getStringInput("Enter the administraitive office location: ");
                std::string supervisor = getStringInput("Enter the administraitive supervisor: ");

                person.push_back(std::make_unique<AdministrativeStaff>(name, id, email, position, salary, 
                officeLocation, supervisor));
                std::cout << "Add successfully.\n";
                break;
            }

            case 4: {
                // Enter basic information
                std::string name = getStringInput("Enter the dean name: ");
                int id = getIntegerInput("Enter the dean id: ");
                std::string email = getStringInput("Enter the dean eamil: ");
                std::string position = getStringInput("Enter the dean position: ");
                float salary = getFloatingInput("Enter the dean salary: ");
                std::string department = getStringInput("Enter the dean department: ");

                // Enter the cource
                int courseNumber;
                std::cout << "Enter the course number: ";
                std::cin >> courseNumber;
                std::vector<std::string> courses;
                for(int i = 0; i < courseNumber; i++) {
                    std::cout << "Enter the courses\n";
                    std::cout << "Course " << (i + 1) << ": ";
                    std::cin.ignore();
                    std::string course;
                    std::getline(std::cin, course);
                    courses.push_back(course);
                }

                std::string officeLocation = getStringInput("Enter the dean office location: ");
                std::string supervisor = getStringInput("Enter the dean supervisor: ");
                float budget = getFloatingInput("Enter the department budget: ");
                std::string vision = getStringInput("Enter the academic vision: ");

                person.push_back(std::make_unique<Dean>(name, id, email, position, salary, department, courses,
                officeLocation, supervisor, budget, vision));
                std::cout << "Add successfully.\n";
                break;
            }

            case 5: {
                // Enter basic information
                std::string name = getStringInput("Enter the vice president name: ");
                int id = getIntegerInput("Enter the vice president id: ");
                std::string email = getStringInput("Enter the vice president eamil: ");
                std::string position = getStringInput("Enter the vice president position: ");
                float salary = getFloatingInput("Enter the vice president salary: ");
                std::string department = getStringInput("Enter the vice president department: ");

                // Enter the cource
                int courseNumber;
                std::cout << "Enter the course number: ";
                std::cin >> courseNumber;
                std::vector<std::string> courses;
                for(int i = 0; i < courseNumber; i++) {
                    std::cout << "Enter the courses\n";
                    std::cout << "Course " << (i + 1) << ": ";
                    std::cin.ignore();
                    std::string course;
                    std::getline(std::cin, course);
                    courses.push_back(course);
                }

                std::string officeLocation = getStringInput("Enter the vice president office location: ");
                std::string supervisor = getStringInput("Enter the vice president supervisor: ");
                float budget = getFloatingInput("Enter the department budget: ");
                std::string vision = getStringInput("Enter the academic vision: ");
                std::string area = getStringInput("Enter regional area: ");

                person.push_back(std::make_unique<VicePresident>(name, id, email, position, salary, department, courses,
                officeLocation, supervisor, budget, vision, area));
                std::cout << "Add successfully.\n";
                break;
            }

            case 6: {
                if(person.empty()) {
                    std::cout << "No person records found.\n";                // check empty
                } else {
                    std::cout << "\n-------- All People --------\n";
                    for(int i = 0; i < person.size(); i++) {
                        person[i] -> displayInfo();
                        std::cout << "----------------------------\n";
                    }
                }

                break;
            }

            case 7: {
                std::cout << "Exit Successfully!\nThanks for using.\n";
                break;
            }

            default:{
                std::cout << "\nINVALID! Try again.\n\n";
                break;
            }
        }
    }while(choice != 7);
}

// clean the cin when invalid variable enter
void cleanInput() {
    std::cin.clear();
    std::cin.ignore(1000000, '\n');
}

// function to get input of string
std::string getStringInput(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

// function to get input of integer
int getIntegerInput(const std::string& prompt) {
    std::cout << prompt;
    int input;
    while(!(std::cin >> input)) {
        std::cout << "Invaild Input! Try again.\n";
        cleanInput();
    }
    cleanInput();
    return input;
}

// function to get input of floating
float getFloatingInput(const std::string& prompt) {
    std::cout << prompt;
    float input;
    while(!(std::cin >> input)) {
        std::cout << "Invaild Input! Try again.\n";
        cleanInput();
    }
    cleanInput();
    return input;
}