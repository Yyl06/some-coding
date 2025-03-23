#include <iostream>

void Fibonacci(int n, int &result){
    if(n == 0){
        result = 0;
    }else if(n == 1){
        result = 1;
    }else{
        int a = 0;
        int b = 1;
        for(int i = 2; i <= n; i++){
            result = a + b;
            a = b;
            b = result;
        }
    }
}

int main(){
    int n = 5;
    int result = 0;
    Fibonacci(n, result);
    std::cout << "Fibonacci of " << n << " is " << result << "\n";
    return 0;
}