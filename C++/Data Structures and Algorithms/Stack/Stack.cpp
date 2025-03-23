#include <iostream>
#include <string>
using std::string;

//Data type of the linked list of Stack
#ifndef DATA_H
#define DATA_H

typedef struct Library{
    string datas;
    Library * Next;

    Library(string data){
        this->datas = data;
        this->Next = nullptr;
    }
}Librarys;

#endif // DATA_H

//Linked list class of Stack
#ifndef STACK_H
#define STACK_H

class LibraryList{
    private:
        Librarys * Head;
        int Size;

    public:
        LibraryList(){
            this->Head = nullptr;
            this->Size = 0;
        }


//Push, adds a new element to the stack(Newer elements always at the top Since LIFO, Last In First Out)
        void Push(string data){
            Librarys * NewLibrary = new Librarys(data);
            NewLibrary->Next = Head;
            Head = NewLibrary;
            Size++;
        }

//Pop, removes the top element of the stack(Always from the top Since LIFO, Last In First Out)
        void Pop(){
            if (this->Head == nullptr) {
                std::cout << "Stack Underflow" << "\n"; // List is empty
                return;
            }
            Librarys * temp = Head;
            Head = Head->Next;
            delete temp;
            Size--;
        }

//Stack Top, copies the top element of the stack, if there is no element in the stack, it will return -1
        string Top() {
            if (Head == nullptr) {
                std::cout << "Stack is empty" << std::endl;
                return "";
            }
            return Head->datas;
        }

//To get the size of the stack, since #include <stack> had these features
        int GetSize() {
            return Size;
        }

//To check if the stack is empty, since #include <stack> had these features
        bool IsEmpty() {
            return Head == nullptr;
        }

//Search
        bool Search(string data) {
            Librarys * temp = Head;
            while (temp != nullptr) {
                if (temp->datas == data) {
                    return true;
                }
                temp = temp->Next;
            }
            return false;
        }

//Traversal
        void Print() {
            Librarys * temp = Head;
            while (temp != nullptr) {
                std::cout << temp->datas << " ";
                temp = temp->Next;
            }
            std::cout << std::endl;
        }

};

#endif // STACK_H

int main(){
    LibraryList s;

    string number;
    int choice;
    std::string exit;
    std::cout << "1. Add Data" << std::endl;
    std::cout << "2. Remove Data" << std::endl;
    std::cout << "3. Search Data" << std::endl;
    std::cout << "4. Display Data" << std::endl;
    std::cout << "5. Check The Size of Stack" << std::endl;
    std::cout << "6. Check whether is The Stack is Empty" << std::endl;
    do{
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the number you want to add: ";
                std::cin >> number;
                s.Push(number);
                std::cout << "Data Added Successfully" << std::endl;
                break;

            case 2:
                s.Pop();
                std::cout << "Data Removed Successfully" << std::endl;
                break;

            case 3:
                std::cout << "Enter the number you want to search: ";
                std::cin >> number;
                if (s.Search(number)){
                    std::cout << "Data Found" << std::endl;
                    break;
                }else{
                    std::cout << "Data Not Found" << std::endl;
                    break;
                }
                break;
            case 4:
                s.Print();
                break;

            case 5:
                s.GetSize();
                break;

            case 6:
                s.IsEmpty();
                break;

            default:
                std::cout << "Invalid Choice" << std::endl;
                break;
    }
    }while(exit != "exit");
    return 0;
}