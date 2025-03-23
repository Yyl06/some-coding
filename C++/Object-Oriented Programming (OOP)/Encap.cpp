#include <iostream>
#include <string>

using std::string;

class Car{
    private:
    string brand;
    int year;

    public:
    Car(){
        brand = "unknown";
        year = 0;
    }

    Car(string b, int y){
        brand = b;
        year = y;
    }

    string getBrand(){
        return brand;
    }

    void setBrand(string b){
        brand = b;
    }

    int getYear(){
        return year;
    }

    void setYear(int y){
        year = y;
    }

    void displayInfo(){
        std::cout << "Brand: " << brand << ", Year: " << year << "\n";
    }
};
int main(){
    Car myCar1;
    std::cout << "Default constructor values:" << "\n";
    myCar1.displayInfo();

    Car myCar2("Toyota", 2020);
    std::cout << "\nParameterized constructive values:" << "\n";
    myCar2.displayInfo();

    myCar2.setBrand("Honda");
    myCar2.setYear(2021);

    std::cout << "After Using Setters:" << "\n";
    std::cout << "Updated Brand: " << myCar2.getBrand() << "\n";
    std::cout << "Updated Year: " << myCar2.getYear() << "\n";

    myCar2.displayInfo();

    return 0;
}