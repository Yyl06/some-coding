#include <iostream>

enum Weekday{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
};

enum class Weather{
    Sunny,
    Rainy,
    Cloudy,
    Snowy,
};

int main(){
    int x;
    enum Weekday day;
    std::cout << "Enter an Integer : ";
    std::cin >> x;

    return 0;
}