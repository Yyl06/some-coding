#include <iostream>
#include "Data.hpp"
using std::string;

//Jun Yu
int main(){
    Morse MorseCode;// Class Object
    MorseCode.BuildTree(); // Call the function to save the database Morse to the Tree
    string text;

    std::cout << "Enter Text Convert to Morse: ";
    std::getline(std::cin , text);

    string Morse = MorseCode.textToMorse(text);
    std::cout << "Morse Code: " << Morse << std::endl;

    std::cout << "Playing Morse Code...." << std::endl;
    MorseCode.playMorseSound(Morse);

    return 0;
}
