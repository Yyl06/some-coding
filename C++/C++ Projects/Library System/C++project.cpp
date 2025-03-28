#include <iostream>
#include <string>
#include "Book.hpp"
#include <fstream>
#include <sstream>
#include "Library.hpp"
#include "Users.hpp"
using std::string, std::cout, std::cin, std::getline;

void Library::saveToFile() {
    std::ofstream File("Books.txt", std::ios::app);
    for (const auto &Book : Shelf) {
        File << Book->getTitle() << "," << Book->getAuthor() << "," << Book->statusBook() << ","
                << (dynamic_cast<ReferenceBook*>(Book) ? "Reference" : "Normal") << "\n";
                //use dynamic_cast when especially in cases where type safety is critical (e.g., when dealing with polymorphic classes)
    }
    File.close();
}

void Library::loadFromFile() {
    std::ifstream File("Books.txt", std::ios::in);
    string title, author, status, type;
    Shelf.clear();
    while (std::getline(File, title, ',') &&
        std::getline(File, author, ',') &&
        std::getline(File, status, ',') &&
        std::getline(File, type)) {
        if (type == "Reference") {
            Shelf.push_back(new ReferenceBook(title, author));
        } else {
            Shelf.push_back(new Book(title, author));
        }
        if (status == "1") {
            Shelf.back()->borrowBook();
        }
    }
    File.close();
}

void Library::saveUsersToFile() {
    std::ofstream File("Users.txt", std::ios::out);
    if (!File){
        std::cerr << "Error: Could not open Users.txt for writing!\n";
        return;
    }

    for (const auto &user : Users) {
        File << user.getUsername() << "," << user.getPassword() << "," << user.getRole();
        for (const auto &book : user.borrowedBooks) {
            File << "," << book.first << " " << book.second;
        }
        File << "\n";
    }
    File.close();
}


void Library::loadUsersFromFile() {
    std::ifstream File("Users.txt", std::ios::out);
    string username, role, line, pass;
    while (std::getline(File, line)) {
        std::istringstream iss(line);
        std::getline(iss, username, ',');
        std::getline(iss, pass, ',');
        std::getline(iss, role, ',');

        User newUser(username, pass, role);

        string bookTitle;
        time_t dueDate;
        while (iss >> bookTitle >> dueDate) { 
            newUser.borrowedBooks[bookTitle] = dueDate;
        }
        Users.push_back(newUser);
    }
    File.close();
}


int main() {
    Library library;
    User* loggedInUser = nullptr; // Stores the logged-in user
    int choice;
    string title, author, username, password, role;

    while (true) {
        cout << "\nLibrary System:\n";
        cout << "1. Register User\n2. Login\n3. Add Book\n4. Add Reference Book\n5. Remove Book\n6. Search Book\n7. Borrow Book\n8. Return Book\n9. Display Books\n10. Logout\n11. Exit\nChoice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }
        cin.ignore(); // Clear newline from buffer

        switch (choice) {
            case 1: { // Register User
                cout << "Enter username: ";
                std::getline(cin, username);

                cout << "Enter password: ";
                std::getline(cin, password);

                cout << "Enter role (User/Librarian): ";
                getline(cin, role);

                if (role != "User" && role != "Librarian") {
                    cout << "Invalid role! Must be 'User' or 'Librarian'.\n";
                    break;
                }

                library.registerUser(username, password, role);
                cout << "User registered successfully!\n";
                break;
            }
            case 2: { // Login
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);

                loggedInUser = library.authenticateUser(username, password);
                if (loggedInUser) {
                    cout << "Login successful! Welcome, " << loggedInUser->getUsername() << ".\n";
                } else {
                    cout << "Invalid username or password.\n";
                }
                break;
            }
            case 3: // Add Book
            case 4: // Add Reference Book
            case 5: // Remove Book
                if (!loggedInUser || loggedInUser->getRole() != "Librarian") {
                    cout << "Access denied! Only librarians can manage books.\n";
                    break;
                }
                cout << "Enter title: ";
                getline(cin, title);
                if (choice == 3 || choice == 4) {
                    cout << "Enter author: ";
                    getline(cin, author);
                    library.addBook(title, author, choice == 4); // True for ReferenceBook
                } else {
                    library.removeBook(title);
                }
                break;
            case 6: // Search Book
                cout << "Enter keyword to search: ";
                getline(cin, title);
                library.searchByKeyWord(title);
                break;
            case 7: // Borrow Book
            case 8: // Return Book
                if (!loggedInUser) {
                    cout << "Please log in first.\n";
                    break;
                }
                cout << "Enter book title: ";
                std::getline(cin, title);
                if (choice == 7)
                    library.borrowBook(*loggedInUser, title);
                else
                    library.returnBook(*loggedInUser, title);
                break;
            case 9: // Display Books
                library.Display();
                break;
            case 10: // Logout
                if (loggedInUser) {
                    cout << "Logged out successfully.\n";
                    loggedInUser = nullptr;
                } else {
                    cout << "You're not logged in.\n";
                }
                break;
            case 11: // Exit
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
