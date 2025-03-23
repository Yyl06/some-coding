#include <iostream>
void change();
int main (){
	change();
	change();
	return 0;
}
void change(){
	static int x=0;
	x= x+1;
	std::cout << " x in change value : " << x << "\n";
}
