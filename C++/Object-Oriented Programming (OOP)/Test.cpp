#include <iostream>
using std::string, std::cout;

class Shape {
    private:
        string name;
        double area;
    public:
        virtual void calculateArea() = 0; // Pure virtual function
    
        void setName(string n) { name = n; }
        string getName() { return name; }
        void setArea(double a) { area = a; }
        double getArea() { return area; }
    
        virtual void display() { // Virtual function
            cout << "\nInside Shape class.";
        }
    };
    
    void Shape::calculateArea() {
        area = 0;
    }

    class Circle : public Shape {
        private:
            static const double pie;
            int radius;
        public:
            Circle(int r);
            void calculateArea() override;
            void display() override;
        };
        
        const double Circle::pie = 3.142;
        
        Circle::Circle(int r) {
            setName("Circle");
            radius = r;
        }
        
        void Circle::calculateArea() {
            double area = pie * radius * radius;
            setArea(area);
        }
        
        void Circle::display() {
            calculateArea();
            cout << "\nArea " << getName() << " with radius " << radius << " is " << getArea();
        }

        class Square : public Shape {
            private:
                double length;
                double width;
            public:
                Square(double l, double w);
                void calculateArea() override;
                void display() override;
            };
            
            Square::Square(double l, double w) {
                setName("Square");
                length = l;
                width = w;
            }
            
            void Square::calculateArea() {
                double area = length * width;
                setArea(area);
            }
            
            void Square::display() {
                calculateArea();
                cout << "\nArea " << getName() << " with length "<< length << " and width " << width << " is " << getArea();
            }

            int main() {
                Shape* shape1 = new Circle(4);
                Shape* shape2 = new Square(5, 9);
            
                shape1->display();
                shape2->display();
            
                delete shape1;
                delete shape2;
            
                return 0;
            }
            