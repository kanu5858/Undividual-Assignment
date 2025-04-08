#include <iostream>
using namespace std;

int ternarySearch(int arr[], int low, int high) {
    if (high >= low) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        
        if (arr[mid1] == arr[mid2]) {
            return mid1;  // You can adjust this based on your use case.
        } else if (arr[mid1] > arr[mid2]) {
            return ternarySearch(arr, low, mid2 - 1);  // Search the left part.
        } else {
            return ternarySearch(arr, mid1 + 1, high);  // Search the right part.
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = ternarySearch(arr, 0, n - 1);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
