//Polymorphism , which creating a class and then inherits the class earlier with a new class
//Mostly used on expanding functions on a class

#include <iostream>

class Animal {
  public:
    void animalSound() {
      std::cout << "The animal makes a sound \n";
    }
};

class Pig : public Animal {
  public:
    void animalSound() {
      std::cout << "The pig says: wee wee \n";
    }
};

class Dog : public Animal {
  public:
    void animalSound() {
      std::cout << "The dog says: bow wow \n";
    }
};

int main() {
  Animal myAnimal;
  Pig myPig;
  Dog myDog;

  myAnimal.animalSound();
  myPig.animalSound();
  myDog.animalSound();
  return 0;
}