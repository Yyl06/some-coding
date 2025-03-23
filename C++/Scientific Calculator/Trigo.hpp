#include<iostream>
#include<cmath>
#define X std::cout << x << " "
#define Y std::cout <<
#define Error std::cerr << "Invalid!"
#define in std::cin >> 

inline void TriOps(){
    Y "1 = tan " << "\n";
    Y "2 = sin " << "\n";
    Y "3 = cos " << "\n";
    Y "4 = tanh " << "\n";
    Y "5 = sinh " << "\n";
    Y "6 = cosh " << "\n";
}

inline void Trigonometric (double &x, double &y, int &op){
    double result;
    double z;
    Y "Please Choose an Trigonometric Operation : " << "\n";
    TriOps();
    in op;
    if(op >= 1 && op <= 3 ){
        Y "z = x/y : ";
        Y "Please Enter x for calculation : ";
        in x;
        Y "Please Enter y for calculation : ";
        in y;
        z=x/y;
    }else if (op >= 4 && op <= 6)
    {
        Y "Please Enter x for calculation : ";
        in x;
    }else{
        Error;
    }

    switch(op){
        //Trigonometric
        //tan
        case 1 :{
            result = tan(z);
            Y "tan(z) = "<< result << "\n";
            break;
        }
        //sin
        case 2 :{
            result = sin(z);
            Y "sin(z)= " << result << "\n";
            break;
        }
        //cos
        case 3 :{
            result = cos(z);
            Y "sin(z)= " << result << "\n";
            break;
        }
        //tanh
        case 4 :{
            result = tanh(x);
            Y "tanh(x)= " << result << "\n";
            break;
        }
        //sinh
        case 5 :{
            result = sinh(x);
            Y "sinh(x)= " << result << "\n";
            break;
        }
        //cosh
        case 6 :{
            result = cosh(x);
            Y "cosh(x)= " << result << "\n";
            break;
        }
        default:{
            Error << "\n";
            break;
        }
    }
    }
    