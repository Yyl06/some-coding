#include <iostream>

int main(){
   /*int ArrayName[10];
    // Array size with 10 elements
    // Array starts from element 0
    
    int Array[3]={1,2,3};
    std::cout << Array[2] << "\n";
    

    //Matrices
    int Matrices[2][3] = {
        {1,2,3},
        {4,5,6,}
    };
    //1st [] for row (Straight line)
    //2nd [] for column (Horizontally Line)

    //Row Printing
    for(int i = 0 ; i < 2 ; i++){
        //Column Printing
        for (int j = 0 ; j < 3 ; j++) {
        std::cout << Matrices[i][j];
        }
        std::cout << "\n";
    }
    

    //Table (Dimensional)
    //Unchanged value (Cannot be changed)
    const int x = 3;
    const int y = 3;
    int table[x][y];

    int i;
    int j;

    std::cout << "Enter the Row u like to input : ";
    std::cin >> i;

    std::cout << "Enter the Column u like to input : ";
    std::cin >> j;

    
    //Output the table(results)
    for(int i = 0 ; i < x ; i++){
        for (int j = 0 ; j < y ; j++) {
            std::cout << " The number for the array element [" << i << "][" << j << "] : " ;
            std::cout << table[i][j];
        }
        std::cout << "\n";
    }

    const int x = 2;
    const int y = 2;
    //Now , We have 2x2 table
    int table[x][y];


    //Using a for loop to modify the table
    for(int i = 0 ; i < x ; i++){
        for(int j = 0 ; j < y ; j++){
            std::cout << "Enter a number for the array element [" << i << "][" << j << "] : ";
            std::cin >> table[i][j];
        }
        std::cout << "\n";
    }
    
    //Output the table(results)
    for(int i = 0 ; i < x ; i++){
        for (int j = 0 ; j < y ; j++) {
            std::cout << " The number for the array element [" << i << "][" << j << "] : " ;
            std::cout << table[i][j];
        }
        std::cout << "\n";
    }*/

    //array for loop
    int Arrays[5]={1,2,3,4,5};
    for (int i : Arrays) {
    std::cout << i << "\n";
    }
//Array = Pointer/References
return 0;
}
