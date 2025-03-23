#include <iostream>
#include <memory>

int main(){
    int x = 10; // Initialize x with a value
    std::unique_ptr<int[]> numbers = std::make_unique<int[]>(x);

    for (int i = 0; i < x; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}