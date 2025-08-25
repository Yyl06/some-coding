import java.util.Scanner;
/*Lab Skill 1 - Question 4
Name        : YONG YUAN LIN
Date        : 6 AUGUST 2025*/

public class LabSkill1_Question4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter Circle's Radius: ");
        double radius = s.nextInt();
        double area = Math.PI * Math.pow(radius, 2);

        System.out.println(area);
        s.close();
    }
}
