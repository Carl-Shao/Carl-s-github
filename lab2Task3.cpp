#include <iostream>


class Student {

// member of class
private:
    int id;
    std::string name;
    float gpa;

    //--------------------------------------------------
    // Task3
    // create new member: major
    std::string major;

public:
    //--------------------------------------------------
    // Task 1
    //default constructor
    Student() : id(0), name("Unknown"), gpa(0.0), major("Unknown") {}

    // constructor with  new params
    Student(int id, std::string name, float gpa, std::string major) : id(id), name(name), gpa(gpa), major(major) {}

    // constructor using explicit
    explicit Student(int id) : id(id), name("Unknown"), gpa(0.0), major("Unknown") {}

    // print function
    void printDetails() const {
        std::cout << "id: " << id << "\n";
        std::cout << "name: " << name << "\n";
        std::cout << "gpa: " << gpa << "\n";
        std::cout << "----------------------------\n";
    }

    // implement NEW FUNCTION
    void printFullDetails() const {
        std::cout << "id: " << id << "\n";
        std::cout << "name: " << name << "\n";
        std::cout << "gpa: " << gpa << "\n";
        std::cout << "major: " << major << "\n";
        std::cout << "----------------------------\n";
    }


    //---------------------------------------------------
    // Task 2
    // Getter Function
    int getId() const {
        return id;
    }
    std::string getName() const {
       return name;
    }
    float getGpa() const {
        return gpa;
    }
    // implement new get function of new member: major
    std::string getMajor() const {
        return major;
    }

    // Setter Function
    void setId(int id) {
        this->id = id;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setGpa(float gpa) {
        this->gpa = gpa;
    }

    // implement new set function of new member: major
    void setMajor(std::string major) {
        this->major = major;
    }
};

int
main()
{
    Student student1(105, "Diana Prince", 4.0, "Physics");
    student1.printFullDetails();

    student1.setName("Diana P.");
    student1.setGpa(3.95);
    student1.printFullDetails();

    std::cin.get();
    std::cin.ignore();
    return 0;
}