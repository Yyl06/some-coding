#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ofstream OutputFile;
    std::ifstream InputFile;
    std::string input1 , input2;
    
    OutputFile.open("ReadMenu.txt", std::ios::out);
    InputFile.open("Menu.txt" , std::ios::in);
    if(!InputFile)
	{
	std::cout << "Error Occured Opening your File. \n";
	}
    
    std::cout <<"File Open Sucessfully. \n";
    std::cout << "Now Reading Information. \n";
    
    InputFile >> input1 >> input2 ;
    OutputFile << input1 << input2 << "\n";
    
    getline(InputFile , input1);
    OutputFile << input1 << "\n";
    
    InputFile.close();
    OutputFile.close();
    std::cout << "Done. ";

    return 0;
}

