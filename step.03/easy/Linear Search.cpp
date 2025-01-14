#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem Statement:
 * Given an array (vector) `arr[]` and a target value `num`, 
 * the task is to find the index of the target value in the array using Linear Search.
 * If the element is present, return its index; otherwise, return -1.
 */

/*
 * Example 1:
 * Input: arr[] = {1, 2, 3, 4, 5}, num = 3
 * Output: 2
 * Explanation: 3 is present at the 2nd index.
 * 
 * Example 2:
 * Input: arr[] = {5, 4, 3, 2, 1}, num = 5
 * Output: 0
 * Explanation: 5 is present at the 0th index.
 */

// Brute Force Approach: Linear Search
// Time Complexity: O(N) -> We traverse the entire array in the worst case.
// Space Complexity: O(1) -> We don't use extra space, only pointers.

int search(const vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            return i;  // Return the index if the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}

// Brute Force Dry Run:
// Input: arr[] = {1, 2, 3, 4, 5}, target = 3
// Step 1: i = 0, arr[0] = 1, target != arr[0], continue to next index
// Step 2: i = 1, arr[1] = 2, target != arr[1], continue to next index
// Step 3: i = 2, arr[2] = 3, target == arr[2], return 2

// Time Complexity: O(N)
// Worst Case: O(N) -> If the target is at the last position or not present in the array at all.
// Best Case: O(1) -> If the target is at the first position.

int main() {
    // Input array (vector)
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 4;  // Element to search for

    // Perform Linear Search
    int location = search(arr, target);

    // Output the result
    if(location != -1) {
        cout << "Element Found At Index: " << location << endl;
    } else {
        cout << "Element Not Found!" << endl;
    }

    return 0;
}

/*
 * Complexity Analysis:
 * - Time Complexity: O(N) where N is the number of elements in the array.
 * - Space Complexity: O(1) as no extra space is used except for variables.
 * - The time complexity in the worst case occurs when the target is not present or is at the end of the array.
 */
