#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::fstream File("students.txt", std::ios::out | std::ios::in | std::ios::app);
    std::string Name, ID;
    double CGPA;
    int count = 0;

    if(!File){
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }else{
        while(File >> Name >> ID >> CGPA){
            count++;
        }
        std::cout << "Total Number of Students: " << count << "\n";
    }
    return 0;
}