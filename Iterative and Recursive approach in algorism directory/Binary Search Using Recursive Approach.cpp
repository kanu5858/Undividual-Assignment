#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1;  // Base case: target not found
    }
    
    int mid = left + (right - left) / 2;
    
    // Check if target is at mid
    if (arr[mid] == target) {
        return mid;
    }
    // If target is smaller, search in the left half
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    // If target is larger, search in the right half
    else {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
