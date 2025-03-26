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
        string getUsername(){ return userName; }
        string getRoles(){ return role; }
        bool authenticate(string u, string p){ return (userName == u && password == p); }
        bool canBorrow(){ return borrowedBooks.size() < borrowLimit; }
        void borrowBook(string title);
        void returnBook(string title);
        void checkOverDueBook();
        void displayHistory();
        friend class Library;
};

