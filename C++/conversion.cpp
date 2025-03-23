#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#define M_PI 3.14159265358979323846

/*
double FoottoMeter(double foot){
    return foot * 0.3048;
}

double MetertoFoot(double meter)
{
    return meter / 0.3048;
}

int main(){
    
    const int max = 5;
    double foot[max] , meter[max];
    std::cout << "\t" << "Feet" << "\t" << " Meters" << "\n";
    for(int i = 1 ; i <= 5 ; i++){
        foot[i] = i;
        meter[i] = FoottoMeter(foot[i]);
        std::cout << "\t" << foot[i] << "\t" << meter[i] << "\n";
        return 0;
        
    }
*/

/*
void InputDistance(int &x1 , int &x2 , int &y1 , int &y2){
    std::cout << "Enter the Center Point x1 Value: ";
    std::cin >> x1;
    std::cout << "Enter the Center Point y1 Value: ";
    std::cin >> y1;
    std::cout << "Enter the Side Point x1 Value: ";
    std::cin >> x2;
    std::cout << "Enter the Side Point y2 Value: ";
    std::cin >> y2;

}

double Distance(int x1 , int x2 , int y1 , int y2){
    return sqrt(pow(x2 - x1 , 2) + pow(y2 - y1 , 2));
}

double Radius(double x1 , double x2 , double y1 , double y2){
    return Distance(x1 , x2 , y1 , y2);
}

double Circumference(double radius){
    return 2 * M_PI  * radius;
}

double Area(double radius){
    return M_PI * pow(radius , 2);
}

int main(){
    int x1 , x2 , y1 , y2;
    InputDistance(x1 , x2 , y1 , y2);
    Distance(x1 , x2 , y1 , y2);
    std::cout << "The Distance between the two points is: " << Distance(x1 , x2 , y1 , y2) << std::setprecision(3) << std::fixed << "\n";
    std::cout << "The Radius of the Circle is : " << Radius(x1, x2, y1, y2) << std::setprecision(3) << std::fixed << "\n";
    std::cout << "The Circumference of the Circle is : " << Circumference(Radius(x1, x2, y1, y2)) << std::setprecision(3) << std::fixed << "\n";

    return 0;
    
}
*/

void Order(int &spools, int &stock , int &charges){
    stock = 100;
    do{
        std::cout << "Enter the Number of Spools For Order :  ";
        std::cin >> spools;
        if(spools < 1){
            std::cout << "Invalid Order" << "\n";
        }
    }while(spools < 1);
    do{
        std::cout << "Enter the Number of Stock: ";
        std::cin >> stock;
    }while(stock < 1);

    std::string yesno;
    int special;
    do{
        std::cout << "Special Shipping Charges? (yes/no): ";
        std::cin >> yesno;
            if(yesno == "yes" || yesno == "YES" || yesno == "Yes"){
                std::cout << "What are the amount Special Charges: ";
                std::cin >> special;
                }if (special < 0){
                    std::cout << "Invalid Charges" << "\n";
            }else if (yesno == "no"|| yesno == "NO" || yesno == "No"){
                special = 0;
            }
    }while(yesno != "yes" && yesno != "YES" && yesno != "Yes" && yesno != "no" && yesno != "NO" && yesno != "No");
        special *= spools;
        charges += special;
}

void DisplayStatus(int stock , int spools , double specialcharges , double shipping = 10){
    int readyToShip = (spools <= stock) ? spools : stock;
    int backOrder = (spools > stock) ? spools - stock : 0;
    double subtotal = readyToShip * 100;
    double totalShipping = readyToShip * (shipping + specialcharges);
    double totalOrder = subtotal + totalShipping;

    std::cout << "Number of Spools Ordered: " << spools << "\n";
    std::cout << "Number of Spools in Stock: " << stock << "\n";
    std::cout << "Special Shipping Charges: " << specialcharges << "\n";
    std::cout << "Shipping Charges: " << shipping << "\n";
    std::cout << "Total Charges: " << specialcharges + shipping << "\n";
    std::cout << "\n";
    std::cout << "Order Status:\n";
    std::cout << "Spools ready to ship: " << readyToShip << "\n";
    std::cout << "Spools on backorder: " << backOrder << "\n";
    std::cout << "Subtotal of the portion ready to ship: $" << subtotal << "\n";
    std::cout << "Total shipping and handling charges: $" << totalShipping << "\n";
    std::cout << "Total of the order ready to ship: $" << totalOrder << "\n";
}
int main (){
    int spools , stock , charges = 100;
    Order(spools , stock , charges);
    DisplayStatus(stock , spools , charges , 100);
    return 0;
}