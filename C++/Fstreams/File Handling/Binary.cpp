#include <iostream>
#include <fstream>

int main(){
    std::fstream file("Binary.bin", std::ios::binary | std::ios::out | std::ios::in);
    int x = 10;
    
    file.write(reinterpret_cast<char*>(x), sizeof(int));
    file.close();

    file.read(reinterpret_cast<char*>(x), sizeof(int));
    file.close();

    return 0;
}