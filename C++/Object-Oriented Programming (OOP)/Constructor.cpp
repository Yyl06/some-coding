#include <iostream>

//Constructor
class Employee {
    private: // Private access specifier
        int salary;
    public:
        Employee(int s) : salary(s) {} // Constructor with initializer list

        void displaySalary() {
            std::cout << "Salary: " << salary << std::endl;
        }
};

int main() {
    Employee emp(5000);
    emp.displaySalary();
    return 0;
}