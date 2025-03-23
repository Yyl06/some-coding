#include <iostream>
#include <string>

void Calc(double &x , double &y , char &op){
	std::cout << "Enter A Number! " << "\n";
	std::cin >> x;
	std::cout << "Enter Another Number! " << "\n";
	std::cin >> y;
	std::cout << "What Operations would you like to have? E.g. (+ - * /)" << "\n";
	std::cin >> op;
}

int main(){

	double x;
	double y;
    double result[1];
    char operations;
	std::string choice;

do{
	Calc(x , y , operations);
    
	switch (operations){
	case '+':{
	result[0] = x+y;
	std::cout << "Result : " << result[0] << "\n";
	break;
	}
	
	case '-':{
	result[0] = (x-y);
	std::cout << "Result : " << result[0] << "\n";
	break;
	}
	
	case '*':{
	result[0] = x*y;
	std::cout << "Result : " << result[0] << "\n";
	break;
	}
	
	case '/':{
		if (y == 0) {
		std::cerr << "Unable to calculate !";
		break;
		} else {
	    result[0] = x/y;
	    std::cout << "Result : " << result[0] << "\n";
	break;}
	}
	
	default:
	std::cout << "Unable to Calculate!" << "\n";
	break;
	}

	std::cout << "Do You wanna Calculate Again? (y/yes)(n/no)) : ";
	std::cin >> choice;
	}while (choice == "y" || choice == "Y" || choice == "Yes" || choice == "YES"); 
	
	return 0;
}
