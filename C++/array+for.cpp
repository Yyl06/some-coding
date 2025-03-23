#include <iostream>

//Allowing user to input two numbers, using a for loop to output the value of the highest number and lowest number

int main(){
    int numbers[2];

    std::cout << "Enter A Number : ";
    std::cin >> numbers[0];
    std::cout << "\n";
    std::cout << "Enter Another Number : ";
    std::cin >> numbers[1];
    std::cout << "\n";

    int highestnum = numbers[0];
    int lowestnum = numbers[0];
    
    for(int i = 0 ; i < 2 ; i++){
        if(numbers[i] > highestnum){
            highestnum = numbers[i];
        }if(numbers[i] < lowestnum) {
            lowestnum = numbers[i];
        }
    }
    
    std::cout << "The Highest Number is : " << highestnum << "\n";
    std::cout << "The Lowest Number is : " << lowestnum << "\n";
    return 0;
}