#include <iostream>
#include <ctime>

using std::string;
using std::cout;

class ATMTransac {
    int transacID;
    time_t date;
    string type;
    double amount;
    double post_balance;

public:
    ATMTransac(int ID, string t, double a, double p_b) 
        : transacID(ID), type(t), amount(a), post_balance(p_b) {
        time(&date);
    }

    void modifies() {
        cout << "Transaction ID: " << transacID << " | Type: " << type
        << " | Amount: " << amount << " | Post Balance: " << post_balance << "\n";
    }
};

class Account {
protected:
    int number;
    double balance;

public:
    Account(int n, double b) : number(n), balance(b) {}

    double getAmount() { return balance; }

    void createTransaction(string type, double amount) {
        balance += (type == "Deposit") ? amount : -amount;
        ATMTransac t(101, type, amount, balance);
        t.modifies();
    }

    void deposit(double amount) {
        createTransaction("Deposit", amount);
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            createTransaction("Withdraw", amount);
        } else {
            cout << "Insufficient balance.\n";
        }
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int n, double b) : Account(n, b) {}

    void withdraw(double amount) override {
        if (balance >= amount) {
            createTransaction("Savings Account Withdrawal", amount);
        } else {
            cout << "Insufficient amount in Savings Account!\n";
        }
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(int n, double b) : Account(n, b) {}

    void withdraw(double amount) override {
        if (balance >= amount) {
            createTransaction("Current Account Withdrawal", amount);
        } else {
            cout << "Insufficient amount in Current Account!\n";
        }
    }
};

class Customer {
    string name;
    string address;
    string dob;
    int cardNumber;
    int pin;
    Account *account;

public:
    Customer(string n, string a, string d, int c, int p, Account *acc)
        : name(n), address(a), dob(d), cardNumber(c), pin(p), account(acc) {}

    void verifypassword() { cout << "Password verified for " << name << ".\n"; }

    void display() {
        cout << "Customer Name: " << name << "\nAccount Balance: " << account->getAmount() << "\n";
    }
};

class Bank {
    int code;
    string address;

public:
    Bank(int c, string a) : code(c), address(a) {}

    void manages() { cout << "Bank manages accounts and ATMs.\n"; }
    void maintains() { cout << "Bank maintains financial records.\n"; }
};

class ATM {
    string location;
    string managedby;

public:
    ATM(string l, string mb) : location(l), managedby(mb) {}

    void identifies() { cout << "ATM located at " << location << " identified.\n"; }
    void transactions() { cout << "ATM processing transactions.\n"; }
};

int main() {
    // Creating objects based on UML
    Bank bank(12345, "123 Bank Street");
    ATM atm("Downtown", "Bank XYZ");

    // Creating accounts
    SavingsAccount savings(1001, 1000);
    CurrentAccount current(2002, 500);

    // Creating customer
    Customer customer("John Doe", "456 Elm St", "01-01-1990", 987654, 1234, &savings);

    // Display initial info
    customer.display();
    bank.manages();
    atm.identifies();

    // Perform transactions
    savings.deposit(500);
    current.withdraw(200);

    return 0;
}
