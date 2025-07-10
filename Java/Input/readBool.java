public class readBool {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        System.out.print("Please enter a boolean value (true/false): ");
        while (!scanner.hasNextBoolean()) {
            System.out.println("Invalid input. Please enter a valid boolean value (true/false).");
            scanner.next(); // Clear the invalid input
            System.out.print("Please enter a boolean value (true/false): ");
        }
        boolean value = scanner.nextBoolean();
        System.out.println("You entered: " + value);

        scanner.close();
    }
}
