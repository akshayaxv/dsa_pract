#include <bits/stdc++.h>
using namespace std;

// Problem: Merge two sorted arrays arr1 and arr2 of sizes n and m into one sorted array

// BRUTE FORCE APPROACH:
// In brute force, we can combine both arrays into one array, sort the whole array,
// and then divide it back into arr1 and arr2 based on the sizes.
// Time Complexity: O((n + m) log(n + m)) - Sorting the merged array
// Space Complexity: O(n + m) - Additional space for the merged array

class Solution {
public:
    void merge_bruteforce(long long arr1[], long long arr2[], int n, int m) {
        vector<long long> merged(n + m);  // To store the merged result

        // Copy the elements of arr1 and arr2 to merged
        for (int i = 0; i < n; i++) merged[i] = arr1[i];
        for (int i = 0; i < m; i++) merged[n + i] = arr2[i];

        // Sort the merged array
        sort(merged.begin(), merged.end());

        // Copy the sorted result back to arr1 and arr2
        for (int i = 0; i < n; i++) arr1[i] = merged[i];
        for (int i = 0; i < m; i++) arr2[i] = merged[n + i];
    }
};

/*
Dry Run for Brute Force:
Input: arr1 = [1, 4, 7], arr2 = [2, 3, 8]
Output: arr1 = [1, 2, 3], arr2 = [4, 7, 8]

- Merge both arrays into one: merged = [1, 4, 7, 2, 3, 8]
- Sort merged array: merged = [1, 2, 3, 4, 7, 8]
- Copy back to arr1 and arr2:
  arr1 = [1, 2, 3], arr2 = [4, 7, 8]
*/

/* -------------------------------------------------- */

// OPTIMIZED APPROACH:
// Since both arrays are already sorted, we can merge them in-place using two pointers.
// Time Complexity: O(n + m) - One pass over both arrays
// Space Complexity: O(1) - No extra space used, we are modifying the arrays in-place

class Solution {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int i = n - 1, j = 0;

        // Move the smaller elements from arr2 to arr1
        while (i >= 0 && j < m) {
            if (arr2[j] <= arr1[i]) {
                swap(arr2[j], arr1[i]);
                i--;
                j++;
            } else {
                break;  // No need to swap if arr2[j] > arr1[i]
            }
        }

        // After the swap, the elements in both arrays might not be sorted
        // So we need to sort the arrays again
        sort(arr1, arr1 + n);  // Sort arr1
        sort(arr2, arr2 + m);  // Sort arr2
    }
};

/*
Dry Run for Optimized Approach:
Input: arr1 = [1, 4, 7], arr2 = [2, 3, 8]
Output: arr1 = [1, 2, 3], arr2 = [4, 7, 8]

- Initialize pointers i = 2 (last index of arr1) and j = 0 (first index of arr2)
- Compare arr1[i] = 7 with arr2[j] = 2:
  - Since 7 > 2, swap arr1[2] with arr2[0], arr1 becomes [1, 4, 2] and arr2 becomes [7, 3, 8].
  - i decreases to 1 and j increases to 1.
- Compare arr1[i] = 4 with arr2[j] = 3:
  - Since 4 > 3, swap arr1[1] with arr2[1], arr1 becomes [1, 3, 2] and arr2 becomes [7, 4, 8].
  - i decreases to 0 and j increases to 2.
- Compare arr1[i] = 1 with arr2[j] = 7:
  - Since 1 < 7, no swap needed.
- Sort both arrays:
  - arr1 becomes [1, 2, 3] and arr2 becomes [4, 7, 8].
*/

int main() {
    long long arr1[] = {1, 4, 7};
    long long arr2[] = {2, 3, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    Solution sol;

    // Brute Force Solution
    sol.merge_bruteforce(arr1, arr2, n, m);
    cout << "Brute Force Result: arr1 = [";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << (i == n - 1 ? "" : ", ");
    }
    cout << "], arr2 = [";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << (i == m - 1 ? "" : ", ");
    }
    cout << "]\n";

    // Optimized Solution
    long long arr1_opt[] = {1, 4, 7};
    long long arr2_opt[] = {2, 3, 8};
    sol.merge(arr1_opt, arr2_opt, n, m);
    cout << "Optimized Result: arr1 = [";
    for (int i = 0; i < n; i++) {
        cout << arr1_opt[i] << (i == n - 1 ? "" : ", ");
    }
    cout << "], arr2 = [";
    for (int i = 0; i < m; i++) {
        cout << arr2_opt[i] << (i == m - 1 ? "" : ", ");
    }
    cout << "]\n";

    return 0;
}
