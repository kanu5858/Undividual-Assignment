#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int target) {
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Calculate the position using the interpolation formula
        int pos = low + ((high - low) * (target - arr[low])) / (arr[high] - arr[low]);
        
        // Check if the target is at the calculated position
        if (arr[pos] == target) {
            return pos;
        }
        
        // If target is smaller, search the left half
        if (arr[pos] > target) {
            high = pos - 1;
        }
        // If target is larger, search the right half
        else {
            low = pos + 1;
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {10, 12, 13, 16, 18, 20, 25, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;
    int result = interpolationSearch(arr, 0, n - 1, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
