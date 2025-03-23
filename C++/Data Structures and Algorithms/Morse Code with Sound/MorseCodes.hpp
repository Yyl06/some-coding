#ifndef MorseCodes_hpp
#define MorseCodes_hpp
#include <iostream>
#include "Data.hpp"
using std::string;

inline void Morse::BuildTree(){
    string morseCodes[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","/"};
    char letters[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
    for(int i = 0 ; i < 27 ; i++){
        Insert(letters[i], morseCodes[i]);
    }
}

#endif