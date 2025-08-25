/*Lab Skill 2 - Question 3
Name        : Yong Yuan Lin
Date        : 21 August 2025*/


public class Employee {
    private int id;
    private String firstName;
    private String lastName;
    private double salary;

    public Employee(int id, String firstName, String lastName, double salary) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.salary = salary;
    }

    public static void main(String[] args) {
        Employee emp1 = new Employee(101, "Ahmad", "Abu Kassim", 2345.00);
        Employee emp2 = new Employee(102, "Muthu", "Ramasamy", 1230.00);
        
        
        System.out.println(emp1.toString() + "\n");
        System.out.println(emp2.toString() + "\n");

        emp1.raiseSalary(10.0);
        emp2.raiseSalary(20.0);

        System.out.println(emp1.toString() + "\n");
        System.out.println(emp2.toString() + "\n");
    }

    public int getID(){
        return id;
    }

    public String getFirstName(){
        return firstName;
    }

    public String getLastName(){
        return lastName;
    }

    public String getName(){
        return firstName + " " + lastName;
    }

    public double getSalary(){
        return salary;
    }

    public void setSalary(double salary){
        this.salary = salary;
    }

    public double getAnnualSalary(){
        return salary * 12;
    }

    public void raiseSalary(double percent){
        System.out.println(getName() + " starting salary RM " + getSalary() + " has been raised by " + percent + "%");
        setSalary(getSalary() + (getSalary() * (percent/100)));
        System.out.println("New salary is RM " + getSalary() + "\n");
    }

    @Override
    public String toString(){
        return "ID: " + id + "\nName: " + getName() + "\nSalary: " + getSalary() + "\nAnnual Salary: " + getAnnualSalary();
    }
}
