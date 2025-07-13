package OOP.Polymorphism;

public class Runtime {
        public static void main(String[] args) {
        Person gs = new GraduateStudent();  // Actual object is GraduateStudent
        Person s = new Student();           // Actual object is Student
        Person p = new Person();            // Actual object is Person
        Object o = new Object();            // Actual object is just Object

        speak(gs); // Will print "Student"
        speak(s);  // Will print "Student"
        speak(p);  // Will print "Person"
        System.out.println(o.toString()); // Will print something like "java.lang.Object@15db9742"
    }

    public static void speak(Person p) {
        System.out.println(p.toString());
    }
    
    static class Person {
        @Override
        public String toString() {
            return "Person";
        }
    }

    static class Student extends Person {
        @Override
        public String toString() {
            return "Student";
        }
    }

    static class GraduateStudent extends Student {
        // Inherits Student's toString()
    }
}





