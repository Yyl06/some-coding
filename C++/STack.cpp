#include <iostream>

typedef struct Stack{
    int data;
    Stack *Next;
    Stack(int data) : data(data), Next(nullptr){}
}Node;

class StackLL{
    Stack *Head;
    int size = 0;

    public:
    StackLL() : Head(nullptr), size(0) {}

    void Push(int data){
        Stack *NewNode = new Stack(data);
        NewNode->Next = Head;
        Head = NewNode;
        size++;
    }

    void Pop(){
        if(Head == nullptr){
            std::cerr << "Stack Underflow" << "\n";
            return;
        }else{
            Stack *temp = Head;
            Head = Head->Next;
            delete temp;
            size--;
        }
    }

    int StackTop(){
        if(Head == nullptr){
            std::cerr << "Stack is empty." << "\n";
            return -1;
        }else{
            return Head->data;
        }
    }

    bool isEmpty(){
        return Head == nullptr;
    }

    int getSize(){
        return size;
    }

    bool Search(int data){
        Stack *temp = Head;
        while(temp != nullptr){
            if(temp->data == data){
                return true;
            }else{
                temp = temp->Next;
            }
        }
        return false;
    }

    void Display(){
        Stack *temp = Head;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->Next;
        }
    }
};