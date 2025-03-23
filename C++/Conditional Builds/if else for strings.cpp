#include <iostream>
#include <string>

int main(){
	int Marks;
	std::string Grades;
	
	std::cout << "Your Marks:" << "\n";
	std::cin >> Marks;
	
	if(Marks>=60){
		std::cout << "You Passed! Congratulations!";
	}
	else if(Marks>=80){
		std::cout << "Excellent Work!";
	}
	else{
		std::cout << "Try Harder Next Time.";
	}
	return 0;
}
