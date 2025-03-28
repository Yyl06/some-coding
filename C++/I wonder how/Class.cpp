#include <iostream>
using std::string;

class Student {
protected:
    int id;
    string name;

public:
    Student(int id, string name) : id(id), name(name) {}

    void displayStudentInfo() {
        std::cout << "Student ID: " << id << '\n';
        std::cout << "Name: " << name << '\n';
    }
};

class UnderGraduateCourse {
    string courseName;
    string courseCode;

    public:
    UnderGraduateCourse(string name, string code) : courseName(name), courseCode(code) {}

    void displayUnderGraduateCourseInfo() {
        std::cout << "Course Name: " << courseName << "\n";
        std::cout << "Course Code: " << courseCode << "\n";
    }
};

class UnderGraduate : public Student {
    string degree;
    UnderGraduateCourse course;

    public:
    UnderGraduate(int id, string name, string d, string cname, string ccode)
        : Student(id, name), degree(d), course(cname, ccode) {}

    void displayUnderGraduateInfo() {
        displayStudentInfo();
        std::cout << "Degree: " << degree << '\n';
        course.displayUnderGraduateCourseInfo();
    }
};

class PostGraduateCourse {
    string courseName;
    string courseCode;

public:
    PostGraduateCourse(string name, string code) : courseName(name), courseCode(code) {}

    void displayPostGraduateCourseInfo() {
        std::cout << "Course Name: " << courseName << "\n";
        std::cout << "Course Code: " << courseCode << "\n";
    }
};

class PostGraduate : public Student {
    string researchTopic;
    PostGraduateCourse course;

    public:
    PostGraduate(int id, string name, string topic, string cname, string ccode)
        : Student(id, name), researchTopic(topic), course(cname, ccode) {}

    void displayPostGraduateInfo() {
        displayStudentInfo();
        std::cout << "Research Topic: " << researchTopic << '\n';
        course.displayPostGraduateCourseInfo();
    }
};

int main() {
    UnderGraduate ug(1001, "Fatihah", "Computer Science", "Data Structures", "CS101");
    PostGraduate pg(2001, "Izzati", "Artificial Intelligence", "Machine Learning", "AI501");

    std::cout << "Undergraduate Course Information:\n";
    ug.displayUnderGraduateInfo();

    std::cout << "\nPostgraduate Course Information:\n";
    pg.displayPostGraduateInfo();

    return 0;
}
