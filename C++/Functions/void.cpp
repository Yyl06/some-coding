#include <iostream>
#include <iomanip>

// Function to show balance
void showbalance(double balance) {
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

// Function to deposit money
double deposit(double balance) {
    double amount = 0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if (amount > 0) {
        balance += amount;
        return balance;
    } else {
        std::cout << "That's not a valid amount.\n";
        return balance;
    }
}

// Function to withdraw money
double showwithdraw(double balance) {
    double amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;

    if (amount > balance) {
        std::cout << "Insufficient funds.\n";
        return balance;
    } else if (amount < 0) {
        std::cout << "That's not a valid amount.\n";
        return balance;
    } else {
        balance -= amount;
        return balance;
    }
}

int main() {
    double balance = 0;
    bool choice = true;
    char op;

    do {
        // Display menu
        std::cout << "\n************ Welcome to Wealthy Bank ************\n";
        std::cout << "Please select an action:\n";
        std::cout << "(A) Check Balance\n(B) Deposit\n(C) Withdrawal\n(D) Exit\n";
        std::cout << "Your Choice: ";
        std::cin >> op;

        switch (op) {
            case 'A':
            case 'a':
                showbalance(balance);
                break;

            case 'B':
            case 'b': {
                balance = deposit(balance); // Update balance after deposit
                break;
            }

            case 'C':
            case 'c': {
                balance = showwithdraw(balance); // Update balance after withdrawal
                break;
            }

            case 'D':
            case 'd':
                std::cout << "Thank you for using Wealthy Bank. Goodbye!\n";
                choice = false;
                break;

            default:
                std::cout << "Please enter a valid option.\n";
                break;
        }
    } while (choice);

    return 0;
}

