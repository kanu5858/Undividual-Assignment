#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void findSecondAndThirdLargest(const vector<int>& nums, int& firstLargest, int& secondLargest, int& thirdLargest) {
    if (nums.size() < 3) {
        firstLargest = secondLargest = thirdLargest = INT_MIN; // Not enough elements in the array
        return;
    }

    firstLargest = secondLargest = thirdLargest = INT_MIN;

    for (size_t i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        if (num > firstLargest) {
            thirdLargest = secondLargest;
            secondLargest = firstLargest;
            firstLargest = num;
        } else if (num > secondLargest) {
            thirdLargest = secondLargest;
            secondLargest = num;
        } else if (num > thirdLargest) {
            thirdLargest = num;
        }
    }
}

int main() {
    int n, select;

    while (true) {
        cout << "Enter the size of the array: ";
        cin >> n;

        if (n < 3) {
            cout << "Array should have at least 3 elements." << endl;
            return 1;
        }

        vector<int> nums(n);
        cout << "Enter the elements of the array: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        int firstLargest, secondLargest, thirdLargest;
        findSecondAndThirdLargest(nums, firstLargest, secondLargest, thirdLargest);

        if (secondLargest != INT_MIN && thirdLargest != INT_MIN) {
            int choice;
            cout << "Which element do you want to print? (1 - Largest, 2 - Second Largest, 3 - Third Largest): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Largest: " << firstLargest << endl;
                    break;
                case 2:
                    cout << "Second largest: " << secondLargest << endl;
                    break;
                case 3:
                    cout << "Third largest: " << thirdLargest << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        } else {
            cout << "Not enough elements in the array to determine the second and third largest." << endl;
        }

        cout << "Do you want to try again?" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;

        cin >> select;
        if (select == 2) {
            cout << "Have a nice coding. Goodbye." << endl;
            break;
        } else if (select != 1) {
            cout << "Invalid input." << endl;
            break;
        }
    }

    return 0;
}

