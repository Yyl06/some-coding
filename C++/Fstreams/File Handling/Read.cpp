#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main(){
    std::ifstream File("students.txt");
    std::string Name, ID;
    double CGPA;
    if(!File){
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }else{
        while(File>> Name >> ID >> CGPA){
            std::cout << "Name: " << Name << "\n";
            std::cout << "ID: " << ID << "\n";
            std::cout << "CGPA: " << std::setprecision(2) << CGPA << "\n\n";
        }
    }

    File.close();
    return 0;
}