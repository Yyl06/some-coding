#include <iostream>
#define X std::cout << x << " "
#define Y std::cout <<
#define Error std::cerr << "Invalid!"
#define in std::cin >> 

inline void Ariops(){
    Y "1 = Addition (+)" << "\n";
    Y "2 = Subtraction (-)" << "\n";
    Y "3 = Multiply (*)" << "\n";
    Y "4 = Division (/)" << "\n";
    Y "5 = Division Remainder" << "\n";
}


inline void Arimethic(double &x, double &y ,int &op){
    Y "Enter A Number :";
    in x;
    Y "\n";
    Y "Enter Another Number :";
    in y;
    Y "\n";
    Y "Choose an Operator :" << "\n";
    Ariops();
    in op;

    double results;
    char ops[5] = {'+' , '-', '*', '/','%' }; 
    switch (op){
        case 1 :{
            results = x+y;
            X << ops[0] << y << "  " << " = " << results << "\n";
            break;
        }
        case 2 :{
            results = x-y;
            X << ops[1] << y << "  " << " = " << results << "\n";
            break;
        }
        case 3 :{
            results = x*y;
            X << ops[2] << y << "  " << " = " << results << "\n";
            break;
        }
        case 4 :{
            if (y != 0) {
                results = x/y;
                X << ops[3] << y << "  " << " = " << results << "\n";
                break;
            }else {
            Error << " Division by 0 is zero ! We are unable to calculate ! " << "\n";
            break;
            }
        }
        case 5 : {
            if (y != 0){
                int num1 = static_cast<int>(x);
                int num2 = static_cast<int>(y);

                int remainder = num1 % num2;
                X << ops[4] << y << "  " << "= " << remainder << "\n";
                break;
            }else {
                Error << "Division by 0 is zero ! They Do Not Have Remainders ! " << "\n";
                break;
            }
        }
        default:{
            std::cerr << "Unexpected Error !" << "\n";
            break;
        }
    }
}