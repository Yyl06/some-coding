#include <iostream>
#include <string>

//void FuncName(Fake Parameters)
void SetName(std::string &Name){
    std::cout << "Enter Name : ";
    std::cin >> Name;
    
    int x = 0;
    while (x<5) {
    std::cout << "Your Name : " << Name << "\n";
    x++;
    }
}

int main(){
    std::string Names;
    
    //Mention FuncName(Real Parameters)
    SetName(Names);

    char choice;
    do{
        
        int x = 10;
        
        while(x<=10){
            std::cout << x << "\n";
            x++;
        }
        
        std::cout << "Do You Wanna Loop Again? (y/n)";
        std::cin >> choice;
    }while(choice == 'y' || choice == 'Y');
    

    return 0;
}