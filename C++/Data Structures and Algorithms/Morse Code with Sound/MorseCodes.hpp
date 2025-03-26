#ifndef MorseCodes_hpp
#define MorseCodes_hpp
#include "Data.hpp"
using std::string;

//Syahmi Part
//inline = Allows a single function definition that uses through files instead of copying everytime when the program compiles
inline void Morse::BuildTree(){
    //Morse codes
    string morseCodes[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","/"};
    //Corresponding Morse Code chars
    char letters[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
    //Insertion for Each character
    for(int i = 0 ; i < 27 ; i++){
        Insert(letters[i], morseCodes[i]);
    }
}

#endif