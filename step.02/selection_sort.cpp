#include <bits/stdc++.h>
using namespace std;

/*
 * Selection Sort Algorithm:
 * - For each position in the array, find the smallest element in the remaining unsorted part.
 * - Swap the smallest element with the element at the current position.
 * 
 * Time Complexity:
 * - Best Case: O(N^2)
 * - Average Case: O(N^2)
 * - Worst Case: O(N^2)
 * Explanation: The nested loop runs for (n-1) + (n-2) + ... + 1 iterations = O(N^2).
 * 
 * Space Complexity: O(1) (In-place sorting).
 */

class Solution {
public:
    // Function to perform selection sort
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) { // Iterate through each position
            int mini = i; // Assume the current position has the smallest element

            // Find the smallest element in the remaining unsorted part
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[mini]) {
                    mini = j; // Update the index of the smallest element
                }
            }

            // Swap the smallest element with the current position
            swap(arr[i], arr[mini]);
        }
    }
};

int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    Solution sol; // Create an object of the Solution class
    sol.selectionSort(arr, n); // Perform selection sort

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Dry Run Example:

Input: arr = {64, 25, 12, 22, 11}
Step-by-step process:
1. i = 0:
    - Find the smallest element from index 0 to 4: mini = 4 (value 11).
    - Swap arr[0] with arr[4]: arr = {11, 25, 12, 22, 64}.
2. i = 1:
    - Find the smallest element from index 1 to 4: mini = 2 (value 12).
    - Swap arr[1] with arr[2]: arr = {11, 12, 25, 22, 64}.
3. i = 2:
    - Find the smallest element from index 2 to 4: mini = 3 (value 22).
    - Swap arr[2] with arr[3]: arr = {11, 12, 22, 25, 64}.
4. i = 3:
    - Find the smallest element from index 3 to 4: mini = 3 (value 25).
    - Swap arr[3] with arr[3] (no change): arr = {11, 12, 22, 25, 64}.
5. i = 4:
    - Already sorted.

Output: {11, 12, 22, 25, 64}.
*/

