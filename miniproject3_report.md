# Project of University Management System

ps: this report use markdown to show. Please open it in markdown

---

### The Design of Class

#### Class Person

It is the most basic class. I constructure the basic information of a person class that latter we can override it. display_Info function is a virtual function to let same function to use in other derived class.



#### Class Student

This class is derived from Person. So it has every member of Person. I also add major and GPA for Student class. Then override the display function to just print the information for student.



#### Class Employee

It is also a base class but it still derived from Person. The other two class derived from Employee.



#### Class Professor and AdministrativeStaff

This two class are derived from Employee and the class Dean will be derived by them. So the derived claim should be virtual public. Setting like this is to avoid member in Dean class initialize twice.



#### Class Dean and Vise President

I do add other member of this two class. Dean is derived from Professor and  AdministrativeStaff. Vise President is derived from Dean.

---

### Main Function

In main function we use unique pointer which is a smart pointer to manage an array of class. I put all of them in vector. So I also need include memory and vector. So we don't have to new the class and delete them.

---

### Other Function

##### cleanInput 

this function is to deal with the invalid input of integer or floating

##### other get function

to get string integer and foalting

