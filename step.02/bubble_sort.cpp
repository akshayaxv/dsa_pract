#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement:
 * Implement the Bubble Sort algorithm to sort an array of integers in ascending order.
 * 
 * Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.
 * After each pass, the largest element in the unsorted part of the array moves to its correct position.
 * 
 * Example Input:
 * arr = {64, 34, 25, 12, 22}
 * Output:
 * arr = {12, 22, 25, 34, 64}
 */

/*
 * Time Complexity:
 * - Best Case: O(n) when the array is already sorted (no swaps needed).
 * - Worst Case: O(n^2) when the array is sorted in reverse order.
 * - Average Case: O(n^2) for random order of elements.
 * 
 * Space Complexity:
 * - O(1), as the sorting is done in place without extra memory.
 */

class Solution {
public:
    // Function to sort the array using Bubble Sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Outer loop controls the number of passes
        for (int i = n - 1; i >= 0; i--) {
            // Inner loop compares adjacent elements
            for (int j = 0; j < i; j++) {
                // If the current element is greater than the next one, swap them
                if (arr[j + 1] < arr[j]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Solution obj;
    obj.bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Dry Run:
 * Input: arr = {64, 34, 25, 12, 22}, n = 5
 *
 * Pass 1:
 * - Compare 64 and 34 → Swap → arr = {34, 64, 25, 12, 22}
 * - Compare 64 and 25 → Swap → arr = {34, 25, 64, 12, 22}
 * - Compare 64 and 12 → Swap → arr = {34, 25, 12, 64, 22}
 * - Compare 64 and 22 → Swap → arr = {34, 25, 12, 22, 64}
 *
 * Pass 2:
 * - Compare 34 and 25 → Swap → arr = {25, 34, 12, 22, 64}
 * - Compare 34 and 12 → Swap → arr = {25, 12, 34, 22, 64}
 * - Compare 34 and 22 → Swap → arr = {25, 12, 22, 34, 64}
 *
 * Pass 3:
 * - Compare 25 and 12 → Swap → arr = {12, 25, 22, 34, 64}
 * - Compare 25 and 22 → Swap → arr = {12, 22, 25, 34, 64}
 *
 * Pass 4:
 * - Compare 12 and 22 → No Swap → arr = {12, 22, 25, 34, 64}
 *
 * Final Output: arr = {12, 22, 25, 34, 64}
 */
