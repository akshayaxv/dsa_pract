#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement: Merge Sort
 * Merge Sort is a divide-and-conquer sorting algorithm.
 * It divides an array into halves, recursively sorts them, 
 * and then merges the sorted halves.
 * 
 * Time Complexity: O(N * log(N))
 * Space Complexity: O(N)
 * 
 * Problem Statement: Merge Two Sorted Arrays Without Extra Space
 * Given two sorted arrays, merge them in such a way that
 * the resultant arrays remain sorted and no extra space is used.
 * 
 * Time Complexity: O(N + M) for comparison + O(N * log(N) + M * log(M)) for sorting.
 * Space Complexity: O(1) (In-place merging).
 */

class MergeSortSolution {
public:
    // Function to merge two sorted halves of an array.
    void merge(int arr[], int l, int m, int r) {
        vector<int> temp; // Temporary vector to store merged elements.
        int left = l, right = m + 1;

        // Merge elements into temp in sorted order.
        while (left <= m && right <= r) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        // Add remaining elements from the left half (if any).
        while (left <= m) {
            temp.push_back(arr[left++]);
        }

        // Add remaining elements from the right half (if any).
        while (right <= r) {
            temp.push_back(arr[right++]);
        }

        // Copy the sorted elements back into the original array.
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    // Recursive function to implement merge sort.
    void mergeSort(int arr[], int l, int r) {
        if (l >= r) return; // Base case: single element is always sorted.

        int mid = l + (r - l) / 2; // Find the middle point.
        mergeSort(arr, l, mid);    // Recursively sort the left half.
        mergeSort(arr, mid + 1, r); // Recursively sort the right half.
        merge(arr, l, mid, r);     // Merge the two halves.
    }
};

class MergeTwoArraysSolution {
public:
    // Function to merge two sorted arrays without extra space.
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int i = n - 1, j = 0;

        // Compare the largest element of arr1 with the smallest of arr2.
        while (i >= 0 && j < m) {
            if (arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            } else {
                break;
            }
        }

        // Sort both arrays to maintain sorted order.
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main() {
    // Example for Merge Sort
    MergeSortSolution ms;
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    ms.mergeSort(arr, 0, n - 1);

    cout << "Sorted Array using Merge Sort: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    /*
     * Dry Run for Merge Sort:
     * Input Array: {12, 11, 13, 5, 6}
     * Step 1: Divide -> {12, 11, 13} and {5, 6}
     * Step 2: Recursively divide -> {12}, {11, 13}, {5}, {6}
     * Step 3: Merge -> {11, 12, 13} and {5, 6}
     * Step 4: Merge final halves -> {5, 6, 11, 12, 13}
     * Output: {5, 6, 11, 12, 13}
     */

    // Example for Merging Two Sorted Arrays Without Extra Space
    MergeTwoArraysSolution mtas;
    long long arr1[] = {10, 12, 15};
    long long arr2[] = {5, 8, 20};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    mtas.merge(arr1, arr2, size1, size2);

    cout << "Merged Arrays Without Extra Space:\nArray 1: ";
    for (int i = 0; i < size1; i++) cout << arr1[i] << " ";
    cout << "\nArray 2: ";
    for (int i = 0; i < size2; i++) cout << arr2[i] << " ";
    cout << endl;

    /*
     * Dry Run for Merge Two Sorted Arrays:
     * Input:
     * arr1 = {10, 12, 15}, arr2 = {5, 8, 20}
     * Step 1: Compare and swap largest of arr1 with smallest of arr2.
     * arr1 = {10, 8, 15}, arr2 = {5, 12, 20}
     * Step 2: Sort both arrays.
     * arr1 = {8, 10, 15}, arr2 = {5, 12, 20}
     * Output:
     * arr1 = {8, 10, 15}, arr2 = {5, 12, 20}
     */

    return 0;
}
