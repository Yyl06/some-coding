#include <iostream>

int main (){
	int number;
	
	std::cout << "Enter a Number:";
	std::cin >> number;
	
	if(number>0){
		std::cout << "The number is Positive.";
	}
	//Use else if for additional if statements.
	else if(number==0){
		std::cout << "The number is 0.";
		
	}
	//use else for other than your first statement only.
	else{
		std::cout << "The number is Negative.";
	}
return 0;
}
