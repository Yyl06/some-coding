#include <iostream>
#include <string>
using std::cout, std::string;

static const int arrayMAX = 5;

class Student{
    protected:
        string name;
        int id;

    public:
        Student(string n, int i) : name(n), id(i) {}
};

class FullTime : private Student{
    double cpa;
    double fee;

    public:
        FullTime(string n, int i,double c, double f) : Student(n, i), cpa(c), fee(f) {}
        void display(){
            cout << "\nid: " << id << "\n";
            cout << "Name: " << name << "\n";
            cout << "CPA: " << cpa << '\n';
            cout << "Fee: " << fee << "\n";
        }
        friend class Course;
};

class PartTime : private Student{
    int totalCredit;
    double ratePerCredit;
    double Payment;

    public:
        PartTime(string n, int i, int totalCredit, double ratePerCredit) : Student(n, i), totalCredit(totalCredit), ratePerCredit(ratePerCredit) {}
        void calculatePayment(){
            Payment = totalCredit * ratePerCredit;
        }
        void display(){
            cout << "\nid: " << id << "\n";
            cout << "Name: " << name << "\n";
            cout << "Total Credit: " << totalCredit << "\n";
            cout << "Rate Per Credit: " << ratePerCredit << "\n";
            cout << "Payment: " << Payment << "\n";
        }
        friend class Course;
};

class Course{
    string name;
    double income;
    FullTime *fullTimeStudent[arrayMAX];
    PartTime *partTimeStudent[arrayMAX];
    int totalStuPT;
    int totalStuFT;

    public:
        Course(string name) : name(name), income(0), totalStuPT(0), totalStuFT(0) {}
        void addStudentFT(FullTime &FT){
            fullTimeStudent[totalStuFT++] = &FT;
            totalStuFT++;
        }
        void addStudentPT(PartTime &PT){
            partTimeStudent[totalStuPT++] = &PT;
            totalStuPT++;
        }
        void calcluateIncome(){
            income = 0;
            for(int i = 0 ; i < totalStuFT ; ++i){
                income += fullTimeStudent[i]->fee;
            }
            for(int i = 0 ; i < totalStuPT ; ++i){
                income += partTimeStudent[i]->Payment;
            }
        }
        void display(){
            calcluateIncome();
            std::cout << "Course Name: " << name << "\n";
            for(int i = 0 ; i < totalStuFT; ++i){
                fullTimeStudent[i]->display();
            }
            for(int i = 0 ; i < totalStuPT ; ++i){
                partTimeStudent[i]->display();
            }
            std::cout << "Total Income: " << income << "\n";
        }
};

int main(){
    Course c("CS");
    FullTime f2("Ali", 401, 3.25, 19800.50);
    FullTime f3("Muthu", 302, 2.85, 21220.20);
    PartTime p1("Kevin", 401, 15, 1500.35);

    c.addStudentFT(f2);
    c.addStudentFT(f3);
    c.addStudentPT(p1);
    c.display();
}