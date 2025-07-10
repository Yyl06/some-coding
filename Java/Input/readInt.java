import java.util.Scanner;

public class readInt {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);

        System.out.print("Please enter an integer value: ");
        while (!x.hasNextInt()) {
            System.out.println("Invalid input. Please enter a valid integer value.");
            x.next(); // Clear the invalid input
            System.out.print("Please enter an integer value: ");
        }
        int value = x.nextInt();
        System.out.println("You entered: " + value);

        x.close();
    }
}
