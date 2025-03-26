//Choose a pivot(random element)
//Every elements smaller than the pivot go to the left, vice versa
//using recursion to both halves
//Very efficient for large datasets
//In-place sorting (no extra memory needed like Merge Sort)
//Good for general-purpose sorting

//Best case: O(n log n)
//Worst case: (Unbalanced Partitioning, already sorted array without optimizations): O(n^2)
//Average case: O(n log n)

#include <iostream>
using std::cout;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {   // If the current element is smaller than the pivot
            i++;
            std::swap(arr[i], arr[j]); // Swap elements
        }
    }
    std::swap(arr[i + 1], arr[high]); // Swap pivot to its correct position
    return i + 1;  // Return the partition index
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        quickSort(arr, low, pi - 1);  // Sort the left part
        quickSort(arr, pi + 1, high); // Sort the right part
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
