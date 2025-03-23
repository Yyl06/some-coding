#include <map>
#include <string>
#include <iostream>
using std::string;
#define Out std::cout << 
#define In std::cin >> 

class Library {
  private: 
  string title;
  string author;
  bool availability;

  public:
  Library(const string &title , const string &author) : title(title), author(author), availability(true){}

  string gettitle()const{
    return title;
  }

  string getauthor()const{
    return author;
  }

  bool getavailability()const{
    return availability;
  }

  void Checkout(){
    availability = false;
  }
  void Checkin(){
    availability = true;
  }
};

std::map<string, Library> System;

void addBook(const string &title , const string &author , const string &ISBN){
  if(System.find(ISBN) == System.end()){
    System[ISBN] = Library(title , author);
    Out "Book added successfully !" << "\n";
  } else {
    Out "Book with ISBN exists." << "\n";
  }
}

void SearchBook(const string &keyword){
  bool found = false;
  for(const auto &entry : System){
    const Library &library = entry.second;
    if(library.gettitle() == keyword || library.getauthor() == keyword){
      Out "Book Found.";
      Out "Title : " << library.gettitle() << "\n" << "Author : " << library.getauthor();
      Out "ISBN : " << entry.first << "\n";
      Out "Availability : " << (library.getavailability() ? "Yes" : "No") << "\n";
      found = true;
    }
  }
  if(!found){
    Out "Book Not Found." << "\n";
  }
}

void Removebook(const string ISBN){
  if(System.erase(ISBN)){
    Out "Book Removed Successfully. " << "\n";
  }else{
    Out "Book with ISBN not found.\n";
  }
}

void CheckOutBook(const string &keyword){
    auto Book = System.find(keyword);
    if(Book != System.end()){
      if(!Book->second.getavailability()){
        Book->second.Checkout();
        Out "Book Has Checked Out.\n";
      }else{
        Out "Book Is Already Checked Out.\n";
      }
    }else{
      Out "Book Not Found.\n";
    }
  }

  void Returnbook(const string &ISBN){
     auto Book = System.find(ISBN);
    if(Book != System.end()){
      if(!Book->second.getavailability()){
        Book->second.Checkin();
        Out "Book Has Checked In.\n";
      }else{
        Out "Book Is Already Checked In/Available.\n";
      }
    }else{
      Out "Book Not Found.\n";
    }
  }

  int main(){
    int choice;
    string title,author,ISBN;

    while(true){
        Out "\nLibrary Management System\n";
        Out "1. Add Book\n";
        Out "2. Remove Book\n";
        Out "3. Search Book\n";
        Out "4. Check Out Book\n";
        Out "5. Return Book\n";
        Out "6. Exit\n";
        Out "Enter your choice: ";
        In choice;
        std::cin.ignore();

        switch (choice) {
          case 1 : 
          Out "Enter ISBN : ";
          std::getline(std::cin , ISBN);
          Out "Enter Title : ";
          std::getline(std::cin , title);
          Out "Enter Author : ";
          std::getline(std::cin , author);
          addBook(title, author, ISBN);
          break;

          case 2 :
          Out "Enter ISBN : ";
          std::getline(std::cin , ISBN);
          Out "Enter Title : ";
          std::getline(std::cin , title);
          Out "Enter Author : ";
          std::getline(std::cin , author);
          Removebook(ISBN);
          break;

          case 3 : 
          Out  "Enter keyword (title, author, or genre): ";
          std::getline(std::cin, title);
          SearchBook(title);
          break;

          case 4 : 
          Out "Enter ISBN to check out: ";
          std::getline(std::cin, ISBN);
          CheckOutBook(ISBN);
          break;

          case 5 :
          Out "Enter ISBN to return: ";
          std::getline(std::cin, ISBN);
          Returnbook(ISBN);
          break;

          case 6 :
          Out "Exiting. Thanks For Using\n";
          break;

          default:
          Out "Invalid!\n"; 
        }
    }
    return 0;
  }