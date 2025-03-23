#include <iostream>

int main(){
	std::string result;
	int num1;
	
	std::cout << "Insert a Number:";
	std::cin >> num1;
	result = (num1 % 2 == 0)? "Even" : "Odd";
	
	std::cout << "The Number Is:" << result << "\n";
	return 0;
}
