#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.hpp"
#include "Users.hpp"
using std::cout;

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
        void SearchBook(string title);
        void searchByKeyWord(string keyword);
        void Display();
        void registerUser(string username, string password, string role);
        User *loginUser(string username, string password);
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
    while(std::getline(InFile, title,',') && std::getline(InFile, author, ',') && std::getline(InFile, status)){
        Shelf.push_back(new Book(title, author));
        if (status == "1"){
            Shelf.back()->borrowBook();
        }
        InFile.close();
    }
}

inline void Library::Add(string title, string author, bool isReference){
    Shelf.push_back(new Book(title, author));
    saveToFile();
    cout << "Book Added Successfully! " << "\n";
}

inline void Library::RemoveBook(string title){
    for(auto it = Shelf.begin() ; it != Shelf.end(); ++it){
        if((*it)->getTitle() == title){
            delete *it;
            Shelf.erase(it);
            saveToFile();
            std::cout << "Book Removed Successfully." << "\n";
            return;
        }
    }
    cout << "Book Not Found.";
}

inline void Library::SearchBook(string title) {
    for (auto book : Shelf) {
        if (book->getTitle() == title) {
            book->DisplayInfo();
            return;
        }
    }
    cout << "Book not found.\n";
}

inline void Library::Display(){
    for(const auto &it : Shelf){
        it->DisplayInfo();
    }
}