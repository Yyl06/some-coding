import java.text.DecimalFormat;
import java.util.Scanner;

class Person{
    protected String name;
    protected String address;

    public Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public String getName(){
        return name;
    }

    public String getAddress(){
        return address;
    }

    public void setAddress(String address){
        this.address = address;
    }

    @Override
    public String toString(){
        return "Name: " + name + "\nAddress: " + address;
    }
}

class Student extends Person{
    private String program;
    private int year;
    private double fee;
    private double cgpa;

    Student(String name, String address, String program, int year, double fee, double cgpa){ 
        super(name, address); 
        this.program = program;
        this.year = year;
        this.fee = fee;
        this.cgpa = cgpa;
    }

    public String getProgram(){ return program; }
    public void setProgram(String program){ this.program = program; }
    public int getYear(){ return year; }
    public void setYear(int year){ this.year = year; }
    public double getFee(){ 
        if(cgpa >= 3.67){
            return fee * 0.75;
        }else if(cgpa >= 3.30 && cgpa <= 3.66){
            return fee * 0.8;
        }else if(cgpa >= 3.00 && cgpa <= 3.29){
            return fee * 0.85;
        }else if(cgpa >= 2.85 && cgpa <= 2.99){
            return fee * 0.9;
        }else{
            return fee;
        }
    }
    public void setFee(double fee){ this.fee = fee; }
    public double getCgpa(){ return cgpa; }
    public void setCgpa(double cgpa){ this.cgpa = cgpa; }

    @Override
    public String toString(){
        return "Name: " + name + "\nAddress: " + address + "\nProgram: " + program +
        "\nYear: " + year + "\nFee: " + fee + "\nCGPA: " + cgpa + "\nFee After Discount: ";
    }
}

class Teacher extends Person implements Comparable<Object>{
    private String school;
    private double salary;

    public Teacher(String name, String address, String school, double salary){
        super(name, address);
        this.school = school;
        this.salary = salary;
    }

    public String getSchool(){ return school; }
    public void setSchool(String school){ this.school = school; }
    public double getSalary(){ return salary; }
    public void setSalary(double salary){ this.salary = salary; }

    @Override
    public String toString(){
        DecimalFormat df = new DecimalFormat("0.00");
        return "Name: " + name + "\nAddress: " + address + "\nSchool: " + school + "\nSalary: RM" + df.format(salary);
    }

    @Override
    public int compareTo(Object o) {
        if(this.salary < ((Teacher)o).salary){
            return -1;
        }else if(this.salary > ((Teacher)o).salary){
            return 1;
        }else{
            return 0;
        }
    }
}

public class TestClass {
    public static void main(String[] args) {
        Teacher[] objectTeacher = new Teacher[10];
        Scanner sc = new Scanner(System.in);
        int count = 0, average = 0, total = 0, higher = 0, lower = 0;

        for(int i = 0; i < objectTeacher.length; i++){
            System.out.print("Enter Teacher Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Teacher Address: ");
            String address = sc.nextLine();
            System.out.print("Enter Teacher School: ");
            String school = sc.nextLine();
            System.out.print("Enter Teacher salary: ");
            double salary = sc.nextDouble();
            total += salary;
            count++;
            objectTeacher[i] = new Teacher(name, address, school, salary);
            sc.nextLine();
            System.out.println(objectTeacher[i] + "\n");
        }

        average = total/count;
        System.out.println("Total Salary for 10 teachers: " + total);
        System.out.println("Average salary: " + average);

        for(Object o : objectTeacher){
            if(((Teacher)o).getSalary() > average){
                higher++;
            }
            if(((Teacher)o).getSalary() < average){
                lower++;
            }
        }
        System.out.println("Number of Salary Higher than Average: " + higher);
        System.out.println("Number of Salary Lower than Average: " + lower);

        double highest = objectTeacher[0].getSalary();
        for(int i = 0; i < objectTeacher.length - 1; i++){
            Teacher t1 = objectTeacher[i];
            Teacher t2 = objectTeacher[i+1];
            int result = t1.compareTo(t2);
            System.out.println("Result Comparison" + result);

            if(objectTeacher[i].getSalary() > highest){
                highest = objectTeacher[i].getSalary();
            }
        }
        System.out.printf("Highest Salary: %.2f%n", highest);
    }
}