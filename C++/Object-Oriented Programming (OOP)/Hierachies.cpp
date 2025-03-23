#include <iostream>

class Animal{
public:
    void eat(){
        std::cout << "Eating..." << "\n";
    }
};

class Dog : public Animal{
    public:
        void Bark(){
            std::cout << "Woof Woof" << "\n";
        }
    };

class Puppy : public Dog{
    public:
        void Weep(){
            std::cout << "Weep Weep..." << "\n";
        }
    };

    int main(){
        Puppy pup;
        pup.eat();
        pup.Bark();
        pup.Weep();

        return 0;
    }