#include <iostream>

//A Void Function that will get the value entered by the user of the name by referencing
void an (std::string &flyer);


int main (){
	std::string flyer;
	std::cout<<"press enter a word";
	std::cin>>flyer;
	
	//We know that functionname(Real Parameters)to let the function knows what,where to read values
	an (flyer); //Now the function knows that an(flyer), taking the int main()'s parameters and the void function itself,
	//Will take reference from the int main()'s flyer and use it on the void an(std::string &flyer)'s function.
	//this we call"call function"
	//we only need to set datatype in 
	return 0;
}

void an (std::string &flyer){
	std::cout<<flyer;
	// Will output the entered value by the user from int main() by dereferencing
}
