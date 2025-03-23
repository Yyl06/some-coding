#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(0));
	
	int chamber = 6;
	int bulletposition = rand() % chamber;
	int PlayerPosition = 0;
	char Choice;
	
	std::cout << "Welcome to Russian Roulette : " << "\n";
    
	do{
    std::cout << "Play or Live?" << "(y/n)";
	std::cin >> Choice;
    
	if (Choice == 'n' || Choice == 'N') {
			std::cout << "You Chose to Live Another Day Huh" << "\n";
			exit(0);
	}

	PlayerPosition = rand() % chamber;
	std::cout << "Spinning the Chamber...." << "\n";
	if (PlayerPosition == bulletposition) {
		std::cout << "BANG! Whoops seems like you have died!" << "\n";
		break;
	} else{
		std::cout << "Clink! Heh, Lucky Devil." << "\n";
	}
	}while(Choice == 'y' || Choice == 'Y');

	std::cout << "Thanks For Playing Then" << "\n";
	return 0;
}