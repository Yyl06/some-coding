#include "Ari.hpp"
#include "Logarithms.hpp"
#include "Power.hpp"
#include "Trigo.hpp"
#include <string>
#include <iostream>

#define Out std::cout <<
#define In std::cin >>
#define End "\n";

void Display(){
    Out "Choose Your Functions : " << End
    Out "1 - Basic Arimethic Operations" << End
    Out "2 - Power Calculations" << End
    Out "3 - Logarithm Calculations" << End
    Out "4 - Trigonometry Calculations" << End
}

int main(){
    double x , y;
    int ops , choices;
    std::string choice;

    do{
        Display();
        std::cin >> choices;

        switch (choices) {
            case 1 : {
                Arimethic(x,  y, ops);
                break;
            }
            case 2 : {
                pow_sqrt(x, y, ops);
                break;
            }
            case 3 : {
                Logarithms(x, y, ops);
                break;
            }
            case 4 : {
                Trigonometric(x, y, ops);
                break;
            }
        }
        Out "Do You Wanna Calculate Again? (Yes/No)" << End
        In choice;
    }while(choice == "Yes" || choice == "yes" || choice == "YES" || choice == "Y" || choice == "y" || choice == "YEs" || choice == "YeS" || choice == "yEs" || choice == "yeS" || choice == "yES");
    Out "Thanks For Using !" << End

}