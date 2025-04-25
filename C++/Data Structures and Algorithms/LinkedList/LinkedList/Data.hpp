#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.hpp"

class DataLibraryList{
    private:
        DataLibrary *Top;
        int Size;

    public:
        DataLibraryList(){
            this->Top=nullptr;
            this->Size=0;
        }

        bool add(int number){
            DataLibrary *NewData = new DataLibrary(number);
            try{
                if (this->Top == nullptr){
                    this->Top = NewData;
                
                }else{
                    NewData->next = this->Top;
                    this->Top = NewData;
                }this->Size++;
                return true;
            }catch(std::bad_alloc &){
                return false;
        }
        return false;
        }

        bool remove(){
            if (this->Top == nullptr){
                return false;
            }
            DataLibrary *Current = this->Top;
            this->Top = this->Top->next;

            delete Current;
            this->Size--;

            return true;
        }

        bool Search(int number){
            DataLibrary *Current = this->Top;
            while(Current != nullptr && Current->number != number){
                Current = Current->next;
            }
            return Current != nullptr;
        }

        void ReverseDisplay(){
            DataLibrary *Previous = nullptr;
            DataLibrary *Current = this->Top;
            DataLibrary *Next = nullptr;

            while(Current != nullptr){
                Next = Current->next;
                Current->next = Previous;
                Previous = Current;
                Current = Next;
            }
            Top = Previous;

            while (Current != nullptr){
                std::cout << Current->number << " ";
                Current = Current->next;
            }
            std::cout << std::endl;
        }

        void Display(){
            DataLibrary *Current = this->Top;
            while (Current != nullptr){
                std::cout << Current->number << " ";
                Current = Current->next;
            }
            std::cout << std::endl;

            std::cout << "Reversed Display: ";
            ReverseDisplay();
        }
};

#endif 