package Student;
import Course.Course;

public class Student{
    private int id;
    private String name;
    private String Matric;
    private int age;
    private Course course;

    public Student(int id, String name, String Matric, int age, Course course){
        this.id = id;
        this.name = name;
        this.Matric = Matric;
        this.age = age;
        this.course = course;
    }

    public int getId(){ return id; }
    public void setId(int id){ this.id = id; }
    public String getName(){ return name; }
    public void setName(String name){ this.name = name; }
    public String getMatric(){ return Matric; }
    public void setMatric(String Matric){ this.Matric = Matric; }
    public int getAge(){ return age; }
    public void setAge(int age){ this.age = age; }
    public Course getCourse(){ return course; }
    public void setCourse(Course course){ this.course = course; }

    public void displayInfo(){
        System.out.println("Student Info: \n" + "id: " + id + "\nName: " + name + "\nMatric: " + Matric + "\nAge: " + age + "\nCourse: " + course);
    }
}
