#pragma once
#include "Book.hpp"
#include "Library.hpp"
#include "Users.hpp"

class Librarian {
    public:
        void changeBookStatus(Book &b, bool status) {
            b.Availability = status;
        }
    
        void addBook(Library &lib, Book* b) {
            lib.Add(b->getTitle(), b->getAuthor(), dynamic_cast<ReferenceBook*>(b) != nullptr);
            std::cout << "Book added to the library.\n";
        }
    
        void removeBook(Library &lib, string title) {
            lib.RemoveBook(title); // Just call Library’s function
        }
        
    };
    