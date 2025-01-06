#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement:
 * Implement Insertion Sort using recursion to sort an array in ascending order.
 * 
 * Insertion Sort builds a sorted portion of the array by inserting elements one at a time
 * into their correct positions relative to the sorted portion.
 * 
 * Key Points:
 * - Time Complexity: O(N^2) (for worst and average cases)
 * - Space Complexity: O(N) (due to recursion stack)
 */

void recursiveInsertionSort(int arr[], int n) {
    // Base Case: If the array has one or no element, it is already sorted
    if (n <= 1) {
        return;
    }

    // Recursive Call: Sort the first (n-1) elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the nth element into its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements of the sorted portion to make space for the nth element
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    recursiveInsertionSort(arr, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Dry Run:
 * Input: arr = {12, 11, 13, 5, 6}
 * 
 * Step 1: Base Case Reached
 * - Sorted Portion: {12}
 * 
 * Step 2: Insert 11
 * - Shift and Insert: {11, 12}
 * 
 * Step 3: Insert 13
 * - No Shifting: {11, 12, 13}
 * 
 * Step 4: Insert 5
 * - Shift and Insert: {5, 11, 12, 13}
 * 
 * Step 5: Insert 6
 * - Shift and Insert: {5, 6, 11, 12, 13}
 * 
 * Output: arr = {5, 6, 11, 12, 13}
 * 
 * Time Complexity:
 * - Best Case: O(N^2) (due to recursion)
 * - Worst Case: O(N^2)
 * Space Complexity: O(N) for recursion stack.
 */
