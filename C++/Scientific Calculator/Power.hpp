#include<iostream>
#include<cmath>
#define X std::cout << x << " "
#define Y std::cout <<
#define Error std::cerr << "Invalid!"
#define in std::cin >> 

inline void pow_sqrtops(){
    Y "1 = x To The Power of y (x^y)" << "\n";
    Y "2 = Square Root of (√x)" << "\n";
    Y "3 = Custom x to the Root of the y (x^1/y)" << "\n";
}

inline void pow_sqrt(double &x,double &y,int &op){
    double result;

    Y "Choose an Operation : " << "\n";
    pow_sqrtops();
    in op;
    //Square Root
    if(op == 2){
        Y "Please Enter a Number : ";
        in x;
        Y "\n";
            if (x >= 0) {
            result = sqrt(x);
            Y "Square Root of " << x << " = " << result << "\n";
            }else {
            Error << " Unable To Square Root Numbers Lower Than 0!" << "\n";
            }
    }else{
        Y "Enter a Number : ";
        in x;
        Y "\n";
        Y "Enter Another Number : ";
        in y;
        Y "\n";
        switch(op){
            //Power
            case 1 :{
                result = pow(x,y);
                X << " To The Power of  " << y << " = " << result << "\n";
                break;
                }
            //Higher Than Square Roots(Enter in fraction form)
            case 3 :{
                if(y != 0){
                result = pow(x,y);
                X << "To The Power of " << y << " = " << result << "\n";
                }else{
                    Error << "\n";
                }
                break;
            }
            default :{
                Error << "\n";
            }
        }
    }
} 
