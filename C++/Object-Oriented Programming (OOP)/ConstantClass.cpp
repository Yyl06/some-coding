#include <iostream>

class Circle{
    private:
    double radius;

    public:
    static const double pie;
    //Constructor
    Circle(double r){
        radius = r;
    }
    double GetArea(){
        return pie * radius * radius;
    }
};

const double Circle::pie = 3.142;

int main(){
    Circle c1(5.5) , c2(12.8);
    std::cout << "Area of circle 1: " << c1.GetArea() << std::endl;
    std::cout << "Area of circle 2: " << c2.GetArea() << std::endl;
    std::cout << "Value of pi: " << Circle::pie << std::endl;
    return 0;
}