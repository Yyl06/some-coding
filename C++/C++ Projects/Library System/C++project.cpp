#include <iostream>
#include <string>
#include "Book.hpp"
#include "Librarian.hpp"
#include "Library.hpp"
#include "Users.hpp"
using std::string, std::cout, std::cin;

void Library::saveToFile() {
    std::ofstream OutFile("Books.txt");
    for (const auto &Book : Shelf) {
        OutFile << Book->getTitle() << "," << Book->getAuthor() << "," << Book->statusBook() << ","
                << (dynamic_cast<ReferenceBook*>(Book) ? "Reference" : "Normal") << "\n";
    }
    OutFile.close();
}

void Library::loadFromFile() {
    std::ifstream InFile("Books.txt");
    string title, author, status, type;
    while (std::getline(InFile, title, ',') &&
        std::getline(InFile, author, ',') &&
        std::getline(InFile, status, ',') &&
        std::getline(InFile, type)) {
        if (type == "Reference") {
            Shelf.push_back(new ReferenceBook(title, author));
        } else {
            Shelf.push_back(new Book(title, author));
        }
        if (status == "1") {
            Shelf.back()->borrowBook();
        }
    }
    InFile.close();
}

void Library::saveUsersToFile(){
    std::ofstream OutFile("Users.txt");
    for (const auto &user : Users) {
        OutFile << user.getUsername() << ", " << user.getRoles();
        for (const auto &book : user.borrowedBooks) {
            OutFile << ", " << book.first << " " << book.second; // title, dueDate
        }
        OutFile << "\n";
    }
    OutFile.close();
}

void Library::loadUsersFromFile() {
    std::ifstream InFile("Users.txt");
    string username, role, line;
    while (std::getline(InFile, line)) {
        std::istringstream iss(line);
        std::getline(iss, username, ',');
        std::getline(iss, role, ',');

        User newUser(username, "password", role);
        string bookTitle;
        time_t dueDate;
        while (iss >> bookTitle >> dueDate) { 
            newUser.borrowedBooks[bookTitle] = dueDate;
        }
        Users.push_back(newUser);
    }
    InFile.close();
}

#include <iostream>
#include "Library.hpp"

using namespace std;

int main() {
    Library library;
    int choice;
    string title, author, username;

    while (true) {
        cout << "\nLibrary System:\n";
        cout << "1. Add Book\n2. Add Reference Book\n"
        << "3. Remove Book\n4. Search Book via Keywords\n5. Borrow Book\n6. Return Book\n7. Display Books\n8. Exit\nChoice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }
        cin.ignore(); // Clear newline from buffer

        switch (choice) {
            case 1:
                cout << "Enter title: "; getline(cin, title);
                cout << "Enter author: "; getline(cin, author);
                library.Add(title, author, false);
                break;
            case 2:
                cout << "Enter title: "; getline(cin, title);
                cout << "Enter author: "; getline(cin, author);
                library.Add(title, author, true); // Reference book
                break;
            case 3:
                cout << "Enter title: "; getline(cin, title);
                library.RemoveBook(title);
                break;
            case 4:
                cout << "Enter Keyword to search: "; getline(cin, title);
                library.searchByKeyWord(title);
                break;
            case 5:
                cout << "Enter username: "; getline(cin, username);
                cout << "Enter book title: "; getline(cin, title);
                if (User* user = library.getUser(username)) {
                    library.borrowBook(*user, title);
                } else {
                    cout << "User not found!\n";
                }
                break;
            case 6:
                cout << "Enter username: "; getline(cin, username);
                cout << "Enter book title: "; getline(cin, title);
                if (User* user = library.getUser(username)) {
                    library.returnBook(*user, title);
                } else {
                    cout << "User not found!\n";
                }
                break;
            case 7:
                library.Display();
                break;
            case 8:
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}