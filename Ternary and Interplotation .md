Find out about Ternary and Interpolation Searching algorisms. 
How they work?
What is the complexity analysis?
Implement them using C++.
Summaries you're finding.

### 1. Ternary Search

#### **How it Works:**
Ternary Search is a divide-and-conquer search algorithm that is similar to Binary Search, but instead of dividing the search space in half, it divides the search space into three parts. It is typically used to find the maximum or minimum value in a unimodal function (i.e., a function that increases then decreases, or vice versa).

**Steps of Ternary Search:**
1. Find two midpoints, `mid1` and `mid2`, such that:
   - `mid1 = low + (high - low) / 3`
   - `mid2 = high - (high - low) / 3`
   
2. Compare the values at `mid1` and `mid2`:
   - If `arr[mid1] > arr[mid2]`, then the maximum (or minimum) must be in the range from `low` to `mid2`, so update `high = mid2 - 1`.
   - If `arr[mid1] < arr[mid2]`, then the maximum (or minimum) must be in the range from `mid1 + 1` to `high`, so update `low = mid1 + 1`.
   - If `arr[mid1] == arr[mid2]`, then we have multiple possible solutions and can just reduce the range based on your specific use case.

3. Repeat the process until the range is reduced to a single point, which will give the maximum or minimum value.

#### **Complexity Analysis:**
- **Time Complexity:** The time complexity of Ternary Search is **O(log₃(n))**, because the problem size is divided by three at each step.
- **Space Complexity:** The space complexity is **O(1)** because we are using a constant amount of extra space.

#### **C++ Implementation:**

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
```

### 2. Interpolation Search

#### **How it Works:**
Interpolation Search is an improvement over Binary Search for uniformly distributed data. Instead of dividing the data in half, it tries to estimate the position of the target value using a linear interpolation formula. This is based on the assumption that the values are uniformly distributed.

**Steps of Interpolation Search:**
1. Calculate the probable position of the element using the formula:
   - `pos = low + ((high - low) * (target - arr[low])) / (arr[high] - arr[low])`
   
2. If `arr[pos] == target`, return the position.
3. If `arr[pos] > target`, repeat the search in the left half (`high = pos - 1`).
4. If `arr[pos] < target`, repeat the search in the right half (`low = pos + 1`).

#### **Complexity Analysis:**
- **Time Complexity:** The time complexity of Interpolation Search is **O(log(log(n)))** for uniformly distributed data. In the worst case (when the data is not uniformly distributed), the complexity is **O(n)**.
- **Space Complexity:** The space complexity is **O(1)**, as it only requires a constant amount of extra space.

#### **C++ Implementation:**

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
```

### Summary

- **Ternary Search**: A divide-and-conquer algorithm that divides the search range into three parts. It has a time complexity of **O(log₃(n))** and is used mainly for unimodal functions.
  
- **Interpolation Search**: An algorithm based on the assumption that the data is uniformly distributed. It has a time complexity of **O(log(log(n)))** for uniform data but can degrade to **O(n)** in the worst case. It performs better than Binary Search on uniformly distributed data.

Both algorithms are efficient in specific scenarios and should be chosen depending on the nature of the data you're dealing with.