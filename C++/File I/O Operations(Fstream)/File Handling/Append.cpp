#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main(){
    std::fstream File("students.txt", std::ios::out | std::ios::in | std::ios::app);
    std::string Name, ID;
    double CGPA;
    if(!File){
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }else{
        std::cout << "Enter Student Name: ";
        std::getline(std::cin, Name);
        std::cout << "\nEnter Student ID: ";
        std::cin >> ID;
        std::cin.ignore();
        std::cout << "\nEnter Student CGPA: ";
        std::cin >> CGPA;
        std::cout << "\n";
        std::cout << "Student Record Saved Successfully!\n";
        File << Name << " " << ID << " " << CGPA << std::setprecision(2) << "\n";
        File.close();
    }

    return 0;
}