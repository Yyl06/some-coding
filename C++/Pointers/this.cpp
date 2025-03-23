//Demonstration on this-> pointer Syntax

#include <iostream>

class pointer{
    //Private class that cant be accessed via mentioning
    private:
    int salary;
    
    public:
    //Setter is enough for getter by using -> pointer function
    void setSalary(int money){
        //money is now set to the address value of salary
        this -> salary = money;
    }
    void showSalary(){
        std::cout << "Salary :" << salary;
    }
};

int main(){
    pointer Salarys;
    int salary = 50000;

    Salarys.setSalary(salary);
    Salarys.showSalary();

    return 0;
}