#include <fstream>
#include <iostream>

int main(){
    std::fstream IntroFile("text.txt", std::ios::out | std::ios::app);
    IntroFile << "Welcome Here";
    IntroFile.close();
    return 0;
}