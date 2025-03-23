#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(0));
    
    std::string handsign[3] ={"Rock","Scissors", "Paper"};
    char choices;

   do{
    int Choice;
    std::cout << "Choose Either Rock(0), Scissors(1) or Paper(2) : ";
    std::cin >> Choice;

    if(Choice < 0 || Choice > 2){
        std::cout << "Invalid Handsign! Try Again" << "\n";
        return 1;
    }

    int AIChoice = rand() % 3;
    std::cout << "Your Choice : " << handsign[Choice] << "\n";
    std::cout << "Computer's Choice : " << handsign[AIChoice] << "\n";

    if(Choice == AIChoice){
        std::cout << "It's a Tie! " << "\n";
    } else if ((Choice == 0 && AIChoice == 1) || (Choice == 1 && AIChoice == 2) || (Choice == 2 && AIChoice == 0) ) {
        std::cout << " You Win! Congratulations! " << "\n";
    }else{
        std::cout << "You Lose! " << "\n";
    }
    
    std::cout << "Do You Wanna Play Again? (Y/N) " << "\n";
    std::cin >> choices;
    
    if(choices == 'N' || choices == 'n'){
        break;
    }
   }while(choices == 'Y' || choices == 'y');

    return 0;
}