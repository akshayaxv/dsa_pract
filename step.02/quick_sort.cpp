#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement: Quick Sort
 * Quick Sort is a divide-and-conquer algorithm that works by selecting a 'pivot' element 
 * from the array and partitioning the other elements into two sub-arrays according to 
 * whether they are less than or greater than the pivot.
 * The sub-arrays are then sorted recursively.
 * 
 * Time Complexity:
 *   - Best Case: O(N * log(N)) [When the partition divides the array into two equal halves]
 *   - Worst Case: O(N^2) [When the partition divides the array into highly uneven parts]
 *   - Average Case: O(N * log(N))
 * Space Complexity: O(log(N)) [Recursive stack space]
 */

class Solution {
public:
    // Function to sort an array using the quick sort algorithm.
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot_index = partition(arr, low, high); // Partitioning the array around pivot
            quickSort(arr, low, pivot_index - 1);        // Recursively sort the left sub-array
            quickSort(arr, pivot_index + 1, high);      // Recursively sort the right sub-array
        }
    }

private:
    // Function to partition the array into two parts based on the pivot.
    int partition(int arr[], int low, int high) {
        int pivot = arr[low]; // Assuming the first element as the pivot
        int i = low, j = high;

        while (i < j) {
            // Find the first element greater than the pivot from the left
            while (arr[i] <= pivot && i < high) {
                i++;
            }

            // Find the first element smaller than the pivot from the right
            while (arr[j] > pivot && j > low) {
                j--;
            }

            // Swap elements to maintain the partitioning condition
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        // Place the pivot in its correct position
        swap(arr[low], arr[j]);
        return j; // Return the pivot index
    }
};

int main() {
    // Example to demonstrate quick sort
    Solution solution;
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    solution.quickSort(arr, 0, n - 1);

    // Printing the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
     * Dry Run for Quick Sort:
     * Input Array: {10, 7, 8, 9, 1, 5}
     * Step 1: Pivot = 10
     *   Partition: {5, 7, 8, 9, 1} + [10] + {}
     * Step 2: Pivot = 5
     *   Left Sub-array: {1}
     *   Right Sub-array: {7, 8, 9}
     * Step 3: Pivot = 7
     *   Left Sub-array: {}
     *   Right Sub-array: {8, 9}
     * Final Output: {1, 5, 7, 8, 9, 10}
     */

    return 0;
}
