#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.hpp"
#include "Librarian.hpp"

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

inline Library::Library(){
    loadFromFile();
}

inline Library::~Library(){
    for(auto Book : Shelf){ delete Book; }
}

//No return type, if no function type if specified, compiler will be so confused ass
inline void Library::saveToFile(){
    std::ofstream OutFile("Books.txt");
    //No modifications and avoid Extra copies
    for(const auto &Book : Shelf){
        OutFile << Book->getTitle() << ", " << (Book->bookAvailability() ? "1" : "0") << "\n";
    }
    OutFile.close();
}

inline void Library::loadFromFile(){
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

inline void Library::Add(string &title, string &author){
    Shelf.push_back(new Book(title, author));
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

inline void Library::AddReferenceBook(string &title, string &author){
    Shelf.push_back(new ReferenceBook(title, author));
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

inline void Library::RemoveBook(string &Title){
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

inline void Library::SearchBook(string &Title) {
    for (auto book : Shelf) {
        if (book->getTitle() == Title) {
            book->DisplayInfo();
            return;
        }
    }
    cout << "Book not found.\n";
}

inline void Library::BorrowBook(string &Title) {
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

inline void Library::ReturnBook(string &Title){
    for(auto &Book : Shelf){
        if(Book->getTitle() == Title && Book->bookAvailability()){
            Book->returnBook();
            saveToFile();
            return;
        }
    }
    cout << "Book not found or wasnt borrowed." << "\n";
}

inline void Library::Display(){
    for(const auto &it : Shelf){
        it->DisplayInfo();
    }
}