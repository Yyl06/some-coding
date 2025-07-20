//Not Used, Outdated
package Student_Management;
import java.util.Scanner;

import Student_Management.Course.Course;
import Student_Management.Student.Student;
import Student_Management.StudentManager.StudentManager;
import static Syntaxes.println.print;
import static Syntaxes.println.printline;
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        StudentManager manager = new StudentManager();

        while(true){
            printline("\n--- Student Management Menu ---");
            printline("1. Add Student");
            printline("2. Remove Student");
            printline("3. View All Students");
            printline("4. Find Student by ID");
            printline("5. Exit");
            print("Choice: ");
            int choice = sc.nextInt();

            switch(choice){
                case 1->{
                    print("Id: ");
                    int id = sc.nextInt();
                    sc.nextLine();
                    print("Name: ");
                    String name = sc.nextLine();
                    print("Age: ");
                    int age = sc.nextInt();
                    sc.nextLine();
                    print("Matric: ");
                    String Matric = sc.nextLine();
                    print("Course ID: ");
                    int courseID = sc.nextInt();
                    Course course = manager.findCourse(courseID);
                    if(course == null){
                        printline("Course not found.");
                    }else{
                        Student s = new Student(id, name, Matric, age, course);
                        manager.addStudent(s);
                    }
                    break;
                }

                case 2->{
                    print("Enter Id to Remove: ");
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
                    print("Enter Id to search: ");
                    int id = sc.nextInt();
                    manager.findStudent(id);
                    break;
                }

                case 5->{
                    printline("Goodbye!");
                    sc.close();
                    return;
                }

                default->{
                    printline("Invalid choice. Try again.");
                }
            }
        }
    }
}
