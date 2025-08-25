import java.util.Scanner;

public class Exercise4_YongYuanLin {
    public static void main(String[] args) {
        String name = "Yong Yuan Lin";
        Scanner input = new Scanner(System.in);
        int total = 0;

        System.out.println(name);
        for (int i = 1; i < 6; i++){
            System.out.print("Input " + i + ": ");
            int num = input.nextInt();
            total += num;
            System.out.println("Total number: " + total);
        }

        input.close();
    }
}