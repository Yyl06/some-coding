#pragma once
#include <iostream>
using std::string, std::cout;

class Book{
    protected:
        string Title, Author;
        bool Availability;

    public:
        Book(string t, string a) : Title(t), Author(a), Availability(false){};

        virtual void DisplayInfo(){
            cout << "Title: " << Title << ", Author: " << Author;
            cout << (Availability ? " (Borrowed)\n" : " (Available)\n");
        };

        string getTitle(){ return Title; }
        string getAuthor(){ return Author; }
        bool statusBook(){ return Availability; }
        virtual bool bookAvailability(){ return true; }
        void borrowBook(){
            if(bookAvailability()){
                Availability = true;
            }
        }
        void returnBook(){ Availability = false; }
        virtual ~Book() = default;
        friend class Librarian;
};

class ReferenceBook : public Book{
    public:
        ReferenceBook(string t, string a) : Book(t,a) {};
        void DisplayInfo() override{
            cout << "Book unavailable." << "\n";
            cout << "Book is only for Referencing." << "\n";
            cout << "Title: " << Title << "\nAuthor: " << Author << "\n(Reference Only)";
        }
        bool bookAvailability() override{
            return false;
        }
};