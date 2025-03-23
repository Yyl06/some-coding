#include <iomanip>
#include <iostream>

using namespace std;


const int x = 10;//10 Students
const int y = 5;//Each Students registered 5 subjects
void DisplayTable(int table[x][y]){
    for(int row = 0 ; row < x ; row++){
        std::cout << "Student " << row + 1 << ": " << "\n";
        for(int col = 0 ; col < y ; col ++){
            std::cout << table[row][col] << " ";
    }
    std::cout << "\n";
  }
}

int main(){
    int table[x][y];
    std::cout << "Enter Student Name : " << x << "Marks Each On Subjects : " << y << "\n";
    for(int row = 0 ; row < x ; row++){
        std::cout << "Student : " << row + 1 << " : " << "\n";
        for(int col = 0 ; col < y ; col++){
            std::cout << "Subject : " << col + 1 << " : " << "\n";
        }
    }
    DisplayTable(table);
/*
const int product = 10;

double price[10];
double total = 0;
double average = 0;
int bil;//int i;

//read price
for(bil=0 ; bil < product ; bil++){
cout << "Enter price:";
cin >>price[bil];
total += price[bil];
// price[0] + price[1] + ~ price[9] = total 
}

//calculate average
average = total/product;

//display all prices and the average
cout << "\nList of prices:"<<endl;
for(bil = 0 ; bil < product ; bil++)
{
cout << price[bil] << endl;
} 

cout << "Average is : " << average << "\n"; 
*/
return 0;
}