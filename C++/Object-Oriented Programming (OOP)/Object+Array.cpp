#include <iostream>

class Inventory{
    private:
        char *description;
        double cost;
        int units;

    public:
        Inventory();
        Inventory(const char desc[]);
        Inventory(const char desc[] , double c , int u);
        ~Inventory();
};

int main(){
    Inventory Items[40];//1st Constructor as Default

    return 0;
}