#include<iostream>
#include<cmath>
#define X std::cout << x << " "
#define Y std::cout <<
#define Error std::cerr << "Invalid!"
#define in std::cin >> 

inline void LogOps(){
    Y "1 = Natural Logarithm ln(y)" << "\n";
    Y "2 = Base-10 Logarithm log10(y) " << "\n";
    Y "3 = Base -2 Logarithm log2(y) " << "\n";
    Y "4 = Natural Logarithm of (1+y) " << "\n";
    Y "5 = Custom Base Logarithm (log(y)/log(x))" << "\n";
}

inline void Logarithms(double &x, double &y, int &op){
    double result;

    Y "Please Choose an Logarithm Operation : " << "\n";
    LogOps();
    in op;
    if(op == 5){
    Y "Please Enter Base for Logarithm : ";
    in x;
    Y "\n";
    Y "Please Enter Number : ";
    in y;
    Y "\n";
        if(x > 0 && y > 0 && y != 1){
        result = log(y)/log(x);
        Y "log Base " << x << "of " << y << " is = " << result << "\n";
    }else{
        Error;
    }}else{
    Y "Please Enter Base for Logarithm : ";
    in x;
    if(x > 0){
    switch(op){
        //Logarithms 
        //Natural Log
        case 1 :{
            result = log(x);
            Y "ln(x)= "<< result << "\n";
            break;
        }
        //Base 10 Log
        case 2 :{
            result = log10(x);
            Y "log10(x)= " << result << "\n";
            break;
        }
        //Base-2 Log
        case 3 :{
            result = log2(x);
            Y "log2(x)= " << result << "\n";
            break;
        }
        //Natural Log (1+y), Handling Float Issues
        case 4 :{
            result = log1p(x);
            Y "ln(1 + " << x << ") = " << result << "\n";
            break;
        }
        default:{
            Error << "\n";
        }
    }
}else{
    Error;
}
    }
}     