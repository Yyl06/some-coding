#include <iostream>

class Employee {
  protected: // Protected access specifier
    int salary;
};

// Derived class
class Programmer: public Employee {
  public:
    int bonus;

    //Setter
    void setSalary(int s) {
      salary = s;
    }
    //Getter
    int getSalary() {
      return salary;
    }
};

int main(){
    Programmer Salary;
    int salary;

    std::cout << "Enter Salary : ";
    std::cin >> salary;
    std::cout << "\n";
    std::cout << "Enter Bonus : ";
    std::cin >> Salary.bonus;
    std::cout << "\n";

    Salary.setSalary(salary);

    std::cout << "Your Bonus : " << Salary.bonus << "\n";
    std::cout << "Salary of a Programmer is : " << Salary.getSalary() << "\n";

    return 0;
}
