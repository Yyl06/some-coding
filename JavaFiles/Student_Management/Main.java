package Student_Management;
import java.util.Scanner;

import Student_Management.Course.Course;
import Student_Management.Student.Student;
import Student_Management.StudentManager.StudentManager;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentManager manager = new StudentManager();

        while(true){
            System.out.println("\n--- Student Management Menu ---");
            System.out.println("1. Add Student");
            System.out.println("2. Remove Student");
            System.out.println("3. View All Students");
            System.out.println("4. Find Student by ID");
            System.out.println("5. Exit");
            System.out.print("Choice: ");
            int choice = sc.nextInt();

            switch(choice){
                case 1->{
                    System.out.print("Id: ");
                    int id = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Name: ");
                    String name = sc.nextLine();
                    System.out.print("Age: ");
                    int age = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Matric: ");
                    String Matric = sc.nextLine();
                    System.out.print("Course ID: ");
                    int courseID = sc.nextInt();
                    Course course = manager.findCourse(courseID);
                    if(course == null){
                        System.out.println("Course not found.");
                    }else{
                        Student s = new Student(id, name, Matric, age, course);
                        manager.addStudent(s);
                    }
                    break;
                }

                case 2->{
                    System.out.print("Enter Id to Remove: ");
                    int removeID = sc.nextInt();
                    sc.nextLine();
                    manager.removeStudent(removeID);
                    break;
                }

                case 3->{
                    manager.displayAllStudents();
                    break;
                }

                case 4->{
                    System.out.print("Enter Id to search: ");
                    int id = sc.nextInt();
                    manager.findStudent(id);
                    break;
                }

                case 5->{
                    System.out.println("Goodbye!");
                    sc.close();
                    return;
                }

                default->{
                    System.out.println("Invalid choice. Try again.");
                }
            }
        }
    }
}
