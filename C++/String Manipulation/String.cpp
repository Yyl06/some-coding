#include <string>
#include <iostream>
using std::string;

int main(){
    /*
    string s1;
    string s2 = "New York";
    string s3(60, '*');
    string s4 = s3;
    string s5 = "N";
    string s6 = "78";

*/

string firstName;
string Name;
string str;

firstName = "Elizabeth";
Name = firstName + " Jones";
str = "It is Sunny.";

std::cout << firstName.length() << "\n";
std::cout << Name.length() << "\n";
std::cout << str.length() << '\n';

std::cout << firstName.find(Name) << '\n';
std::cout << Name.find("Jones") << "\n";
std::cout << str.find("i") << "\n";
std::cout << firstName.find(Name + "J") << "\n";
std::cout << str.find('b' + 'c') << "\n";


return 0;
}