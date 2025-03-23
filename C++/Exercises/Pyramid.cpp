#include <iostream>
#include "Pyramid.hpp"

int main(){
    double l , w , h;
    int choice;
    int base;
    Pyramid Pyramix(l ,h ,w);
    std::cout << "Enter the length of the pyramid: ";
    std::cin >> l;
    std::cout <<"\n";
    std::cout << "Enter the width of the pyramid: ";
    std::cin >> w;
    std::cout <<"\n";
    std::cout << "Enter the height of the pyramid: ";
    std::cin >> h;
    std::cout << std::endl;

    std::cout << "Enter Parameter to Calculate (1-Area / 2-Volume): ";
    std::cin >> choice;
    std::cout << std::endl;
    switch(choice){
        case 1 :
        std::cout << "Enter the Base Shape of the Pyramid (1-Square / 2-Rectangle)): ";
        std::cin >> base;
        std::cout << std::endl;
        
        switch (base){
            case 1 :
            std::cout << "Area of the Pyramid: " << Pyramix.GetArea(l , h) << std::endl;
            break;

            case 2 :
            std::cout << "Volume of the Pyramid: " << Pyramix.GetArea(l , w, h) << std::endl;
            break;

            default :
            std::cerr << "Invalid Input" << std::endl;
            break;
        }break;

        case 2 :
        std::cout << "Enter the Base Shape of the Pyramid (1-Square / 2-Rectangle)): ";
        std::cin >> base;
        std::cout << std::endl;

            switch (base){
            case 1 :
            std::cout << "Area of the Pyramid: " << Pyramix.GetVolume(l , h) << std::endl;
            break;

            case 2 :
            std::cout << "Volume of the Pyramid: " << Pyramix.GetVolume(l , w, h) << std::endl;
            break;

            default :
            std::cerr << "Invalid Input" << std::endl;
        }
        break;

        default :
        std::cerr << "Invalid Input" << std::endl;
        break;
    }
}