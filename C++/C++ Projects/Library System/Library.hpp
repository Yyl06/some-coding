#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.hpp"
#include "Users.hpp"
using std::cout, std::string;

class Library{
    private:
        std::vector<Book*>Shelf;
        std::vector<User> Users;
        void saveToFile();
        void loadFromFile();
        void saveUsersToFile();
        void loadUsersFromFile();

    public:
        Library();
        ~Library();
        void registerUser(string u, string p, string r) {
            Users.push_back(User(u, p, r));
            std::cout << "User registered.\n";
        }
        User* getUser(string username) {
            for (auto &u : Users) {
                if (u.getUsername() == username) return &u;
            }
            return nullptr;
        }
        void Add(string title, string author, bool isReference);
        void RemoveBook(string title);
        void searchByKeyWord(string keyword);
        void Display();
        User *loginUser(string username, string password);
        bool borrowBook(User &user, string title);
        void returnBook(User &user, string title);
        void checkOverdueBooks(User &user);
};

inline Library::Library(){
    loadFromFile();
    loadUsersFromFile();
}
inline Library::~Library(){
    saveToFile();
    saveUsersToFile();
    for (auto B : Shelf) { delete B; }
}

//No return type, if no function type if specified, compiler will be so confused ass


inline void Library::Add(string title, string author, bool isReference){
    if(isReference){
        Shelf.push_back(new ReferenceBook(title, author));
    }else{
            Shelf.push_back(new Book(title, author));
    }
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

inline void Library::RemoveBook(string title){
    for (auto it = Shelf.begin(); it != Shelf.end(); ++it) {
        if ((*it)->getTitle() == title) {
            delete *it;
            Shelf.erase(it);
            saveToFile();
            cout << "Book Removed Successfully.\n";
            return;
        }
    }
    cout << "Book Not Found.\n";
}

inline bool Library::borrowBook(User &user, string title) {
    if (!user.canBorrow()) {
        std::cout << "You have reached the borrowing limit (3 books).\n";
        return false;
    }
    if (user.hasBook(title)) {
        std::cout << "You already borrowed this book.\n";
        return false;
    }
    for (auto book : Shelf) {
        if (book->getTitle() == title) {
            if (!book->bookAvailability()) { // Check reference book
                std::cout << "This is a reference book and cannot be borrowed.\n";
                return false;
            }
            book->borrowBook();
            user.borrowBook(title);
            saveToFile();
            std::cout << "Book borrowed successfully.\n";
            return true;
        }
    }
    std::cout << "Book not found or unavailable.\n";
    return false;
}

inline void Library::returnBook(User &user, string title){
    for(auto book :Shelf){
        if(book->getTitle() == title && book->statusBook() == true){
            book->returnBook();
            user.returnBook(title);
            saveToFile();
            return;
        }
    }
    std::cerr << "Book return failed." << '\n';
}

inline void Library::searchByKeyWord(string keyword) {
    std::cout << "Searching the Books for keyword.." << keyword << "\n";
    bool found = false;
    for (auto book : Shelf) {
        if(book->getTitle().find(keyword) != string::npos ||
            book->getAuthor().find(keyword) != string::npos) {
                book->DisplayInfo();
                found = true;
            }
    }if (keyword.empty()) {
        std::cout << "Invalid search keyword.\n";
        return;
    }
}

inline void Library::Display(){
    for(const auto &it : Shelf){
        it->DisplayInfo();
    }
}

inline void Library::checkOverdueBooks(User &user){
    user.checkOverDueBook();
}

