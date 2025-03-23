#include <iostream>

int main() {
#ifdef __clang__
    std::cout << "Compiled with Clang!\n";
#elif defined(__GNUC__)
    std::cout << "Compiled with GCC!\n";
#else
    std::cout << "Unknown Compiler!\n";
#endif
    return 0;
}
