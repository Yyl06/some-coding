//Heap sort, building a max heap(Complete binary tree) to sort elements
//Works well for large datasets where memory constraints exist(Doesnt consume extra memory).
//Useful for priority queue implementations.
//Not the best for nearly sorted arrays, as Quick Sort might be more efficient.

/*
Building the Heap: O(n)
Heapify per extraction: O(log n)
Total extraction: O(n log n)
Overall: O(n log n)
*/

#include <iostream>
using std::cout;

// Function to heapify a subtree rooted at index 'i'
void heapify(int arr[], int n, int i) {
    int largest = i; // Assume root is the largest
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Main function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Heapify the reduced heap
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver code
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
