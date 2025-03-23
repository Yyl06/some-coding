#include <iostream>
#include <fstream>
#include <string>
using std::string;

int main(){
    std::ofstream Info("info.txt", std::ios::app | std::ios::in);
    string name;
    int age;

    std::cout << "Enter Your Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Your Age: ";
    std::cin >> age;

    Info << name << " " << age;
    Info.close();


    std::ifstream Displayinfo("info.txt");
    string line;
    if(!Displayinfo){
        std::cerr << "Error Opening File." << "\n";
        return -1;
    }else{
        while(Displayinfo >> name >> age){
            std::cout << "Your Name: " << name << "\n";
            std::cout << "Your Age: " << age << "\n";
        }
    }


    std::ofstream File("info.txt", std::ios::app);
    string color;

    std::cout << "Enter Your Favorite Color: ";
    std::cin.ignore();
    std::getline(std::cin, color);

    File << " " << color;
    File.close();


    std::ifstream FileIn("numbers.bin", std::ios::binary | std::ios::in);
    std::ofstream FileOut("numbers.bin", std::ios::binary | std::ios::out);
    int x[1];

    std::cout << "Enter your lucky number: ";
    std::cin >> x[0];

    FileOut.write(reinterpret_cast<char*>(x), x[0]*sizeof(int));
    FileOut.close();
    std::cout << "Lucky Number Saved to Binary File! " << "\n\n\n";

    FileIn.read(reinterpret_cast<char*>(x), x[0]*sizeof(int));
    FileIn.close();
    
    std::cout << "Lucky Number read from Binary File: ";
    std::cout << x[0];
    std::cout << "\nBinary File Read Sucessfully!" << "\n";

    return 0;
}