#pragma once
#include <map>
#include <iostream>
#include <ctime>
#include "Book.hpp"
using std::string, std::cout;
//Xuan Hui

const int borrowLimit = 3;
const double lateFeePerDay = 2.50;
const int maxBorrowDays = 14;

class User{
    string userName;
    string password;
    string role;
    std::map<string, time_t> borrowedBooks;

    public:
        User(string u, string p, string r) : userName(u), password(p), role(r){}
        string getUsername() const { return userName; }
        string getPassword() const { return password; }
        string getRoles() const { return role; }
        bool authenticate(string u, string p){ return (userName == u && password == p); }
        bool canBorrow(){ return borrowedBooks.size() < borrowLimit; }
        void borrowBook(string title);
        bool returnBook(string title);
        void checkOverDueBook();
        bool hasBook(const string &title);
        string getRole() const { return role; }
        friend class Library;
};

inline bool User::hasBook(const string &title){
    return borrowedBooks.find(title) != borrowedBooks.end();
}