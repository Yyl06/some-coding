#include <iostream>
using namespace std;

int main(){
    //While function that loops under a declarment
    
    int x;
    cout << "Enter a Number : ";
    cin >> x;
   
    while(x <= 10){
        cout << "The Number is Below than 10. " << "\n";
        cout << "Enter Another Number : " << "\n";
        cin >> x;
    }
    
    cout << "The Number is bigger than 10." << "\n";
    

    return 0;
}