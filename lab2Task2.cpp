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
};


int
main()
{
    Student student1(103, "Bob Smith", 3.5);
    student1.setName("Robert Smith");
    student1.setGpa(3.6);
    student1.printDetails();

    const Student student2(104, "Charlie Brown", 3.8);
    student2.printDetails();

    std::cin.get();
    std::cin.ignore();
    return 0;
}