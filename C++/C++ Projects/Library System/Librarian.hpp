#pragma once
#include "Book.hpp"

class Librarian{
    public:
        static void changeBookStatus(Book &b, bool status){
            b.Availability = status;
        }
};