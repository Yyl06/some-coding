import java.util.Scanner;

public class Switches{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.println("Enter your Result status: ");
        String grade = input.nextLine();

        switch (grade){
            case "Pass":
                System.out.println("You passed the test");
                break;
            
            default:
                System.out.println("You Failed.");
        }

        input.close();
    }
}
