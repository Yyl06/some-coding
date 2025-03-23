#include <iostream>
#include <string>

int main(){
   
    int x = 4;
    //Integer named x is set to 4
    int *px = &x;
    //Integer of pointer x is now set to the reference address(memory) of x
    //px will now extract the value memory of x that is stored and use it as an actual value
    int y = *px;
    //Integer named y is now set to the thing pointed to by px

    std::cout << "Value of x : " << x << "\n";
    std::cout << "Value of *px : " << *px << "\n";
    std::cout << "Value of &x : " << &x << "\n";
    std::cout << "Value of y : " << y << "\n";
// px = &x , x = *px
    
    
    
    //Dereferencing a pointer 
    int num = 10; 
    int *pnum = &num;

    //Referencing : The Output of the address
    std::cout << "Address Of The Pointer is : " << pnum << "\n";

    //Dereferencing : The Output of the value
    std::cout << "Dereferencing Value is : " << *pnum << "\n";



    //Changing a Value of a Pointer
    std::string Food = "Pizza";
    std::string *pFood = &Food;
   
    //Output The Memory Address of food
    //It Can be either pFood(This is for Pointers)/&Food(This is for References), they are the same memory address of it
    std::cout << "Memory of pFood : " << pFood << "\n";
    std::cout << "Memory of &Food : " << &Food << "\n";

    //Output the actual value of food
    std::cout << "Actual value of Food : " <<  *pFood << "\n";

    //Now, We can change(update) the value of the pointer by doing this :
    *pFood = "Hamburger";
    //Pointer of pfood has changed

    //Output the new memory address value of the pointer
    std::cout << "The Memory Address Of Updated pFood Value : " << pFood << "\n";

    //Output the new value of the pointer
    std::cout << "The New Value of Updated pFood Value : " << *pFood << "\n";

    return 0;

    //Pointers and References are just 2 things
    //Memory Values and Actual Values
}