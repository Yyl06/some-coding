package OOP.Inheritance.SuperClasses;

public class Faculty extends Employee{
    public static void main(String[] args) {
        Faculty f = new Faculty();
    }
    
    public Faculty() {
        System.out.println("Faculty's no-arg constructor is invoked");
    }
}
