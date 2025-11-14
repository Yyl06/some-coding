/*Assignment 2 - Question 1
Name		: Yong Yuan Lin, Chung Wei Kit, Marcus Lai Wei Ze 
Date		: 10 October 2019*/

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class StateInfo{
    String name;
    double credit;

    public StateInfo(String name, double credit) {
        this.name = name;
        this.credit = credit;
    }
}

public class Billing {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Map<Character, StateInfo> freeCredit = new HashMap<>();
        freeCredit.put('K', new StateInfo("Kuala Lumpur", 15.00));
        freeCredit.put('S', new StateInfo("Selangor", 20.00));
        freeCredit.put('P', new StateInfo("Putrajaya", 18.00));
        freeCredit.put('T', new StateInfo("Terengganu", 21.00));
        freeCredit.put('L', new StateInfo("Labuan", 12.00));
        freeCredit.put('J', new StateInfo("Johor", 25.00));
        freeCredit.put('O', new StateInfo("Other State", 19.00));

        System.out.println("ELECTRO BILLING SYSTEM");
        System.out.println("======================");

        System.out.print("Enter Customer Account Number: ");
        String account = sc.nextLine();

        System.out.print("Enter Last Meter Reading in KWH: ");
        int lastReading = sc.nextInt();

        System.out.print("Enter Current Meter Reading in KWH: ");
        int currentReading = sc.nextInt();

        System.out.print("Enter Overdue Amount (if any): ");
        double overdue = sc.nextDouble();

        char stateCode = account.charAt(account.length() - 1);
        StateInfo credit = freeCredit.getOrDefault(stateCode, new StateInfo("Unknown State", 0.00));

        int usage = currentReading - lastReading;
        double currentBill = usage * 0.53;
        double amountToPay = (currentBill + overdue) - credit.credit;

        sc.close();

        System.out.println("\n\nYOUR BILL INFORMATION");
        System.out.println("=====================");
        System.out.println("Customer Account Number: " + account);
        System.out.println("State: "  + credit.name.toUpperCase());
        System.out.println("Electric Usage in KWH: " + usage);
        System.out.printf("Current Bill: %.2f%n", currentBill);
        System.out.printf("Overdue From Last Month: %.2f%n", overdue);
        System.out.printf("Free Electric Credit: %.2f%n", credit.credit);
        System.out.printf("Amount To Pay: %.2f%n", amountToPay);
    }
}