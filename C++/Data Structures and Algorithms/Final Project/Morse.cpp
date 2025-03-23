#include <iostream>
#include "Node.hpp"
#include "MorseCodes.hpp"
using std::string;

int main(){
    Morse MorseCode;
    MorseCode.BuildTree();
    string text;

    std::cout << "Enter Text Convert to Morse: ";
    std::getline(std::cin , text);

    string Morse = MorseCode.textToMorse(text);
    std::cout << "Morse Code: " << Morse << std::endl;

    std::cout << "Playing Morse Code...." << std::endl;
    MorseCode.playMorseSound(Morse);

    return 0;
}