#include <iostream>

class Shape{
    public:
    virtual void Shapes() = 0; //pure virtual; must be overrided
};

class Circle : public Shape{
    public:
        void Shapes() override{
            std::cout << "Drawing Circle..." << "\n";
        }
};

class Rectangle : public Shape{
    public:
        void Shapes() override{
            std::cout << "Drawing Rectangle.." << "\n";
        }
};

void renderShape(Shape &s){
    s.Shapes();
}

int main(){
    Circle c;
    Rectangle Rect;

    renderShape(c);
    renderShape(Rect);
}