#include <iostream>
#include <cstring>
#include <cctype>

int main(){
    char matric[20];
    int len;
    
    std::cout << "Enter your matric number in this format(A123): ";
    std::cin >> matric;

    len = strlen(matric);
    //isalpha() is a function in the <cctype> header that checks if a given character is an alphabetic letter (either uppercase or lowercase).
    if(std::isalpha(matric[0]) == true && (len == 4)){
        std::cout << "The Matric You Entered is: " << matric << "is Valid" << "\n";
    }else{
        std::cout << "First Char: " << matric[0] << "\n";
        std::cout << "Invalid Matric: First number must be alpabet" << "\n";
        std::cout << "Invalid Matric: Length must be 4" << "\n";
        std::cout << "The Matric You Entered is: " << matric << "\n";
    }

    return 0;
}