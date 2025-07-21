package OOP.Polymorphism;
import java.util.ArrayList;

//Final Method
class Animal {
    public final void makeSound() {
        System.out.println("Some sound");
    }
}

class Dog extends Animal {
    // ❌ Error:
    // public void makeSound() {
    //     System.out.println("Bark");
    // }
}

//Final Class
final class Utility{
    public static void printMessage() {
        System.out.println("Can't be extended");
    }
}
// ❌ Error:
// class AdvancedUtility extends Utility { }

//Final Variable(const in C++)
class Person {
    final String name;

    public Person(String name) {
        this.name = name;
    }
    // name can never change after construction
}

public class FinalKeyword{

    //Final Parameters
    public static void printLength(final String name) {
        // name = "New"; // ❌ Error: cannot assign a value to final parameter
        System.out.println("Length: " + name.length());
    }

    public static void main(String[] args) {
        //Final Variable
        final int x = 10;
        // x = 20;  // ❌ Error: cannot assign a value to final variable 'x'
        System.out.println("x = " + x);

        //Final Reference
        final ArrayList<String> list = new ArrayList<>();
        list.add("Hello");   // ✅ allowed
        list.add("World");

        // list = new ArrayList<>(); // ❌ Error: cannot assign a new object
        System.out.println(list);


        //Final Method
        Animal animal = new Dog();
        animal.makeSound();  // Output: Some sound
        // animal.makeSound();  // Cannot override final method in Dog class
        System.out.println("Animal sound made successfully.");

        //Final Parameter's usage
        printLength("Java");
        printLength("ChatGPT");


        //Final Variable
        Person person = new Person("Alice");
        System.out.println("Person's name: " + person.name);
    }
}

