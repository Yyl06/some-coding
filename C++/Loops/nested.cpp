#include <iostream>

int main(){
    for (int i = 1 ; i <= 10; i++) {
        //For Columns
        for (int j = 1 ; j <= i; j++) {
            //For Rows
        std::cout << "*";
        }   
    std::cout << "\n";
    }
    return 0;
}