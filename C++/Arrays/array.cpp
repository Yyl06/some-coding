#include <iostream>
#include <array>

int main(){
    std::array<int, 10> data = {1,2,3,4,5,6,7,8,9,10};

    for(unsigned int i = 0 ; i < data.size() ; i++){
        std::cout << data[i] << "\n";
    }
}