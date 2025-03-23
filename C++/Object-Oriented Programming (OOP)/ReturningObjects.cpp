#include <iostream>


class Complex {
private:
    int real, imag;

public:
    // Constructor using initializer list
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the + operator for complex number addition
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Display function
    void display() {
        std::cout << real << " + " << imag << "i" << "\n";
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex sum = c1 + c2;  // Using operator overloading
    sum.display();
    return 0;
}