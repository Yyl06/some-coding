#include <iostream>
#include <string>

class Person{
    private:
    int age;
    std::string name;

    public:
    //Setter for age
    void Setage(int a){
        if (a <= 0) {
        std::cout << "Invalid Age !" << "\n";
        } else {
            age = a;
        }
    }

    //Getter for age
    int GetAge(){
        return age;
    }

    //Setter for name
    void SetName(std::string n){
        name = n;
    }
    //Getter for name
    std::string GetName(){
        return name;
    }

    void DisplayAll(){
        std::cout << "Your Name : " << name << " Your Age : " << age << "\n";
    }
};

class Rectangle{
    private:
    double length , width;

    public:
    void SetLength(double l){
        if(l <= 0){
            std::cout << "Invalid length !" << "\n";
        } else {
        length = l;
        }
    }
    double GetLength(){
        return length;
    }

    void SetWidth(double w){
        if (w <= 0){
            std::cout << "Invalid width !" << "\n";
        } else {
        width = w;
        }
    }
    double GetWidth(){
        return width;
    }

    double area = width * length;
    double perimeter = 2 * (width + length);
    
    double CalcArea(){
        return area;
    }

    double CalcPerimeter(){
        return perimeter;
    }
};

class Student{
    private:
    int rollnumber , marks;
    std::string name;

    void Getrollnum(int r){
        rollnumber = r;
    }
    int Getrollnum(){
        return rollnumber;
    }

    void GetMarks(int m){
        if(m < -1 || m > 101){
            std::cout << "Invalid Marks !" << "\n";
        } else {
        marks = m;
        }
    }
    int SetMarks(){
        return marks;
    }

    void SetName(std::string n){
        name = n;
    }
    std::string GetName(){
        return name;
    }
};

int main(){
    Person mylist;
    int age;
    std::string name;
    char choice;

do{
    std::cout << "Your Name : ";
    std::cin >> name ;
    mylist.SetName(name);
    std::cout << "Your Age : ";
    std::cin >> age;
    mylist.Setage(age);
    mylist.DisplayAll();
    std::cout << "Do You Wanna Enter Again? (y/n) :";
}while(choice == 'y' || choice == 'Y');




    return 0;
}