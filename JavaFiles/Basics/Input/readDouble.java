import java.util.Scanner;

public class readDouble {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);

        System.out.print("Please enter a double value: ");
        while (!x.hasNextDouble()) {
            System.out.println("Invalid input. Please enter a valid double value.");
            x.next(); // Clear the invalid input
            System.out.print("Please enter a double value: ");
        }
        double value = x.nextDouble();
        System.out.println("You entered: " + value);

        x.close();
    }
}
