#include <iostream>
#include <string>
#include "Book.hpp"
#include "Librarian.hpp"
#include "Library.hpp"
using std::string, std::cout, std::cin;

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