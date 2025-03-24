#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::string, std::cout, std::cin;

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

class Librarian{
    public:
        static void changeBookStatus(Book &b, bool status){
            b.Availability = status;
        }
};

class Library{
    private:
        std::vector<Book*>Shelf;
        void saveToFile();
        void loadFromFile();
    public:
        Library();
        void Add(string &Title, string &Author);
        void AddReferenceBook(string &title, string &Author);
        void RemoveBook(string &Title);
        void SearchBook(string &Title);
        void BorrowBook(string &Title);
        void ReturnBook(string &Title);
        void Display();
        ~Library();
};

Library::Library(){
    loadFromFile();
}

Library::~Library(){
    for(auto Book : Shelf){ delete Book; }
}

//No return type, if no function type if specified, compiler will be so confused ass
void Library::saveToFile(){
    std::ofstream OutFile("Books.txt");
    //No modifications and avoid Extra copies
    for(const auto &Book : Shelf){
        OutFile << Book->getTitle() << ", " << (Book->bookAvailability() ? "1" : "0") << "\n";
    }
    OutFile.close();
}

void Library::loadFromFile(){
    std::ifstream InFile("Books.txt");
    string title, author;
    bool status;
    while(InFile >> std::ws , std::getline(InFile, title,',') && InFile >> status){
        Book* b = new Book(title, "Unknown");
        if (status){
            b->borrowBook();
        }
        Shelf.push_back(b);
    }
}

void Library::Add(string &title, string &author){
    Shelf.push_back(new Book(title, author));
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

void Library::AddReferenceBook(string &title, string &author){
    Shelf.push_back(new ReferenceBook(title, author));
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

void Library::RemoveBook(string &Title){
    for(auto it = Shelf.begin() ; it != Shelf.end(); ++it){
        if((*it)->getTitle() == Title){
            delete *it;
            Shelf.erase(it);
            saveToFile();
            std::cout << "Book Removed Successfully." << "\n";
            return;
        }
    }
    cout << "Book Not Found.";
}

void Library::SearchBook(string &Title) {
    for (auto book : Shelf) {
        if (book->getTitle() == Title) {
            book->DisplayInfo();
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::BorrowBook(string &Title) {
    for (auto book : Shelf) {
        if (book->getTitle() == Title) {
            if (!book->bookAvailability()) {
                cout << "This is a reference book and cannot be borrowed.\n";
                return;
            }
            if (!book->statusBook()) {
                book->borrowBook();
                saveToFile();
                cout << "You borrowed the book!\n";
                return;
            }
        }
    }
    cout << "Book not available or not found.\n";
}

void Library::ReturnBook(string &Title){
    for(auto &Book : Shelf){
        if(Book->getTitle() == Title && Book->bookAvailability()){
            Book->returnBook();
            saveToFile();
            return;
        }
    }
    cout << "Book not found or wasnt borrowed." << "\n";
}

void Library::Display(){
    for(const auto &it : Shelf){
        it->DisplayInfo();
    }
}


int main(){
    Library System;
    int choice;
    string title,author;

    while (true) {
        cout << "\nLibrary System:\n";
        cout << "1. Add Book\n2. Add Reference Book\n3. Remove Book\n4. Search Book\n5. Borrow Book\n6. Return Book\n7. Display Books\n8. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter title: "; getline(cin, title);
                cout << "Enter author: "; getline(cin, author);
                System.Add(title, author);
                break;
            case 2:
                cout << "Enter title: "; getline(cin, title);
                cout << "Enter author: "; getline(cin, author);
                System.AddReferenceBook(title, author);
                break;
            case 3:
                cout << "Enter title: "; getline(cin, title);
                System.RemoveBook(title);
                break;
            case 4:
                cout << "Enter title: "; getline(cin, title);
                System.SearchBook(title);
                break;
            case 5:
                cout << "Enter title: "; getline(cin, title);
                System.BorrowBook(title);
                break;
            case 6:
                cout << "Enter title: "; getline(cin, title);
                System.ReturnBook(title);
                break;
            case 7:
                System.Display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}