/*Lab Skill 3 - Question 2
Name : Yong Yuan Lin
Date : 11 September 2025*/

import java.util.Scanner;

public class LabSkill3Question2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first name: ");
        String firstName = sc.nextLine();
        System.out.print("Enter last name: ");
        String lastName = sc.nextLine();
        System.out.println("Length of firstName: " + firstName.length());
        System.out.println("Length of lastName: " + lastName.length());

        if (firstName.equals(lastName)) {
            System.out.println("Same value entered for firstName and lastName");
        }

        System.out.println("Lowercase firstName: " + firstName.toLowerCase());
        System.out.println("Lowercase lastName: " + lastName.toLowerCase());
        System.out.println("Uppercase firstName: " + firstName.toUpperCase());
        System.out.println("Uppercase lastName: " + lastName.toUpperCase());
    }
}