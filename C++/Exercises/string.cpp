#include <cctype>
#include <iostream>
#include <cstring>

int main(){
    char course[10];
    char Matric[20];
    int Lengthcourse, LengthMatric;
    const std::string ListCourse[] = {"DDWA", "DDWC", "DDWE"};

    std::cout << "Enter your Course Code(DDWA): ";
    std::cin >> course;

    std::cout << "Enter your Matric Number(A123): ";
    std::cin >> Matric;

    LengthMatric = strlen(Matric);
    Lengthcourse = strlen(course);
    if(std::isalpha(course[0]) && std::isalpha(Matric[0]) && (LengthMatric == 4) && (Lengthcourse == 4)){
        bool validCourse = false;
        std::string program = "OTHER COURSE";
        for(int i = 0; i < 3; i++){
            //strcmp() performs a character-by-character comparison:
            //It checks ASCII values (e.g., 'a' (97) is smaller than 'b' (98)).
            //It stops when characters differ or reaches '\0'.
            if(strcmp(course, ListCourse[i].c_str()) == 0){
                validCourse = true;
                if(i == 0) program = "DIPLOMA IN CIVIL ENGINEERING";
                else if (i == 1) program = "DIPLOMA IN COMPUTER SCIENCE";
                else if (i == 2) program = "DIPLOMA IN ELECTRICAL ENGINEERING";
                break;
            }else{
                std::cout << "Invalid Course: Course Code must be DDWC, DDWE or D" << "\n";
                std::cout << "The Course You Entered is: " << course << "\n";
                break;
            }
        }
        if (validCourse) {
            std::cout << "The Course You Entered (" << course << ") is Valid\n";
            std::cout << "Your Program is: " << program << "\n";
        } else {
            std::cout << "Invalid Course: Course Code must be DDWA, DDWC, or DDWE\n";
        }
        std::cout << "The Matric You Entered is: " << Matric << " is Valid" << "\n";
    }else{
        std::cout << "First Char: " << Matric[0] << "\n";
        if(!std::isalpha(course[0])) std::cout << "Invalid Course: First number must be alphabet" << "\n";
        if(!std::isalpha(Matric[0])) std::cout << "Invalid Matric: Length must be 4" << "\n";
        std::cout << "The Matric You Entered is: " << Matric << "\n";
    }
    return 0;
}