//a simple comparison-based sorting
//finding the smallest element from the unsorted part and swapping it with the first unsorted element

/*
Find the smallest element in the array.

Swap it with the first element of the unsorted part.

Move to the next element and repeat the process.

Continue until the entire array is sorted.
*/

//Best case O(n^2)
//Worst case O(n^2)
//AVerage case O(n^2)

//Small dataset, memory effeciency, limited swaps, choose selection sort..s

#include <iostream>
using std::cout;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the smallest

        // Find the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found smallest element with the first element of the unsorted part
        std::swap(arr[i], arr[minIndex]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
