package OOP.Inheritance.SuperClasses;

class Animal {
    Animal(String name) {
        System.out.println("Animal name: " + name);
    }
}

class Dog extends Animal {
    Dog(){
        super("Bulldog"); // Call parent constructor
        System.out.println("Dog constructor finished");
    }
}

public class callConstructor {
    public static void main(String[] args) {
        Dog d = new Dog();
    }
}
