#include <iostream>

class Fibonacci{
    private:
    int n;
    int sequence[20];

    public:
        Fibonacci(int n) : n(n) {}

        void generate(int sequence[]){
            sequence[0] = 0;
            sequence[1] = 1;
            for(int i = 2 ; i < n ; i++){
                sequence[i] = sequence[i-1] + sequence[i-2];
            }
        }

        void print(){
            for(int i : sequence){
                std::cout << "Numbers of Sequence: " << i;
            }
            std::cout << "\n";
        }
};

int main(){
    int n;
    int sequence[n];
    Fibonacci numbers(n);
    std::cout << "Enter Terms to Print Fibonacci Numbers: ";
    std::cin >> n;
    if(n > 20){
        std::cerr << "Invalid input!";
    }
    numbers.generate(sequence);
    numbers.print();
    return 0;
}