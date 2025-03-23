//Name : YONG YUAN LIN(A24DW0325)
//Topic : Data Library
//Assignment 1 : List Array

#include <iostream>
#include <string>
using std::string;

const int size = 100;
string book[size];
static int count = 0;

void add(){
    if(count == 0){
        std::cout << "this book will be adding at beginning" << std::endl;
        std::cout << "please enter title of the book" << std::endl;
        std::cin >> book [0];
        std::cout << "success add book" << std::endl;
        count++;
    }else{
        std::cout << "this book will be adding after "<<count<<"'s book" <<std::endl;
        std::cout << "please enter title of the book" << std::endl;
        std::cin >> book [count];
        std::cout << "success add book" << std::endl;
        count++;
    }
}

void remove(){
    int pos;
    std::cout << "please enter the position of the book that you want to remove" << std::endl;
    std::cin>>pos;
    for (int i = (pos - 1); i < count; i++){
        book[i]=book[i+1];
    }

    std::cout << "success remove book" << std::endl;

    for (int i = 0; i < count; i++){
        std::cout << "current book at "<<i+1<<" :"<<book[i] << std::endl;
    }
}

void search(){
    string title;
    bool found = false;
    std::cout << "please enter name of the book" << std::endl;
    std::cin >>title;

    for (int i = 0; i < count; i++){
        if (book[i] == title)
        {
            std::cout << "book found at position "<< i+1 << std::endl;
            found =true;
        }
    }

    if(!found){
        std::cout << "the book didn't exist" << std::endl;
    }
}

void display(){
    for (int i = 0; i < count; i++){
        std::cout << "current book at "<<i+1<<" :"<<book[i] << std::endl;
    }

}

int main (){
    char op;
    bool choice = true;

    while (choice)
    {
        std::cout << "\033[31m libary management system" << "\n";     
        std::cout << "\033[33m 1. add book" << "\n";   
        std::cout << "\033[32m 2. remove book" << "\n";  
        std::cout << "\033[34m 3. search book" << "\n";  
        std::cout << "\033[35m 4. display book" << "\n";   // Indigo
        std::cout << "\033[31m 4.exit" << "\n";
        std::cout << "\033[0m please enter your choice :";

        std::cin>>op;

        switch (op){
            case '1':
            add();
            break;
            case '2':
            remove();
            break;
            case '3':
            search();
            break;
            case '4':
            display();
            break;   
            case '5':
            choice = false;
            std::cout << "thank for using" << std::endl;
            return 0;
            break;
            
            default:
            std::cerr<<"error";
            break;
        }
    
    }
    

    return 0;
}