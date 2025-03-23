#include <iostream>

/*
int main(){
    int x = 5;
    int *px = &x;
    int y = 10;
    int *py = &y;
    //Dereferencing
    std::cout << "Number of x: " << x << "\n";
    std::cout << "Number of y: " << y << "\n";
    
    int temp;
    temp = x;
    x = y;
    y = temp;

    std::cout << "New x: " << x << "\n";
    std::cout << "New y: " << y << "\n";

    //Pointer Derefencing
    std::cout << "Number of x: " << x << "\n";
    std::cout << "Number of y: " << y << "\n";
    
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;

    std::cout << "New x: " << x << "\n";
    std::cout << "New y: " << y << "\n";
    return 0;
}*/
/*
void ArrayReversal(int *x, int size){
    int *start = x;
    int *end = x + size - 1;
    while(start < end){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

}
int main(){
    int size = 10;
    int arr[] = {5 , 10 , 15 , 20 , 25 , 30};

    for(int i = 0 ; i < 6 ; i++){
        std::cout << "Elements in the array : " << arr[i] << "\n";
    }

    ArrayReversal(arr, size);
    
    std::cout << "Reversed array : " << "\n";
    for(int i = 0 ; i < 6 ; i++){
        std::cout << arr[i] << "\n";
    }

    return 0;
}
*/
/*
void SearchNum(int x[] , int &size , int &num){
    for(int i = 0 ; i < size ; i++){
        if(num == x[i]){
            std::cout << "Found Number in the array." << "\n";
            return;
        }
    }
    num = -1;
    std::cout << "Error Code : " << num << " Cant Find Number in array." << "\n";
}

int main(){
    int size = 10;
    int arr[] = {5 ,10, 15, 20, 25, 30};
    int x;

    std::cout << "Enter a number for search : ";
    std::cin >> x;

    SearchNum(arr, size, x);
}
*/

/*
int main(){
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
*/
/*
int main(){
    int size;
    int *arr = new int[size];
    int *p = arr;

    std::cout << "Enter the array size : ";
    std::cin >> size;
    
    for(int i = 0 ; i < size ; i++){
        std::cout << "Enter a number : ";
        std::cin >> *p;
        p++;
    }
    p = arr;
int sum = 0;
for(int i = 0; i < size; i++){
    sum += *p;
    p++;
}
std::cout << "Sum of the array: " << sum << "\n";
delete[] arr;
}
*/
 
void Calcarr(int *x ,int &size, int &num){
    int *ap = x;
    std::cout << "Enter the size of the array : ";
    std::cin >> size;
    for(int i = 0 ; i < size ; i++){
        std::cout << "Enter an element : " << "\n";
        std::cin >> x[num == i];
        if(*ap % 2 == 0){
            *ap *=2;
        }else{
           *ap += 1;
        }
    }
}
int main(){
    int size;
    int arr[size];
    int num;

    Calcarr(arr, size , num);

    for(int i : arr){
        std::cout << "New array numbers : " << i << "\n";
    }
    std::cout << "\n";
}