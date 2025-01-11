#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement:
 * Implement the Insertion Sort algorithm to sort an array of integers in ascending order.
 * .
 * Insertion Sort works by dividing the array into a sorted and unsorted part. It picks each element
 * from the unsorted part and places it in the correct position in the sorted part.
 * 
 * Example Input:
 * arr = {64, 34, 25, 12, 22}
 * Output:
 * arr = {12, 22, 25, 34, 64}
 */

/*
 * Time Complexity:
 * - Best Case: O(n) when the array is already sorted.
 * - Worst Case: O(n^2) when the array is sorted in reverse order.
 * - Average Case: O(n^2) for random order of elements.
 * 
 * Space Complexity:
 * - O(1), as the sorting is done in place without extra memory.
 */

class Solution {
public:
    // Function to sort the array using Insertion Sort algorithm.
    void insertionSort(int arr[], int n) {
        
        for (int i = 1; i < n; i++) {  // Start with the second element
            int current = arr[i];     // Take the current element
            int j = i - 1;            // Compare with elements in the sorted part

            // Shift larger elements to the right
            while (j >= 0 && arr[j] > current) {
                arr[j + 1] = arr[j];
                j--;
            }

            // Insert the current element in its correct position
            arr[j + 1] = current;
        }
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    obj.insertionSort(arr, n);

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
 * Iteration 1 (i = 0):
 * - arr = {64, 34, 25, 12, 22} (No changes as the first element is already sorted)
 * 
 * Iteration 2 (i = 1):
 * - Compare 34 and 64 → Swap → arr = {34, 64, 25, 12, 22}
 * 
 * Iteration 3 (i = 2):
 * - Compare 25 and 64 → Swap → arr = {34, 25, 64, 12, 22}
 * - Compare 25 and 34 → Swap → arr = {25, 34, 64, 12, 22}
 * 
 * Iteration 4 (i = 3):
 * - Compare 12 and 64 → Swap → arr = {25, 34, 12, 64, 22}
 * - Compare 12 and 34 → Swap → arr = {25, 12, 34, 64, 22}
 * - Compare 12 and 25 → Swap → arr = {12, 25, 34, 64, 22}
 * 
 * Iteration 5 (i = 4):
 * - Compare 22 and 64 → Swap → arr = {12, 25, 34, 22, 64}
 * - Compare 22 and 34 → Swap → arr = {12, 25, 22, 34, 64}
 * - Compare 22 and 25 → Swap → arr = {12, 22, 25, 34, 64}
 * 
 * Final Output: arr = {12, 22, 25, 34, 64}
 */
