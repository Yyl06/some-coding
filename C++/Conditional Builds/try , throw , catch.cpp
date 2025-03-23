// program to divide two numbers and throw an exception if the divisor is 0

#include <iostream>
using namespace std;

int main() {
    float numerator, denominator, result;
    numerator = 9;
    denominator = 0;

    try {
        // throw an exception if denominator is 0
        if (denominator == 0)
            throw 0; // Throwing an integer
        result = numerator / denominator; // if denominator not zero
        cout << numerator << " / " << denominator << " = " << result << endl;
    } 
    catch (int exception) { // Catching an integer
        cout << "Error: Cannot divide by " << exception << endl;
    }

    return 0;
}