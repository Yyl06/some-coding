#include <iostream>

void factorialLoop(int n) {
    int totalPermutations = 1;
    
    for (int i = 1; i <= n; i++) {
        totalPermutations *= i;  // Calculate n!
    }

    for (int i = 0; i < totalPermutations; i++) {  // O(n!)
        std::cout << "Iteration " << i << "\n";
    }
}

int main(){
    factorialLoop(50);
    return 0;
}
