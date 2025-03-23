#include <iostream>
#include <fstream>
#include <vector>


int main(){
    std::fstream Binary("data.bin",  std::ios::in | std::ios::out | std::ios::binary);
    int x;

    std::cout << "Enter Numbers to Multiply: ";
    std::cin >> x;

    //int numbers[x] is not allowed since this is C++ u mf, C++ does not support Variable-Length Arrays(VLA)
    //You can use Smart Pointers, Heap Allocation(new[], delete[])
    //int number[] = new number[x];
    std::vector<int> numbers(x);
    for(int i = 0; i < x ; i++){
        numbers[i] = i+1;
    }

    //Writing to File
    //.read(char *Str(Raw Memory Manipulation mf, make it as bytes..), streamsize Count)
    //reinterpret_cast<type of pointer>(variable)
    //streamsize Count = x*sizeof(int)
    //reinterpret_cast<new_type>(expression);
    Binary.write(reinterpret_cast<char*>(numbers.data()), x*sizeof(int));
    Binary.close();
    std::cout << "Binary File Written Sucessfully! " << "\n";

    std::fill(numbers.begin(), numbers.end(), 0);

    //Reading from File
    Binary.read(reinterpret_cast<char*>(numbers.data()), x*sizeof(int));
    Binary.close();

    std::cout << "Numbers of Binary Mode: ";
    for(int i = 0 ; i < x ; i++){
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
    //delete[] number;

    return 0;
}