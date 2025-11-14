public class polymorphisn {
    public static void main(String[] args) {
        Object stud = new Student();

        if(stud instanceof Object){
            System.out.println("a");
        }else{
            System.err.println("b");
        }

        Student s = (Student) stud;
    }
}

class Student{}