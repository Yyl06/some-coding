#include <iostream>

void Factorial(int n, int &result){
    if(n == 0){
        result = 1;
    }else{
        Factorial(n - 1, result);
        result *= n;
    }
}

int main(){
    int n = 5;
    int result = 1;
    Factorial(n, result);
    std::cout << "Factorial of " << n << " is " << result << "\n";
    return 0;
}