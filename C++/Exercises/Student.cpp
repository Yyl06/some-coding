#include <iostream>
#include <string>

class Student{
    protected:
        std::string name;

    public:
        Student(std::string name) : name(name) {
            std::cout << "Student Name: " << name << "\n";
        }
        ~Student(){};
};

class UnderGrad : public Student{
    std::string Major;

    public:
        UnderGrad(std::string name, std::string major) : Student(name), Major(major) {
            std::cout << "Major: " << major << "\n";
        }
        ~UnderGrad(){};
};

int main(){
    UnderGrad UG("Ali", "Computer Science");

    std::cout << "---------------------------------" << "\n";
}