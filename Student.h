#ifndef STUDENT_H
#define STUDENT_H

#include <string>

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
    Student();

    // constructor with params
    Student(int id, std::string name, float gpa, std::string major);

    // constructor using explicit
    explicit Student(int id);

    // print function
    void printDetails() const;


    //---------------------------------------------------
    // Task 2
    // Getter Function
    int getId() const;
    std::string getName() const;
    float getGpa() const;

    // getter function of new member: major
    std::string getMajor() const;


    // Setter Function
    void setId(int id);
    void setName(std::string name);
    void setGpa(float gpa);

    // getter function of new member: major
    void setMajor(std::string major);

    //----------------------------------------------------
    // Task3
    // create new function of print full details
    void printFullDetails() const;
};


#endif