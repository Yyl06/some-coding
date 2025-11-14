import java.util.Scanner;

public class test{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int[] numbers = new int[5];
        int total = 0, count = 0;
        for(int number : numbers){
            System.out.print("Enter Numbers: ");
            number = input.nextInt();
            total += number;
            count++;
        }
        double average = total/count;
        System.out.println("Average numbers: " + average);

        input.close();
    }
}