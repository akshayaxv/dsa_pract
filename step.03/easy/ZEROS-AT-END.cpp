#include <bits/stdc++.h>
using namespace std;

/*
### Problem Statement:
Given an array `arr[]` of size `n`, the task is to move all the zeros in the array to the end 
while maintaining the relative order of the non-zero elements.

#### Example:
Input: arr[] = {1, 0, 2, 3, 0, 4, 0}
Output: arr[] = {1, 2, 3, 4, 0, 0, 0}

### Constraints:
1. 1 <= n <= 10^5
2. -10^9 <= arr[i] <= 10^9
*/

/*
### Brute Force Approach:
1. Create a temporary array `temp` of the same size as `arr`.
2. Traverse the original array and copy all non-zero elements into `temp`.
3. Fill the remaining positions in `temp` with zeros.
4. Copy the elements of `temp` back to the original array.

#### Code for Brute Force Approach:
void pushZerosToEndBruteForce(int arr[], int n) {
    // Create a temporary array
    int temp[n];
    int index = 0;

    // Copy all non-zero elements to temp
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[index++] = arr[i];
        }
    }

    // Fill the remaining positions in temp with zeros
    while (index < n) {
        temp[index++] = 0;
    }

    // Copy elements from temp back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

#### Time Complexity:
- Best Case: O(n) (Single pass to copy elements + single pass to copy back).
- Space Complexity: O(n) (Additional array used for storing elements).

#### Dry Run (Brute Force):
Input: arr[] = {1, 0, 2, 3, 0, 4, 0}, n = 7
Step 1: Copy non-zero elements to `temp`: temp = {1, 2, 3, 4, _, _, _}
Step 2: Fill remaining positions with zeros: temp = {1, 2, 3, 4, 0, 0, 0}
Step 3: Copy `temp` back to `arr`: arr = {1, 2, 3, 4, 0, 0, 0}
*/

/*
### Optimal Approach (In-place Two-pointer Technique):
1. Maintain two pointers `i` and `j`:
   - `i` tracks the last position where a non-zero element was placed.
   - `j` traverses the array.
2. Whenever `arr[j]` is non-zero, increment `i` and swap `arr[i]` and `arr[j]`.
3. This ensures all non-zero elements are placed at the beginning, and zeros are shifted to the end.

#### Time Complexity:
- Best Case: O(n) (Single pass through the array).
- Worst Case: O(n) (Single pass through the array).
- Space Complexity: O(1) (No additional memory used).

#### Dry Run (Optimal Approach):
Input: arr[] = {1, 0, 2, 3, 0, 4, 0}, n = 7
Initialization: i = -1, j = 0
Step 1: j = 0, arr[j] = 1, non-zero → i = 0, swap(arr[0], arr[0]) → arr = {1, 0, 2, 3, 0, 4, 0}
Step 2: j = 1, arr[j] = 0, zero → no change
Step 3: j = 2, arr[j] = 2, non-zero → i = 1, swap(arr[1], arr[2]) → arr = {1, 2, 0, 3, 0, 4, 0}
Step 4: j = 3, arr[j] = 3, non-zero → i = 2, swap(arr[2], arr[3]) → arr = {1, 2, 3, 0, 0, 4, 0}
Step 5: j = 4, arr[j] = 0, zero → no change
Step 6: j = 5, arr[j] = 4, non-zero → i = 3, swap(arr[3], arr[5]) → arr = {1, 2, 3, 4, 0, 0, 0}
Step 7: j = 6, arr[j] = 0, zero → no change
Output: arr[] = {1, 2, 3, 4, 0, 0, 0}
*/

class Solution {
public:
    void pushZerosToEnd(int arr[], int n) {
        // Optimal Solution: In-place Two-pointer Technique
        int i = -1; // Tracks the position to place the next non-zero element
        for (int j = 0; j < n; j++) {
            if (arr[j] != 0) {
                i++;               // Move the pointer for non-zero elements
                swap(arr[i], arr[j]); // Swap the current non-zero element to its correct position
            }
        }
    }
};

int main() {
    Solution obj;
    int arr[] = {1, 0, 2, 3, 0, 4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Brute Force Example (Commented out for explanation purposes)
    // Uncomment to test brute force approach:
    /*
    obj.pushZerosToEndBruteForce(arr, n);
    */

    cout << "Before Moving Zeros: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    obj.pushZerosToEnd(arr, n);

    cout << "After Moving Zeros: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
