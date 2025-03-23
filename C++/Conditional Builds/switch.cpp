#include <iostream>

int main(){
    int n = 3;

    switch(n){
        case 5:{
            std::cout << "Equal";
            break;
        }
        case 0 ... 4:{
            std::cout << "Less";
            break;
        }
        default:
        std::cout << "Greater";
    }

    return 0;
}