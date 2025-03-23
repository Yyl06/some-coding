#include <iostream>
#include <string>
using std::string;

class Course{
    string name, code;

    public:
        Course(string name, string code) : name(name) , code(code) {}

        string getName(){
            return name;
        }

        string getCode(){
            return code;
        }
};

class Student{
    string name, matrix;
    Course *subject, *sub1;

    public:
        Student(string name, string matrix) : name(name), matrix(matrix){}
        void regCourse(Course *C){
            subject = C;
        }

        void regCourse(Course *C, int i){
            sub1 = C;
        }

        void Display(){
            std::cout << "Name : " << name << std::endl;
            std::cout << "Matrix : " << matrix << std::endl;
            std::cout << "Course 1 : " << subject->getName() << " (" << subject->getCode() << ")" << std::endl;
            std::cout << "Course 2 : " << sub1->getName() << " (" << sub1->getCode() << ")" << std::endl;
        }
};

int main(){
    Course *c = new Course("PT2" , "PT2 1234");
    Course *c1 = new Course("PT1" , "PT1 1234");
    Student s("Ali" , "12345");

    s.regCourse(c);
    s.regCourse(c1, 1);
    s.Display();

    return 0;
}