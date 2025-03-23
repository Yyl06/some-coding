//Vectors
#include <vector>
#include <iostream>
#include <string>
#define Out std::cout <<
using std::string;

int main(){
    //Creating a vector by using vector<DataType> Name Syntax
    std::vector<std::string> NameList;

    //Vectors = Arrays , Use {} for specifying elements
    //Vectors dont have fixed sizes , which means you can add elements as you desire
    NameList = {"Yong" , "Lee"};

    //By Using a ForEach Loop to print all elements in the vector
    for (std::string Name : NameList) {
        Out "Names List : " << "\n";
        Out Name << "\n";
    }

    // **<DataType> Can't be changed after declaration on the vector**

    //Accessing a Vector by using [](The array bracket)
    std::vector<std::string> choices = {"Yes" , "No"};
    //Output the 1st element
    Out choices[0] << "\n";
    //Output the 2nd element
    Out choices[1] << "\n";
    
    //Advantages of using vector (Introducing .front() and .back() from the vector library)
    std::vector<string> Frame = {"Lotus" , "Dawn" , "Plume" , "Pyroath"};
    //First Element ( .front() )
    Out Frame.front();
    //Last Element ( .back() )
    Out Frame.back();
    //Accessing an element with an specified index with .at()
    //Accessing 2nd element (arrays start with sequence 0)
    Out Frame.at(1);
    //Accessing 3rd element
    Out Frame.at(2);
    //By Using .at() rather than the arr bracket[] is that if the element doesn't exists, it will throws an error message
    //Example :
    Out Frame.at(5);

    //Changing an vector element , modifying the vector i mentioned before
    //Changing the first element
    Frame[0] = "Crimson Abyss";
    //Now Frame no.0's element is named Crimson Abyss instead of Lotus
    Out Frame[0];
    //Expected , will output Crimson Abyss instead of Lotus
    //However if we use .at() , it would be much safer for the code to run afterwards
    //Example :
    Frame.at(0) = "Crimson Weave";
    //Adding Vector Elements by introducing .push_back()
    //We'll be using the Frame vector mentioned before
    Frame.push_back("Lotus");
    //New Frame named Lotus is added to the end of the vector , sequencing at the last element
    //You can add as many elements as u want (eg. 10 vector elements at once)
    Frame.push_back("Crimson Abyss");

    //Removing Elements from a vector , introducing .pop_back()
    Frame.pop_back();
    //"Crimson Abyss" is removed from the vector elements
    //The Brackets are empty because adding and removing vectors are from the last element
    //Example , I Added Crimson Abyss as the last element of the Frame , now .pop_back will remove "Crimson Abyss" from the Frame vector

    //Checking a size of vector , introducing .size()
    //Ofc , using cout
    Out Frame.size();
    //Outputs the number of elements included in the vector
    
    //Checking an empty vector , introducing .empty()
    //If the vector is empty , it will outputs 1 and vice versa
    std::vector<int> Numbers; //An empty vector
    
    Out Numbers.empty(); //Outputs 1 , an empty vector
    Out Frame.empty(); //Outputs 0 , a non-empty vector

    //Looping Through a vector
    //By using for loop/ForEach loop , we can loop through a vector
    //For Loop , by using .size()
    for(int i = 0 ; i < Frame.size() ; i++){
        Out Frame.at(i) << "\n";
    }

    //The ForEach Loop , more cleaner "for loop"
    for(std::string Frames : Frame){
        Out Frames << "\n";
    }

    Frame.erase(Frame.begin()+1);
    return 0;
}