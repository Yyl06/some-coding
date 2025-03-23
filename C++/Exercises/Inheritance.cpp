#include <iostream>
#include <string>

class Employee{
    private:
    int staffID;

    protected:
        std::string name;
        char gender;
        int age;

    public:
        Employee(){staffID=-1;}
        Employee(int id){staffID = id;}
        ~Employee(){std::cout << "\nEmployee Destructor\n";}
        void SetStaffID(int id){
            staffID = id;
        }
        int GetstaffID(){
            return staffID;
        }
        void Display(){
            std::cout << "\nDetail Employee: " << "\n\tName: " << name << "\n\tStaffID: " << staffID << "\n\tGender: " << gender << "\n\tAge: " << age;
        }
};

class Permanent : public Employee{
    private:
        double salary;

    public:
        Permanent(int i, std::string n, char g){
            SetStaffID(i);
            name = n;
            gender= g;
        }
        void setAge(int a){
            age = a;
        }
        void setSalary(double s){
            salary = s;
        }
        void Display(){
            std::cout << "\nDetail Permanent Staff: " << "\n\tName: " << name << "\n\tStaffID: " << GetstaffID() << "\n\tGender: " << gender << "\n\tAge: " << age << "\n\tSalary: " << salary;
        }
        ~Permanent(){
            std::cout << "\nPermanent Destructor\n";
        }
};

class Temporary : public Employee{
    private:
        double Payment, Commision;
        int Daywork;

    public:
        Temporary(int i, std::string n, char g, int d, double c) : Daywork(d), Commision(c) {
            SetStaffID(i);
            name = n;
            gender = g;
            SetAge(20);
            Payment = CalculatePayment();
        }
        void SetAge(int a){
            age = a;
        }

        void SetdayWork(int d){
            Daywork = d;
        }

        double CalculatePayment(){
            Payment = 1500.00 + (Commision/100*1500.00*Daywork);
            return Payment;
        }

        void Display(){
            std::cout << "\nDetail Temporary Staff: " << "\n\tName: " << name << "\n\tStaffID: " << GetstaffID() << "\n\tGender: " << gender << "\n\tAge: " << age << "\n\tPayment: " << CalculatePayment();
        }
};

int main(){
    Employee emp(1001);
    emp.Display();

    Permanent p(1002, "John Doe", 'M');
    p.setAge(32);
    p.setSalary(2500.58);
    p.Display();
    std::cout << "\nFrom Main Staff p Display ID " << p.GetstaffID();

    Temporary t(1003, "Mary Jane", 'F', 18, 10.5);
    t.Display();
    std::cout << "\nFrom Main Staff t Display ID " << t.GetstaffID();

    return 0;
}