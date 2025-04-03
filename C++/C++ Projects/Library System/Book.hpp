#pragma once
#include <iostream>
#include <ctime>
#include "Users.hpp"
using std::string;
using std::cout;
//Syahmi + Yuan Lin
class Book{
    protected:
        string Title;
        string Author;
        bool Availability;
        time_t dueDate;

    public:
        Book(string t, string a) : Title(t), Author(a), Availability(false), dueDate(0){};
        virtual void DisplayInfo(){
            cout << "Title: " << Title << ", Author: " << Author;
            if(Availability){
                cout << " (Borrowed, Due: " << ctime(&dueDate) << ")\n";
            }
            cout << " (Available)\n";
        }
        string getTitle(){ return Title; }
        string getAuthor(){ return Author; }
        bool statusBook(){ return Availability; }
        virtual bool bookAvailability(){ return true; }
        void borrowBook(){
            if(bookAvailability()){
                Availability = true;
                dueDate = time(0) + (maxBorrowDays * 86400);
            }
        }
        void returnBook(){ Availability = false; dueDate = 0; }
        friend class Librarian;
};

class ReferenceBook : public Book{
    public:
        ReferenceBook(string t, string a) : Book(t,a) {};
        void DisplayInfo() override{
            cout << "Title: " << Title << "\nAuthor: " << Author << "(Reference Only)\n";
        }
        bool bookAvailability() override{ return false; }
};