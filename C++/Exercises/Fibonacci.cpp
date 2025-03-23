#include <iostream>
class Fibonacci {
    private:
        const static int n = 20;
        int sequence[n];

    public:
        Fibonacci(int n) {
            std::cout << "Enter Terms to Generate Fibonacci Sequence: ";
            std::cin >> n;
        }
};