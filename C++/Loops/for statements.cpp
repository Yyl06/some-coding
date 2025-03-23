#include <iostream>

int main(){
	//Column 
	/*for(int i = 10; i >= 0 ; i--){
		// 10 9 8 7 6 5 4 3 2 1 0 , i-- = i-1
		//Row
		for (int j = 0; j <= i ; j++){
			// j = 0, j <= i(j will stop looping when int i reaches 3),j = 1(completed) j++ = j+1
			std::cout << "*";
	}
	std::cout << "\n";
	}
	*/

	int myNumbers[5] = {10, 20, 30, 40, 50};
	//for (Datatype variable ; ArrayDataTypeName)
    for (int i : myNumbers) {
    std::cout << i << "\n";
}
	return 0;
}
