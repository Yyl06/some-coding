/*Lab Skill 3 - Question 3
Name : Yong Yuan Lin
Date : 11 September 2025*/

import java.util.Scanner;

public class LabSkill3Question3{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first string: ");
        String str1 = sc.nextLine();
        System.out.print("Enter second string: ");
        String str2 = sc.nextLine();

        if (str1.equals(str2)) {
            System.out.println("The two strings are equal (case sensitive).");
        } else {
            System.out.println("The two strings are NOT equal (case sensitive).");
        }
    }
}