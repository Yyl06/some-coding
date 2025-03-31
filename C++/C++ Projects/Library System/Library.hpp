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
        Library(){
            loadFromFile();
            loadUsersFromFile();
        }
        ~Library(){
            saveToFile();
            saveUsersToFile();
            for (auto B : Shelf) { delete B; }
        }
        void registerUser(string u, string p, string r){
            Users.push_back(User(u, p, r));
            std::cout << "User registered.\n";
        }
        User* getUser(string username) {
            for (auto &u : Users) {
                if (u.getUsername() == username) return &u;
            }
            return nullptr;
        }
        void addBook(string title, string author, bool isReference);
        void removeBook(string title);
        void searchByKeyWord(string keyword);
        void Display();
        User *loginUser(string username, string password);
        bool borrowBook(User &user, string title);
        void returnBook(User &user, string title);
        void checkOverdueBooks(User &user);
        User* authenticateUser(const string &username, const string &password);
};


inline void Library::Display(){
    for(const auto &it : Shelf){
        it->DisplayInfo();
    }
}

inline void Library::checkOverdueBooks(User &user){
    user.checkOverDueBook();
}
User* Library::authenticateUser(const string &username, const string &password){
    for (auto& user : Users) { // Assuming `Users` is a vector<User>
        if (user.authenticate(username, password)) {
            return &user; // Return pointer to authenticated user
        }
    }
    return nullptr; // Return nullptr if authentication fails
}