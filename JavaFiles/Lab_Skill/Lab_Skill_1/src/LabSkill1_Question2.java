/*Lab Skill 1 - Question 2
Name		: YONG YUAN LIN
Date		: 6 AUGUST 2025*/
import java.util.Scanner;

public class LabSkill1_Question2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Enter the novel name you want to purchase: ");
        String bookName = s.nextLine();

        System.out.println("Thanks for purchasing " + bookName);

        s.close();
    }
}
