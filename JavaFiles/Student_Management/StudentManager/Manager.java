package Student_Management.StudentManager;
import Student_Management.Student.Student;
import java.util.ArrayList;

public class Manager {
    private ArrayList<Student> students = new ArrayList<>();

    public void addStudent(Student s){
        students.add(s);
        System.out.println("Student Added Sucessfully!");
    }

    public void removeStudent(int id){
        students.removeIf(s -> s.getId() == id);
        System.out.println("Student Removed Sucessfully!");
    }

    public void displayAllStudents(){
        if(students.isEmpty()){
            System.out.println("No Students Found.");
        }else{
            for(Student s : students){
                s.displayInfo();
            }
        }
    }

    public void findStudent(int id){
        if(students.isEmpty()){
            System.out.println("No Students Found. No Students in the list.");
        }else{
            for(Student s : students){
                if(s.getId() == id){
                    s.displayInfo();
                    return;
                }
            }
        }
    }
}
