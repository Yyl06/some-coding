#include <iostream>

class Animal{
    public:
        virtual void makeSound() = 0;
};

class Dog : public Animal{
    public:
        void makeSound() override{
            std::cout << "Dog Barks" << "\n";
        }
};

class Cat : public Animal{
    public:
        void makeSound() override{
            std::cout << "Cat Meows" << "\n";
        }
};

int main(){
    Dog d;
    Cat c;
    d.makeSound();
    c.makeSound();
    return 0;
}