#include <iostream>
#include <iomanip>
/*
class Radius{
    private:
    double radius;

    public:
    Radius(){
        radius = 0.0;
    }

    //Constructor
    Radius(double r){
        radius = r;
    }

    //Getter + Setter
    void setRadius(double r){
        this -> radius = r;
    }

    double getArea(){
        return 3.14159 * radius * radius;
    }

    double getDiameter(){
        return 2 * radius;
    }

    double getCircumference(){
        return 2 * 3.14159 * radius;
    }
};

int main(){

}
*/

class Shape{
    //Private variables
    private:
    double length , width;

//Setter + Getter for length and width, with a method to calculate the area of the rectangle
    public:
    void SetLength(double l){
        this -> length = l;
    }
    void SetWidth(double w){
        this -> width = w;
    }

    double GetArea(){
        return length * width;
    }

    void Display(){
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Area: " << GetArea() << std::fixed << std::setprecision(2) << std::endl;
    }
};

int main(){
    //The Class Named Shape is Named to Rect1 as an object
    Shape Rect1;
    //Calling the setter methods
    Rect1.SetLength(5.0);
    Rect1.SetWidth(4.0);
    Rect1.Display();
    return 0;
}