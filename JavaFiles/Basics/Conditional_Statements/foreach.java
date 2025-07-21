public class foreach {
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5};

        System.out.println("Array elements:");
        for (int number : numbers) {
            System.out.print(number + " ");
        }
        System.out.println();

        int sum = 0;
        for (int number : numbers) {
            sum += number;
        }
        System.out.println("Sum of array elements: " + sum);
    }
}
