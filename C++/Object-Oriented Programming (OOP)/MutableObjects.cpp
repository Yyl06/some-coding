#include <iostream>

class Triangle{
    private:
    mutable double height;
    double base;

    public:
    Triangle(double h, double b) : height(h) , base(b) {};
    
    double GetArea() const{
        double area = 0.5 * height * base;;
        return area;
    }

    double GetBase() const{
        return base;
    }

    void SetHeight(double h) const{
        height = h;
    }
};

int main(){
    Triangle t1(5.0, 4.0);
    std::cout << "Area of triangle: " << t1.GetArea() << std::endl;
    std::cout << "Base of triangle: " << t1.GetBase() << std::endl;
    t1.SetHeight(10.0);
    std::cout << "Area of triangle: " << t1.GetArea() << std::endl;
    std::cout << "Base of triangle: " << t1.GetBase() << std::endl;
    return 0;
}