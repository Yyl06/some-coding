#include <iostream>
using namespace std;

int main() {
    Library library;
    User* loggedInUser = nullptr;

    while (true) {  // Keep the whole system running
        int choice, chars;
        string title, author, username, password, role;

        // Login/Register loop
        while (!loggedInUser) {  // Loop until user logs in
            cout << "1. Register User\n2. Login User\n";
            cout << "Choice: ";

            if (!(cin >> chars)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter a number.\n";
                continue;
            }
            cin.ignore();

            switch (chars) {
                case 1: {  // Register User
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
                case 2: {  // Login
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
                default:
                    cout << "Invalid choice! Enter 1 or 2.\n";
            }
        }

        // Main menu loop
        while (loggedInUser) {
            cout << "\nLibrary System:\n";
            cout << "1. Add Book\n2. Add Reference Book\n3. Remove Book\n4. Search Book\n"
                    "5. Borrow Book\n6. Return Book\n7. Display Books\n8. Logout\n9. Exit\nChoice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter a number.\n";
                continue;
            }
            cin.ignore();  // Clear newline

            switch (choice) {
                case 1: // Add Book
                case 2: // Add Reference Book
                case 3: // Remove Book
                    if (loggedInUser->getRole() != "Librarian") {
                        cout << "Access denied! Only librarians can manage books.\n";
                        break;
                    }
                    cout << "Enter title: ";
                    getline(cin, title);
                    if (choice == 1 || choice == 2) {
                        cout << "Enter author: ";
                        getline(cin, author);
                        library.addBook(title, author, choice == 2); // True for ReferenceBook
                    } else {
                        library.removeBook(title);
                    }
                    break;
                case 4: // Search Book
                    cout << "Enter keyword to search: ";
                    getline(cin, title);
                    library.searchByKeyWord(title);
                    break;
                case 5: // Borrow Book
                case 6: // Return Book
                    cout << "Enter book title: ";
                    std::getline(cin, title);
                    if (choice == 5)
                        library.borrowBook(*loggedInUser, title);
                    else
                        library.returnBook(*loggedInUser, title);
                    break;
                case 7: // Display Books
                    library.Display();
                    break;
                case 8: // Logout
                    cout << "Logged out successfully.\n";
                    loggedInUser = nullptr;  // Forces return to login loop
                    break;
                case 9: // Exit
                    cout << "Exiting system...\n";
                    return 0;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
}
