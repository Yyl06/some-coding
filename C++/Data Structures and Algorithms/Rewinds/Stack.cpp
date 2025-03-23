#include <iostream>

typedef struct Link{
    int data;
    Link *Next;

    Link(int data){
        this->data = data;
        this->Next = nullptr;
    }
}Linked;

class List{
    private:
        int size;
        Link *Head;

    public:
        bool Push(int data){
            Link *NewLink = new Link(data);
            NewLink->Next = Head;
            Head = Head->Next;
            size++;
            return true;
        }

        bool Pop(){
            if(this->Head == nullptr){
                std::cout << "Stack Underflow." << "\n";
                return false;
            }else{
            Link *temp = Head;
            Head = Head->Next;
            delete temp;
            size--;
            return true;
            }
        }

        //Alternative way with parameters of pop
        bool Pop(int &data){
            if(this->Head == nullptr){
                std::cout << "Stack Underflow." << "\n";
                return false;
            }else{
            Link *temp = Head;
            data = temp->data;
            Head = Head->Next;
            delete temp;
            size--;
            return true;
            }
        }
        

        int StackTop(){
            if(this->Head == nullptr){
                std::cout << "Stack is Empty." << "\n";
                return -1;
            }else{
                return Head->data;
            }
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return Head == nullptr;
        }

        void Display(){
            Link *temp = Head;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->Next;
            }
            std::cout << "\n";
        }
};