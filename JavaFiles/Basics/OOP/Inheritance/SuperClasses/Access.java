package OOP.Inheritance.SuperClasses;

class Animal {
    String type = "Animal";
}

class Dog extends Animal {
    String type = "Dog";

    void printType() {
        System.out.println("Child type: " + type);       // Dog
        System.out.println("Parent type: " + super.type); // Animal
    }
}

public class Access{
    int x = 10;
    public static void main(String[] args) {
        Dog d = new Dog();
        d.printType();
    }
}