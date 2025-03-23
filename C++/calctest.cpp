#include <iostream>

void Addition(double &x, double &y, double &result){
    result = x + y;
}

void Subtraction(double &x, double &y, double &result){
    result = x - y;
}

void Multiplication(double &x, double &y, double &result){
    result = x * y;
}

void Division(double &x, double &y, double &result){
    if(x == 0 || y == 0){
        std::cout << "Cannot divide by zero" << std::endl;
    }else{
        result = x / y;
    }
}


int main(){
    double x, y, result;
    char op;
    std::cout << "Enter the first number : ";
    std::cin >> x;
    std::cout << "Enter the second number : ";
    std::cin >> y;
    std::cout << "Enter the operator : ";
    std::cin >> op;
    switch(op){
        case '+':
            Addition(x, y, result);
            std::cout << "The sum of the numbers is : " << result << std::endl;
            break;
        case '-':
            Subtraction(x, y, result);
            std::cout << "The difference of the numbers is : " << result << std::endl;
            break;
        case '*':
            Multiplication(x, y, result);
            std::cout << "The product of the numbers is : " << result << std::endl;
            break;
        case '/':
            Division(x, y, result);
            std::cout << "The division of the numbers is : " << result << std::endl;
            break;
        default:
            std::cout << "Invalid operator" << std::endl;
            break;
    }
    return 0;
}