#include <iostream>
void changeValue(int x);

int main(){
	int x;
	x = 50;
	std::cout << "Before change value of x : " << x << "\n";
	changeValue(x);
	std::cout << "After change value of x : " << x << "\n";
	return 0;
}
void changeValue(int x)
{
	x += x;
	std::cout << "Change of x Value is : " << x << "\n";
}
