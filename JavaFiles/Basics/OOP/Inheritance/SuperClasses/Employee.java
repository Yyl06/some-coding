package OOP.Inheritance.SuperClasses;

public class Employee extends Person{
    public Employee() {
        this("Invoke Emp’s overloaded constructor");
        System.out.println("Emp's no-arg constructor is invoked");
    }
    public Employee(String s) {
        System.out.println(s);
    }
}
