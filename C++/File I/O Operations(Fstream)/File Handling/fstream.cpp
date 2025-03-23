#include <fstream>
#include <iostream>

int main(void){
    /* Declare file stream variables such as the following  */
    std::ifstream fsIn;
    std::ofstream fsOut;
    std::fstream both;

    fsIn.open("prog1.txt");
    if(!fsIn.is_open()){
        std::cout << "Error opening file" << std::endl;
        return -1;
    }
    fsOut.open("prog2.txt");
    if(!fsOut){
        std::cout << "Error opening file" << std::endl;
        return -1;
    }

    fsOut << "Hello World!";

    fsIn.close();
    fsOut.close();
    

    return 0;
}