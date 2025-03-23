#include <iostream>
void convertMeter(float km);

int main(){
	float km;
	std::cout << "Enter a distance In KiloMeters :";
	std::cin >> km;
	convertMeter(km);
	return 0;
}
void convertMeter(float km){
	float Meter;
	Meter = km * 1000;
	std::cout<< "The Distance in of Kilometere you Entered In Meter : " << Meter << "\n";
}
