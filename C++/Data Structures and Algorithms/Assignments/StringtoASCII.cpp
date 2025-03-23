/* ----------------- Lab Skill 2 ----------------------------
Section : 44
Name : YONG YUAN LIN
No Matric Card : A24DW0325
Topic : Stack
------------------------------------------------------------- */

#include <iostream>
#include <string>
using std::string;
#include "HeaderDataType.hpp"
#include "HeaderClass.hpp"

        /*Alternative Methods for ASCII to Binary Conversion
        #include <bitset>
        std::cout << "Binary Conversion: ";
        for (char c : data) {
        //Bits are set to 8 since ASCII Characters are Based on 8 bit Binary Representation
        std::cout << std::bitset<8>(c) << " ";
    }
    std::cout << "\n";
        
            //A loop that iterates from 7 to 0,
            //Which corresponds to the 8 bits in a byte (since ASCII characters are represented in 8-bit binary).
            for(int i = 7 ; i >= 0 ; i--){
                //The right shift operator (>>) moves bits to the right by a specified data of positions.
                //Each shift divides the data by 2 (integer division), discarding the rightmost bit.
                //Right shifts ASCII by i bits:
                //Example: If ASCII = 65 (which is 'A'), its binary is 01000001.
                //When i = 7: (65 >> 7) = 0, so 0 & 1 = 0)(LSB)
                //This extracts each bit from left to right.
                //& here is the AND Logic Operator, if ASCII >> i is same as 1, then LSB will be 1.
                std::cout << ((ASCII >> i) & 1);
                //ASCII/(int i x 2) to get Binary Representations
                //Right shifts only work for powers of 2.
            }
        */


int main(){
    string data;
    LibraryList String;
    int choice;
    string exit;

    std::cout << "String To ASCII Conversion: " << "\n";
    std::cout << "1. Add Data" << std::endl;
    std::cout << "2. Remove Data" << std::endl;
    std::cout << "3. Display Data" << std::endl;
    std::cout << "4. Check The Size of Stack" << std::endl;
    std::cout << "5. Check whether is The Stack is Empty" << std::endl;
    do{
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                std::cout << "Enter the data you want to add: ";
                std::getline(std::cin,data);
                std::cout << "Data Added Successfully" << "\n";
                String.Push(data);
                break;

            case 2:
                String.Pop();
                std::cout << "Data Removed Successfully" << "\n";
                break;

            case 3:
            String.Clear();

            for(char c : data){
                //Push everything as char from the string given
                //A simple trick to wrap a char into a std::string instantly.
                String.Push(string(1,c));
                }
                String.Print();
                String.Convert(data);
                break;

            case 4:
                String.GetSize();
                break;

            case 5:
                String.IsEmpty();
                break;

            default:
                std::cout << "Invalid Choice" << std::endl;
                break;
        }

        std::cout << "Exit or Continue(y/n): ";
        std::getline(std::cin , exit);
    }while(exit == "No" || exit == "no" || exit == "n");
    return 0;
}