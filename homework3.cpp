#include <iostream>
#include <iomanip>


// create Complex class 
class Complex{
private:
    // create private variable of real part and imaginary part of each complex
    double real;
    double imaginary;

public:
    // constructure the real and imaginary part of Complex and initialize
    Complex(double a = 0.0, double b = 0.0):real(a), imaginary(b){}

    // overloading the four calculate signments (+ - * /)
    Complex operator+(const Complex& other) const{
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const{
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const{
        return Complex(real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const{
        double check = other.real * other.real + other.imaginary * other.imaginary;
        if(check == 0){
            std::cout << "\nInvalid Input! Can't devide by it!\n";
            return Complex();
        }
        return Complex((real * other.real + imaginary * other.imaginary) / check,
    (imaginary * other.real - real * other.imaginary) / check);
    }

    // overloading the compare signment
    bool operator==(const Complex& other) const{
        if (real == other.real && imaginary == other.imaginary){
            return true;
        } else{
            return false;
        }
    }

    // overloading the - for negtive object
    Complex operator-() const{
        return Complex(-real, -imaginary);
    }

    // claim friend function of cin and cout
    friend std::istream& operator >> (std::istream& in, Complex& c);
    friend std::ostream& operator << (std::ostream& out, const Complex& c);
};

std::istream& operator >> (std::istream& in, Complex& c){
    in >> c.real >> c.imaginary;
    return in;
}

std::ostream& operator << (std::ostream& out, const Complex& c){
    if (c.imaginary == 0) {
        out << c.real;
    } else if (c.real == 0) {
        if (c.imaginary == 1)
            out << "i";
        else if (c.imaginary == -1)
            out << "-i";
        else
            out << c.imaginary << "i";
    } else {
        out << c.real;
        if (c.imaginary >= 0) {
            if (c.imaginary == 1)
                out << " + i";
            else
                out << " + " << c.imaginary << "i";
        } else {
            if (c.imaginary == -1)
                out << " - i";
            else
                out << " - " << (-c.imaginary) << "i";
        }
    }
    return out;
}

int main(){
    Complex a, b;

    // enter the two comlex number
    std::cout << "Enter the first complex number (real, imaginary): ";
    std::cin >> a;
    std::cout << "Enter the second complex number (real, imaginary): ";
    std::cin >> b;

    // display the result of calculating
    std::cout << "\n-------------- RESULT ---------------\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "a / b = " << a / b << "\n";

    std::cout << "-a = " << -a << "\n";
    std::cout << "-b = " << -b << "\n";
    std::cout << "a = b ?" << (a == b ? "True" : "False") << "\n";

    return 0;
} 