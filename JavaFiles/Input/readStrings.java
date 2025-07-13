import java.util.Scanner;

public class readStrings {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter a string value: ");
        while (!scanner.hasNextLine()) {
            System.out.println("Invalid input. Please enter a valid string value.");
            scanner.next(); // Clear the invalid input
            System.out.print("Please enter a string value: ");
        }
        String value = scanner.nextLine();
        System.out.println("You entered: " + value);

        scanner.close();
    }
}
