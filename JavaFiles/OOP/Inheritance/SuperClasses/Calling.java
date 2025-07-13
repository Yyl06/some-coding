package OOP.Inheritance.SuperClasses;

class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void sound(){
        super.sound(); // Call parent method
        System.out.println("Dog barks");
    }
}

public class Calling{
    public static void main(String[] args) {
        Dog d = new Dog();
        d.sound();
    }
}
