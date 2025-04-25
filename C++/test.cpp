#include <iostream>

class Animal{
	protected:
		std::string sound;
};

class Dog : public Animal{
	public:
		Dog(){
			std::cout << sound << '\n';
		}
};