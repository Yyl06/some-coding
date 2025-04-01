#pragma once
#include "Book.hpp"
#include "Library.hpp"
#include "Users.hpp"
//Yong Hern

class Librarian {
    public:
        void changeBookStatus(Book &b, bool status) {
            b.Availability = status;
        }
    
        void addBook(Library &lib, Book* b) {
            //use dynamic_cast when especially in cases where type safety is critical (e.g., when dealing with polymorphic classes)
            lib.addBook(b->getTitle(), b->getAuthor(), dynamic_cast<ReferenceBook*>(b) != nullptr);
            std::cout << "Book added to the library.\n";
        }
    
        void removeBook(Library &lib, string title) {
            lib.removeBook(title); // Just call Library’s function
        }
    };