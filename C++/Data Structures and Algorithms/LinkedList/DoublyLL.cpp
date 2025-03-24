#include <iostream>
#include <string>
using std::string;

struct Node{
    string data;
    Node *Previous ,*Next;

    Node(string d) : data(d),Previous(nullptr), Next(nullptr) {};
};

class DoublyLL{
    Node *Head;
    int count;

    public:
        DoublyLL() : Head(nullptr), count(0) {};

    void Insert(string data){
        Node *newNode = new Node(data);
        try{
            if(this->Head != nullptr){
                Head->Previous = newNode;
                newNode->Next = Head;
            }else{
                Head = newNode;
            }
        }catch(std::bad_alloc &){
            std::cerr << "Segfault ☠️" << "\n";
            return;
        }
    }

    void InsertatTail(string data){
        Node *newNode = new Node(data);
        try{
            if(this->Head == nullptr){
                Head = newNode;
                return;
            }else{
                Node *temp = Head;
                while(temp->Next){ temp = temp->Next; }
                temp->Next = newNode;
                newNode->Previous = temp;
            }
        }catch(std::bad_alloc &){
            std::cerr << "Segfault ☠️" << "\n";
            return;
        }
    }

    void Deletion(string data){
        Node *temp = Head;
        while(temp != nullptr && temp->data != data){ temp = temp->Next; }//temp is not empty and temp does not equal to data input will continue until unfufiled
        if(temp == nullptr){ return; } //Node not found

        if(temp->Previous != nullptr){
            temp->Previous->Next = temp->Next;
        }else{
            Head = temp->Next;
        }

        if(temp->Next != nullptr){
            temp->Next->Previous = temp->Previous;
        }
        delete temp;
    }

    void AscendingPrint(){
        Node *temp = Head;
        while(temp){
            std::cout << temp->data << " ";
            temp = temp->Next;
        }
        std::cout << "\n";
    }

    void DecendingPrint(){
        if(Head == nullptr){ return; }

        Node *temp = Head;
        while(temp->Next){
            temp = temp->Next;
        }
        
        while(temp){
            std::cout << temp->data << " ";
            temp = temp->Previous;
        }
        std::cout << "\n";
    }

    ~DoublyLL(){
        Node *temp;
        while(Head){
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
    }
};

int main(){
    DoublyLL DLL;
    DLL.Insert("10");
    DLL.Insert("20");
    DLL.InsertatTail("30");
    DLL.InsertatTail("40");

    std::cout << "Forward: ";
    DLL.AscendingPrint();

    std::cout << "Backward: ";
    DLL.DecendingPrint();

    DLL.Deletion("20");
    std::cout << "After deleting 20: ";
    DLL.AscendingPrint();

    return 0;
}