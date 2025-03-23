#include <iostream>

class Parent{
    public:
    Parent(){
        std::cout << "Constructor Parent Called." << "\n";
    }

    ~Parent(){
        std::cout << "Destructor Parent Called." << "\n";
    }
};

class Child : public Parent{
    public:
    Child(){
        std::cout << "Constructor Child Called." << "\n";
    }

    ~Child() {
        std::cout << "Destructor Child Called." << "\n";
    }
};

int main(){
    Child Class;


    return 0;
}