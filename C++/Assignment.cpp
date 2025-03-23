#include <iostream>
#include <string>
using std::string;
#include <cstring>

int main(){
    string str = "Hello World";
    char elements;
    char blank =' ';

    // Create a character array with sufficient size
    char charArray[100];

    // Copy string to character array
    strcpy_s(charArray, str.c_str());
    // Print the initial character array
    std::cout << "Character Array: " << charArray << std::endl;

    //adding more elements
    int pos;int size = str.length()+1;

    std::cout << "please enter the position that you want to add : ";
    std::cin >> pos;

    std::cout << "please enter what elements that you want to add : ";
    std::cin >> elements;

    for (int i = size; i >= pos-1; i--)
    {
        charArray[i+1]=charArray[i];
    }

    charArray[pos-1] = elements;

    for (int i = 0; i < size; i++)
    {
        std::cout << charArray[i];
    }
    std::cout << "  " << std::endl;

//remove
    std::cout << "please enter the position that you want to remove : ";
    std::cin >> pos;

    charArray[pos-1] = blank;

    for (int i = pos-1; i <= size; i++)
    {
        charArray[i]=charArray[i+1];
    }
    

//testing
    for (int i = 0; i < size; i++)
    {
        std::cout << charArray[i];
    }
    std::cout << "  " << std::endl;

//search
    std::cout << "please enter what elements that you want to search: ";
    std::cin >> elements;
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (elements == charArray[i]){
            std::cout << elements <<" is at the "<< i+1 <<" position" << std::endl;
            found = true;
            break;
        }
    }if (found == false){
    std::cout << "element not found" << std::endl;
}
    
//print out(traversal)
    for (int i = 0; i < size; i++){
        std::cout << charArray[i] << std::endl;
    }
    return 0;
}