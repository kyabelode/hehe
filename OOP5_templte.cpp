/*Write a function template for selection sort that inputs, sorts and outputs an integer array 
and a float array. */

#include <iostream>
using namespace std;

// Template function for selection sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Find the index of the minimum element in the remaining unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted portion
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to print the elements of the array
template <typename T>
void printArray(const T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Input for integer array
    int n;
    cout << "Enter the number of elements in the integer array: ";
    cin >> n;
    int intArray[n];
    cout << "Enter the elements of the integer array: ";
    for (int i = 0; i < n; ++i) {
        cin >> intArray[i];
    }

    cout << "Original integer array: ";
    printArray(intArray, n);
    selectionSort(intArray, n);
    cout << "Sorted integer array:   ";
    printArray(intArray, n);

    // Input for float array
    int m;
    cout << "Enter the number of elements in the float array: ";
    cin >> m;
    float floatArray[m];
    cout << "Enter the elements of the float array: ";
    for (int i = 0; i < m; ++i) {
        cin >> floatArray[i];
    }

    cout << "Original float array:   ";
    printArray(floatArray, m);
    selectionSort(floatArray, m);
    cout << "Sorted float array:     ";
    printArray(floatArray, m);

    return 0;
}
