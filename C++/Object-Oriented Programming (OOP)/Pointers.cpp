#include <iostream>

class Rect{
    private:
        int length, width;

    public:
    Rect(int l , int w){
        length = l;
        width = w;
    }

    int area(){
        return length * width;
    }
};

int main(){
    Rect Rectangle(10 ,5);
    Rect *pRectangle = &Rectangle;

    std::cout << "Area of Rectangle : " << pRectangle->area() << "\n";
    return 0;
}