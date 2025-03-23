#include <iostream>
using std::string;

class Subject{
    private:
    string name, grade;
    int codeSubject, credit;
    double mark, subjectPoint;

    public:
    void SetSubject(){
        std::cout << "Enter Subject's Name: ";
        std::cin >> name;
        std::cout << "\nEnter Subject Code: ";
        std::cin >> codeSubject;
        std::cout << "\nEnter Subject Credit: ";
        std::cin >> credit;
        std::cout << "\nEnter Subject Mark (MAX 100): ";
        std::cin >> mark;


    }

    string GetGrades(int marks){
        if(marks >= 90 && marks <= 100){
            return this->grade = "A+";
        }else if(marks <= 89 && marks >= 80){
            return this->grade = "A";
        }else if(marks <= 79 && marks >= 75){
            return this->grade = "A-";
        }else if(marks <= 74 && marks >= 70){
            return this->grade = "B+";
        }else if(marks <= 69 && marks >= 65){
            return this->grade = "B";
        }else if(marks <= 64 && marks >= 60){
            return this->grade = "B-";
        }else if(marks <= 59 && marks >= 55){
            return this->grade = "C+";
        }else if(marks <= 54 && marks >= 50){
            return this->grade = "C";
        }else if(marks <= 49 && marks >= 45){
            return this->grade = "C-";
        }else if(marks <= 44 && marks >= 40){
            return this->grade = "D+";
        }else if(marks <= 39 && marks >= 35){
            return this->grade = "D";
        }else if(marks <= 30 && marks >= 34){
            return this->grade = "D-";
        }else if(marks <= 29 && marks >= 0){
            return this->grade = "E";
        }else{
            std::cerr << "Out Of Range." << "\n";
        }
    }

    double GetGradePoint(int marks){
        if(marks >= 90 && marks <= 100){
            std::cout << "Grade Points: 4" << "\n";
        }else if(marks <= 89 && marks >= 80){
            std::cout << "Grade Points: 4" << "\n";
        }else if(marks <= 79 && marks >= 75){
            std::cout << "Grade Points: 3.67" << "\n";
        }else if(marks <= 74 && marks >= 70){
            std::cout << "Grade Points: 3.33" << "\n";
        }else if(marks <= 69 && marks >= 65){
            std::cout << "Grade Points: 3" << "\n";
        }else if(marks <= 64 && marks >= 60){
            std::cout << "Grade Points: 2.67" << "\n";
        }else if(marks <= 59 && marks >= 55){
            std::cout << "Grade Points: 2.33" << "\n";
        }else if(marks <= 54 && marks >= 50){
            std::cout << "Grade Points: 2" << "\n";
        }else if(marks <= 49 && marks >= 45){
            std::cout << "Grade Points: 1.67" << "\n";
        }else if(marks <= 44 && marks >= 40){
            std::cout << "Grade Points: 1.33" << "\n";
        }else if(marks <= 39 && marks >= 35){
            std::cout << "Grade Points: 1" << "\n";
        }else if(marks <= 30 && marks >= 34){
            std::cout << "Grade Points: 0.67" << "\n";
        }else if(marks <= 29 && marks >= 0){
            std::cout << "Grade Points: 0" << "\n";
        }else{
            std::cerr << "Out Of Range." << "\n";
        }
    }

    void Display(){
        std::cout << "Subject List: " << "\n";
        std::cout << "\tSubject's Name: " << name << "\n";
        std::cout << "\tSubject Code: " << codeSubject << "\n";
        std::cout << "\tSubject Credit: " << credit << "\n";
        std::cout << "\tSubject Marks: " << mark << "\n";
        std::cout << "\tSubject Grades: " << GetGrades(mark) << "\n";
        std::cout << "\tGrade Points: " << GetGradePoint(mark) << "\n";
    }

    int getCredit(){
        return credit;
        }

    double getSubjectPoint(){
        return subjectPoint; 
        }
};

class Student{
    private:
        string name;
        int IDnum;
        double cpa;
        int subjectCount;
    
    public:
        Subject Subjects;
        Student(std::string name, int IDnum, double cpa , int subjectCount){
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "IC Number: ";
            std::cin >> IDnum;
            
            std::cout << "Number of Registered Subjects : ";
            std::cin >> subjectCount;
            if(subjectCount > 5){
                std::cerr << "Maximum Subjects Are 5!";
            }

        this->name = name;
        this->IDnum = IDnum;
        this->cpa = cpa;
        this->subjectCount = subjectCount;
        }

        void setSubject(){
            int mark;
            for(int i = 0 ; i < subjectCount ; i++){
                std::cout << "Enter Subject Details for Subject " << (i+1) << ": " << "\n";
                Subjects.SetSubject();
                Subjects.GetGrades(mark);
                Subjects.GetGradePoint(mark);
                Subjects.Display();
            }
        }

        double GetCpa(double cpa){
            double totalPoints = 0, totalCredits = 0;
            for (int i = 0; i < subjectCount; i++) {
                totalPoints += Subjects.getSubjectPoint();
                totalCredits += Subjects.getCredit();
            }
            return cpa = totalCredits > 0 ? totalPoints / totalCredits : 0;
        }

    void display() {
        std::cout << "Student Name: " << name << "\n";
        std::cout << "IC Number: " << IDnum << "\n";
        std::cout << "CPA: " << GetCpa(cpa) << "\n";
    }
};

int main(){
    Subject Subjects;
    
    string name, grade, subjectName;
    int codeSubject, credit, IDnum, subjectCount;
    double mark, subjectPoint, cpa;
    
    Student Results(name, IDnum, cpa, subjectCount);
    Results.setSubject();
    Subjects.SetSubject();
    Results.display();
    Subjects.Display();
}