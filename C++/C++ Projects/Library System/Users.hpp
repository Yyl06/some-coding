#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include "Book.hpp"
using std::string, std::cout;

const int borrowLimit = 3;
const double lateFeePerDay = 2.50;
const int maxBorrowDays = 14;

class User{
    string userName;
    string password;
    string role;
    std::vector<string> History;
    std::map<string, time_t> borrowedBooks;

    public:
        User(string u, string p, string r) : userName(u), password(p), role(r) {}
        string getUsername() const { return userName; }
        string getRoles() const { return role; }
        bool authenticate(string u, string p){ return (userName == u && password == p); }
        bool canBorrow(){ return borrowedBooks.size() < borrowLimit; }
        void borrowBook(string title);
        void returnBook(string title);
        void checkOverDueBook();
        bool hasBook(const string &title);
        friend class Library;
};


inline void User::borrowBook(string title) {
    if (borrowedBooks.size() >= borrowLimit) {
        std::cout << "Borrowing limit reached! You can only borrow up to " << borrowLimit << " books.\n";
        return;
    }
    time_t now = time(0); // Current time as borrowing timestamp
    time_t duedate = now + (maxBorrowDays * 86400);
    borrowedBooks[title] = duedate;
    std::cout << "Book '" << title << "' borrowed successfully!\n";
    std::cout << "Due date: " << ctime(&duedate);
}

inline void User::returnBook(string title) {
    auto it = borrowedBooks.find(title);
    if (it == borrowedBooks.end()) {
        std::cout << "You don't have this book.\n";
        return;
    }

    time_t now = time(0);
    if (now > it->second) { // Fix: Only charge if past due
        int daysLate = (now - it->second) / 86400;
        double fine = daysLate * lateFeePerDay;
        std::cout << "Book returned late! Fine: $" << fine << "\n";
    }

    borrowedBooks.erase(it);
    std::cout << "Book returned successfully.\n";
}

inline void User::checkOverDueBook() {
    time_t now = time(0);
    bool overdueFound = false;
    
    std::cout << "Checking overdue books...\n";
    for (const auto& book : borrowedBooks) {
        time_t dueDate = book.second;
        if (now > dueDate){
            overdueFound = true;
            int daysOverdue = (now - dueDate) / 86400; // Convert seconds to days
            double fine = daysOverdue * lateFeePerDay;
            std::cout << "Overdue: " << book.first << " | Days overdue: " << daysOverdue << " | Fine: $" << fine << "\n";
        }
    }
    if (!overdueFound) {
        std::cout << "No overdue books!\n";
    }
}


inline bool User::hasBook(const string &title) {
    return borrowedBooks.find(title) != borrowedBooks.end();
}