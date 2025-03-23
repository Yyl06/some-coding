#include <cstddef>
#include <string>
#include <iostream>
using std::string;

int main(){
    string s = "Hello World!";

    std::cout << "Length: " << s.length() << "\n";

    std::cout << "Substring(0-4): " << s.substr(0,5) << "\n";

    size_t pos = s.find("World");
    if(pos != std::string::npos){
        std::cout << "Found at: " << pos << "\n";
    }

    s.replace(7, 5, "C++");
    std::cout << "After Replace: " << s << "\n";

    s.append(" Enjoy Coding!");
    std::cout << "After Append: " << s << "\n";

    return 0;
}