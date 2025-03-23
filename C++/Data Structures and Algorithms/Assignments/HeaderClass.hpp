/* ----------------- Lab Skill 2----------------------------
Section : 44
Name : YONG YUAN LIN
No Matric Card : A24DW0325
Topic : Stack
------------------------------------------------------------- */

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "HeaderDataType.hpp"
using std::string;

class LibraryList{
    Librarys *Head;
    int size;

    public:
        LibraryList(){
            this->Head = nullptr;
            this->size = 0;
        }

//Push, Push the element to the top of the stack
        void Push(string data){
            Librarys *NewStack = new Librarys(data);
            NewStack->Next = Head;
            Head = NewStack;
            size++;
        }

//Pop, Removes the top element of the stack
        void Pop(){
            if(this->Head == nullptr){
                std::cout << "Stack Underflow" << "\n";
                return;
            }else{
            Librarys *temp = Head;
            Head = Head->Next;
            delete temp;
            size--;
            }
        }

//Stack Top
//Uses string because string cant use return -1
        string Top(){
            if(Head == nullptr){
                std::cout << "Stack is Empty" << "\n";
                return "";
            }
            return Head->datas;
        }

//To get the size of the stack, since #include <stack> had these features
        int GetSize() {
            return size;
        }

//To check if the stack is empty, since #include <stack> had these features
        bool IsEmpty() {
            return Head == nullptr;
        }

//Traversal Stack(Reversed)
        void Print(){
            Librarys *temp = Head;
            while (temp != nullptr) {
                std::cout << temp->datas << " ";
                temp = temp->Next;
            }
            std::cout << "\n";
        }

//Clearance (For Freeing Up Memory)
        void Clear() {
            while (!IsEmpty()) {
                Pop();
            }
        }

//Conversion
        void Convert(string &data){
                std::cout << "Conversion Progress: " << "\n";
                //Conversion to char
                std::cout << "Char Conversion : ";
                for (char c : data) {
                    std::cout << c << " ";
                }
                std::cout << "\n";

                //Conversion to ASCII
                std::cout << "ASCII Conversion : ";
                for(char c : data){
                    std::cout << static_cast<int>(c) << " ";
                }
                std::cout << "\n";

                //Conversion to Binary
                std::cout << "Binary Conversion : ";
                for(char c : data){
                    int ASCII = static_cast<int>(c);
                    LibraryList Stack;
                    if(ASCII == 0){
                        Stack.Push("0");
                    }else{
                        while (ASCII > 0) {
                            Stack.Push(std::to_string(ASCII % 2));
                            ASCII /= 2;
                        }

                // Pop and print each binary digit from the stack
                while (!Stack.IsEmpty()) {
                    std::cout << Stack.Top();  // Print the top binary digit
                    Stack.Pop();               // Remove it from the stack
                }
            }
            //Adds a space between the binary representations of different characters.
            std::cout << " ";
        }
        std::cout << "\n";
            std::cout << "Done Conversion !" << "\n";
        }
};

#endif //STACK_H

