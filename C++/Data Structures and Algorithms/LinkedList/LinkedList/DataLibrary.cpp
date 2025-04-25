#include <iostream>
#include "Data.hpp"

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