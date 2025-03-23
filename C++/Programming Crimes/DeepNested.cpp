#include <iostream>
#include <string>

void Mood(int &x ,std::string &mood , bool &debug){
    if(x==42){
        std::cout << "The meaning of life is within reach!\n";
    } else {
        std::cout << "Close, but not quite 42.\n";
    }

    if (mood == "chaotic") {
        std::cout << "The world is chaotic.\n";
    } else {
        std::cout << "Calm and orderly, as programming should be.\n";
    }

    if(debug){
        std::cout << "Debug mode enabled. Still chaotic, though.\n";
    }
}


int main() {
    int x = 42;
    std::string mood = "chaotic";
    bool debug = false;

    if (x > 0 && x < 100) {
        Mood(x, mood, debug);
    }else {
        std::cout << "x is out of range.\n";
    }

    return 0;
}
