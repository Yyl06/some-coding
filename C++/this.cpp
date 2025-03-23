#include <iostream>
using std::string;

class Student{
    private:
        string name;
        int age;

    public:
        Student(string n, int a){
            this->name = n;
            this->age = a;
        }

        void Display(){
            std::cout << "Name: " << this->name << ", Age: " << this->age << "\n";
        }
        
        Student &SetName(string name){
            this->name = name;
            return *this;
        }

        Student &SetAge(int age){
            this->age = age;
            return *this;
        }

        bool isSame(Student &other){
            return this == &other;
        }
};

int main(){
    Student s1("Alice" , 20);
    Student s2("Bob", 22);

    std::cout << "Initial Details: " << "\n";
    s1.Display();
    s2.Display();

    std::cout << "\nUpdated Details using Method Chaining: " << "\n";
    s1.SetAge(21).SetName("Alice Cooper");
    s1.Display();

    std::cout << "\nComparing Objects: " << "\n";
    if(s1.isSame(s2)){
        std::cout << "Student 1 and Student 2 is the same." << "\n";
    }else{
        std::cout << "Student 1 and Student 2 are different objects." << "\n";
    }

    std::cout << "Self Comparasion: " << "\n";
    if(s1.isSame(s1)){
        std::cout << "Student 1 is comaparing to itself." << "\n";
    }

    return 0;
}