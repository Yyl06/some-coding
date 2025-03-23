#ifndef DATA_H
#define DATA_H
#include <iostream>

typedef struct DataLibrarys{
    int number;
    DataLibrarys *next;

    DataLibrarys(int number){
        this->number = number;
        this->next = nullptr;
    }
}DataLibrary;

#endif

#ifndef STACK_H
#define STACK_H

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

#endif // STACK_H

int main(){
    DataLibraryList *Stack = new DataLibraryList();
    int number;
    int choice;
    std::string exit;
    std::cout << "1. Add Data" << std::endl;
    std::cout << "2. Remove Data" << std::endl;
    std::cout << "3. Search Data" << std::endl;
    std::cout << "4. Display Data" << std::endl;
    do{
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the number you want to add: ";
                std::cin >> number;
                if (Stack->add(number)){
                    std::cout << "Data Added Successfully" << std::endl;
                }else{
                    std::cout << "Failed to add data" << std::endl;
                }
                break;

            case 2:
                if (Stack->remove()){
                    std::cout << "Data Removed Successfully" << std::endl;
                }else{
                    std::cout << "Failed to remove data" << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter the number you want to search: ";
                std::cin >> number;
                if (Stack->Search(number)){
                    std::cout << "Data Found" << std::endl;
                }else{
                    std::cout << "Data Not Found" << std::endl;
                }
                break;

            case 4:
                Stack->Display();
                break;

            default:
                std::cout << "Invalid Choice" << std::endl;
                break;
        }
    }while(exit != "exit");
    return 0;
}