#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement:
 * Implement Bubble Sort using recursion to sort an array in ascending order.
 * 
 * Bubble Sort repeatedly compares adjacent elements and swaps them if they are 
 * in the wrong order. The largest element "bubbles up" to its correct position 
 * in each pass.
 * 
 * Key Points:
 * - Time Complexity: O(N^2) (for worst and average cases)
 * - Space Complexity: O(N) (due to recursion stack)
 */

void recursiveBubbleSort(int arr[], int n) {
    // Base Case: If the array has only one element, it is already sorted
    if (n == 1) {
        return;
    }

    // Perform one pass to move the largest element to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive Call: Sort the remaining array
    recursiveBubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    recursiveBubbleSort(arr, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Dry Run:
 * Input: arr = {64, 34, 25, 12, 22, 11, 90}
 * 
 * Step 1: Pass 1 (n=7)
 * - Compare and Swap: {34, 25, 12, 22, 11, 64, 90}
 * 
 * Step 2: Pass 2 (n=6)
 * - Compare and Swap: {25, 12, 22, 11, 34, 64, 90}
 * 
 * Step 3: Pass 3 (n=5)
 * - Compare and Swap: {12, 11, 22, 25, 34, 64, 90}
 * 
 * Step 4: Pass 4 (n=4)
 * - Compare and Swap: {11, 12, 22, 25, 34, 64, 90}
 * 
 * Output: arr = {11, 12, 22, 25, 34, 64, 90}
 * 
 * Time Complexity:
 * - Best Case: O(N^2) (due to recursion)
 * - Worst Case: O(N^2)
 * Space Complexity: O(N) for recursion stack.
 */
