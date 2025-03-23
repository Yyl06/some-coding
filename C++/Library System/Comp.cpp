#include <iostream>
#include <string>
using std::string;

const int Maximum = 100;

string Title[Maximum];
string Author[Maximum];
string Genre[Maximum];
string ISBNs[Maximum];
bool AVAILABILITY[Maximum];
int TotalBooks = 0;

void addBooks(string title , string author , string genre , string ISBN){
    if(TotalBooks < Maximum){
        Title[TotalBooks] = title;
        Author[TotalBooks] = author;
        Genre[TotalBooks] = genre;
        ISBNs[TotalBooks] = ISBN;
        AVAILABILITY[TotalBooks] = true;
        TotalBooks++;
        std::cout << "Book added successfully! " << "\n";
    }else{
        std::cout << "Library is full." << "\n";
    }
}

void removeBooks(string ISBN){
    for(int i = 0 ; i < TotalBooks ; i++){
        if(ISBNs[i] == ISBN){
            for(int j = i ; j < TotalBooks - 1 ; j++){
                Title[j] = Title[j+1];
                Author[j] = Author[j+1];
                Genre[j] = Genre[j+1];
                ISBNs[j] = ISBNs[j+1];
                AVAILABILITY[j] = AVAILABILITY[j+1];
            }
            TotalBooks--;
            std::cout << "Book Removed successfully ! " << "\n";
            return;
        }
    }
    std::cout << "Book with ISBN " << ISBN << "is not found." << "\n";
}

void checkBook(string keyword){
    bool found = false;
    for (int i = 0 ; i < TotalBooks ; i++){
        if(Title[i] == keyword || Author[i] == keyword || Genre[i] == keyword){
            std::cout << "Book Found." << "\n";
            std::cout << "Title : " << Title[i] << "\n" << "Author : " << Author[i] << "\n" << "Genre : " << Genre[i] << "\n";
            std::cout << "ISBN : " << ISBNs[i] << "\n";
            std::cout << "Availability : " << (AVAILABILITY[i] ? "Yes" : "No") << "\n";
            found = true;
        }
    }
    if(!found){
        std::cout << "No Books Found Matching the Keyword Given." << "\n";
    }
}

void Checkout(string ISBN){
    for (int i = 0 ; i < TotalBooks ; i++){
        if(ISBNs[i] == ISBN){
            if(AVAILABILITY[i]){
                AVAILABILITY[i]=false;
                std::cout << "Book Checked Out Successfully !" << "\n";
            }else{
                std::cout << "Book Is Checked Out." << "\n";
            }
            return;
        }
    }
    std::cout << "Book Not Found. " << "\n";
}

void Checkin(string ISBN){
    for (int i = 0 ; i < TotalBooks ; i++){
        if(ISBNs[i] == ISBN){
            if(!AVAILABILITY[i]){
                AVAILABILITY[i]=true;
                std::cout << "Book Checked In Successfully !" << "\n";
            }else{
                std::cout << "Book Is Not Checked In." << "\n";
            }
            return;
        }
    }
    std::cout << "Book Not Found. " << "\n";
}

void PrintAllBooks(){
    for(int i = 0 ; i < TotalBooks ; i++){
        std::cout << "Title : " << Title[i] << "\n";
        std::cout << "Author : " << Author[i] << "\n";
        std::cout << "Genre : " << Genre[i] << "\n";
        std::cout << "ISBN : " << ISBNs[i] << "\n";
        std::cout << "Availability : " << (AVAILABILITY[i] ? "Yes" : "No") << "\n";
    }
}
int main(){
    int choice;
    string title , author , genre , ISBN;


    while(true){
    std::cout << "\033[32mLibrary Management System" << "\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Search Book\n";
    std::cout << "4. Check Out Book\n";
    std::cout << "5. Return Book\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    std::cout << "\033[0m";

    switch(choice){
        case 1 :
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);
        std::cout << "Enter author name: ";
        std::getline(std::cin, author);
        std::cout << "Enter genre: ";
        std::getline(std::cin, genre);
        std::cout << "Enter ISBN: ";
        std::getline(std::cin, ISBN);
        addBooks(title, author, genre, ISBN);
        break;

        case 2 : 
        std::cout << "Enter the ISBN Code to remove : ";
        std::getline(std::cin, ISBN);
        removeBooks(ISBN);
        break;

        case 3 :
        std::cout << "Enter a keyword : ";
        std::getline(std::cin , title);
        checkBook(title);
        break;

        case 4 :
        std::cout << "Enter ISBN of the book : ";
        std::getline(std::cin , ISBN);
        Checkout(ISBN);
        break;

        case 5 :
        std::cout << "Enter ISBN of the book : ";
        std::getline(std::cin , ISBN);
        Checkin(ISBN);
        break;

        case 6 :
        std::cout << "Thanks for using !" << "\n";
        return 0;

        default : 
        std::cerr << "Invalid !" << "\n";
        return 0;
    }
    }
}