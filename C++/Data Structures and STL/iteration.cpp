//Iteration also applies to list , deque , map and set
#include <string>
#include <vector>
#include <iostream>

int main(){
    //Creating a vector
    std::vector<std::string> Frame = {"Lotus" , "Dawn" , "Plume" , "Pyroath"};
    //Creating an iteration
    std::vector<std::string>::iterator Frames;
    //I've created an iterator named Frames
    //Looping through the vector with the iterator by using .begin()/.end()
    for(Frames = Frame.begin() ; Frames != Frame.end() ; ++Frames){
        std::cout << *Frames << "\n";
    }
    //.begin() = points to the 1st element of the structure
    //.end() = points to that one position after the last element

    //Getting the 2nd Element with .begin()
    Frames = Frame.begin()+1;
    //+1 means Element 0+1=1 , reading the 2nd element , will output "Dawn"
    Frames = Frame.begin()+3;
    //+3 , which is the 4th element , will output "Pyroath"

    //Getting the last element with .end()
    Frames = Frame.end()-1;
    //.end() points the element after the last one, we want to the the last one we would minus by 1

    //Modifying vectors through iteration
    Frames = Frame.begin();
    *Frames = "Crimson Abyss";
    //By using the asterisk (*) symbol we points the new value to the 1st element of the vector

    //using "auto" keyword by replacing iterator
    //We can change this std::vector<std::string>::iterator Frames;
    //to this : auto Frames = Frame.begin();
    //We can use auto keywords on for loops as well :
    for(auto Frames = Frame.begin() ; Frames != Frame.end() ; Frames++){
        std::cout << *Frames << "\n";
    }
    //Using the "auto" keyword is better and it makes your code more cleaner
    /*
    However , Comparing ForEach Loops with Iterators, they still have difference between them
    If you want to only display elements , you can use the ForEach loop rather than iterators because it looks much simpler and cleaner
    But when you want to modify, add, remove elements, it is better to use iterator because you can do it during iteration
    */

    //Iterate in reverse, introducing .rbegin()/.rend()
    for(auto Frames = Frame.rbegin() ; Frames != Frame.rend() ; Frames++){
        std::cout << *Frames << "\n";
    }
    //the "r" in the .rbegin() and .rend() means reverse, iterating in reverse orders
    return 0;
}