#include <iostream>

typedef struct Book{
    Book *Next;
    int data;

    Book(int data){
        this->data = data;
        this->Next = nullptr;
    }
}Books;

class Stack{
    int size;
    Book *Top;

    public:
    Stack(){
        this->size = 0;
        this->Top = nullptr;
    }

    bool Push(int data){
        Books *NewBook = new Book(data);
        NewBook->Next = Top;
        Top = NewBook;
        this->size++;
        return true;
    }

    bool Pop(){
        if(this->Top == nullptr){
            std::cerr << "Stack Underflow." << "\n";
            return false;
        }else{
            Books *temp = Top;
            Top = Top->Next;
            delete temp;
            this->size--;
            return false;
        }
        return false;
    }

    bool StackTop(){
        if(Top == nullptr){
            std::cerr << "Stack is Empty." << "\n";
            return false;
        }else{
            return Top->data;
        }
    }

    int GetSize(){
        return size;
    }

    bool isEmpty(){
        return Top == nullptr;
    }

    void Display(){
        Book *temp = Top;
        while(temp != nullptr){
            std::cout << temp->data;
            temp = temp->Next;
        }
        std::cout << "\n";
    }
};