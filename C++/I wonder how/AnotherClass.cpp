#include <iostream>

class AnotherClass{
    public:
    int addAmount(class NewClass &nClass);
};
class NewClass{
    private:
    int amount = 50;
    friend int AnotherClass::addAmount(NewClass &nClass);
};

int AnotherClass::addAmount(NewClass &nClass){ return nClass.amount; };

int main(){
    NewClass nClass;
    AnotherClass aClass;
    std::cout << "The amount is: " << aClass.addAmount(nClass) << std::endl;
    return 0;
}