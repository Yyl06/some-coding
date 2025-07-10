import java.util.Scanner;

public class readChar{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter a character: ");
        while (!scanner.hasNext()) {
            System.out.println("Invalid input. Please enter a valid character.");
            scanner.next(); // Clear the invalid input
            System.out.print("Please enter a character: ");
        }
        String input = scanner.next();
        char value = input.charAt(0);
        System.out.println("You entered: " + value);
        
        scanner.close();
    }
}
