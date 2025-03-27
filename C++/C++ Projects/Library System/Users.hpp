#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <ctime>
using std::string;

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
    borrowedBooks[title] = now;
    History.push_back(title);
    std::cout << "Book '" << title << "' borrowed successfully!\n";
}

inline void User::returnBook(string title) {
    auto it = borrowedBooks.find(title);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it); // Remove book from borrowed list
        std::cout << "Book returned successfully: " << title << "\n";
    } else {
        std::cout << "You haven't borrowed this book.\n";
    }
}

inline void User::checkOverDueBook() {
    time_t now = time(0);
    bool overdueFound = false;
    
    std::cout << "Checking overdue books...\n";
    for (const auto& book : borrowedBooks) {
        double daysPassed = difftime(now, book.second) / (60 * 60 * 24); // Convert seconds to days
        if (daysPassed > maxBorrowDays) {
            overdueFound = true;
            double fine = (daysPassed - maxBorrowDays) * lateFeePerDay;
            std::cout << "Overdue: " << book.first << " | Days overdue: " << (daysPassed - maxBorrowDays) << " | Fine: $" << fine << "\n";
        }
    }
    
    if (!overdueFound) {
        std::cout << "No overdue books!\n";
    }
}

inline bool User::hasBook(const string &title) {
    return borrowedBooks.find(title) != borrowedBooks.end();
}