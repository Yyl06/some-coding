public class readFloat {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        System.out.print("Please enter a float value: ");
        while (!scanner.hasNextFloat()) {
            System.out.println("Invalid input. Please enter a valid float value.");
            scanner.next(); // Clear the invalid input
            System.out.print("Please enter a float value: ");
        }
        float value = scanner.nextFloat();
        System.out.println("You entered: " + value);

        scanner.close();
    }
}
