//template <typename T>
//return_type function_name(T parameter) {
  // code
//}

//Templates are useful in various situations
#include <iostream>

template<typename x>
x add(x a, x b){
    return a + b;
}

int main(){
    std::cout << add<int>(5, 3) << "\n";
    std::cout << add<double>(3.5, 4.3) << '\n';

    return 0;
}