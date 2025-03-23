#include<iostream>
#include "Pyramid.hpp"
using namespace std;

int main(){
	double length, width, height;
	int choice;
	int base;

	cout << "Length: ";
	cin >> length;
	cout << "\nWidth: ";
	cin >> width;
	cout << "\nHeight: ";
	cin >> height;

	Pyramid Pyramix(length, height, width);
	
	cout << "\nChoose (1-Area/2-Volume): ";
	cin >> choice;
	switch(choice){
		case 1:
			cout << "\nBase Shape (1-Square/2-Rectangle): ";
			cin >> base;
			
		switch(base){
			case 1:
			cout << "\nArea: " << Pyramix.GetArea(length, height);
			break;
			
			case 2:
			cout << "\nVolume: " << Pyramix.GetArea(length, width);
			break;
			
			default :
            cerr << "\nInvalid Input";
            break;
        }break;
        
        case 2 :
        cout << "Enter the Base Shape of the Pyramid (1-Square / 2-Rectangle)): ";
        cin >> base;

            switch (base){
            case 1 :
            cout << "Area of the Pyramid: " << Pyramix.GetVolume(length , height);
            break;

            case 2 :
            cout << "Volume of the Pyramid: " << Pyramix.GetVolume(length , width, height);
            break;

            default :
            cerr << "Invalid Input" << std::endl;
        }break;
        
        default :
        std::cerr << "Invalid Input" << std::endl;
        break;
	}
}
