#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
        void Add(string title, string author, bool isReference);
        void RemoveBook(string title);
        void searchByKeyWord(string keyword);
        void Display();
        void registerUser(string username, string password, string role);
        User *loginUser(string username, string password);
        bool borrowBook(User &user, string title);
        void returnBook(User &user, string title);
        void checkOverdueBooks(User &user);
};

inline Library::Library(){
    loadFromFile();
    loadUsersFromFile();
}
inline Library::~Library(){ for(auto B : Shelf){ delete B; } }

//No return type, if no function type if specified, compiler will be so confused ass
inline void Library::saveToFile(){
    std::ofstream OutFile("Books.txt");
    //No modifications and avoid Extra copies
    for(const auto &Book : Shelf){
        OutFile << Book->getTitle() << ", " << Book->getAuthor() << ", " << Book->statusBook() << "\n";
    }
    OutFile.close();
}

inline void Library::loadFromFile(){
    std::ifstream InFile("Books.txt");
    string title, author, status;
    while(std::getline(InFile, title, ',') && std::getline(InFile, author, ',') && std::getline(InFile, status)){
        Shelf.push_back(new Book(title, author));
        if (status == "1"){
            Shelf.back()->borrowBook();
        }
    }
    InFile.close();
}

inline void Library::Add(string title, string author, bool isReference){
    if(isReference){
        Shelf.push_back(new ReferenceBook(title, author));
    }else{
            Shelf.push_back(new Book(title, author));
    }
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

inline void Library::saveUsersToFile(){
    std::ofstream OutFile("Users.txt");
    for(const auto &user : Users){
        OutFile << user.getUsername() << ", " << user.getRoles() << "\n";
    }
    OutFile.close();
}

inline void Library::loadUsersFromFile(){
    std::ifstream InFile("Users.txt");
    string username, role;
    while(std::getline(InFile, username, ',') && std::getline(InFile, role)){
        Users.emplace_back(username, "password", role); // Default password, replace with real hashing
    }
    InFile.close();
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

inline void Library::searchByKeyWord(string keyword) {
    std::cout << "Searching the Books for keyword.." << keyword << "\n";
    bool found = false;
    for (auto book : Shelf) {
        if(book->getTitle().find(keyword) != string::npos ||
            book->getAuthor().find(keyword) != string::npos) {
                book->DisplayInfo();
                found = true;
            }
    }if(!found){
        cout << "Book not found.\n";
    }
}

inline void Library::Display(){
    for(const auto &it : Shelf){
        it->DisplayInfo();
    }
}

inline bool Library::borrowBook(User &user, string title){
    if(user.History.size() >= 3){
        std::cout << "You have reached the borrowing limit (3 books).\n";
        return false;
    }if (user.hasBook(title)) {
        cout << "You already borrowed this book.\n";
        return false;
    }else{
        for(auto book : Shelf){
            if(book->getTitle() == title && book->statusBook() == false){
                book->borrowBook();
                user.borrowBook(title);
                saveToFile();
                cout << "Book borrowed successfully.\n";
                return true;
            }
        }
    }
    cout << "Book not available for borrowing.\n";
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

inline void Library::checkOverdueBooks(User &user){
    user.checkOverDueBook();
}