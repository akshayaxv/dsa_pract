#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/number-of-inversions_6840276?utm_

/* 
Approach: 
Inversion count is a measure of how far an array is from being sorted.
An inversion is a pair of elements (arr[i], arr[j]) such that i < j and arr[i] > arr[j].

We can use a merge sort-based approach to count inversions efficiently while sorting the array.

Explanation: 
1. During the merge step of merge sort, whenever we find that arr[i] > arr[j], it means all the remaining elements from arr[i] to mid will be greater than arr[j], hence contributing inversions.
2. We recursively divide the array and count inversions during merging.

Here is the implementation using merge sort to count inversions:

*/

int cnt = 0; // global variable to store inversion count

// Merge function to count inversions and merge two sorted halves
void merge(vector<int>&a, int l, int mid, int r) {
    int i = l, j = mid + 1;
    while (i <= mid and j <= r) {
        if (a[i] > a[j]) {
            cnt += (mid - i + 1); // all elements from i to mid are greater than a[j]
            j++;
        } else {
            i++;
        }
    }

    // Merge the two sorted halves
    i = l, j = mid + 1;
    vector<int> temp;
    while (i <= mid and j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= r) {
        temp.push_back(a[j]);
        j++;
    }

    // Copy the sorted elements back to the original array
    for (int i = l; i <= r; i++) {
        a[i] = temp[i - l];
    }
}

// Divide the array and recursively count inversions
void divide(vector<int>&a, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    divide(a, l, mid);
    divide(a, mid + 1, r);
    merge(a, l, mid, r);
}

// Function to return the number of inversions
int numberOfInversions(vector<int> &a, int n) {
    divide(a, 0, n - 1);
    return cnt;
}

/*
Dry Run for Merge Sort Approach:
Input: arr = [4, 3, 2, 1]
    - Initially the array is [4, 3, 2, 1]
    - Divide step:
      - Left part: [4, 3] → merge → [3, 4]
      - Right part: [2, 1] → merge → [1, 2]
    - Now merge the two halves [3, 4] and [1, 2]
    - During merging, the following inversions are counted:
      - (4, 1) → contributes 2 inversions (since 4 > 1, and 4, 3 are also greater)
    - Total inversions = 6

Output: 6
*/

// Optimal solution using merge sort with inversion counting:

class Solution {
public:
    long long cnt = 0;

    // Merge function for counting inversions
    void merge(long long arr[], long long low, long long mid, long long high) {
        long long i = low, j = mid + 1;
        vector<long long> temp;

        // Count inversions during merging
        while (i <= mid and j <= high) {
            if (arr[i] > arr[j]) {
                cnt += (mid - i + 1); // All elements from i to mid are greater than arr[j]
                temp.push_back(arr[j]);
                j++;
            } else {
                temp.push_back(arr[i]);
                i++;
            }
        }

        // Merge the two halves
        while (i <= mid) { temp.push_back(arr[i++]); }
        while (j <= high) { temp.push_back(arr[j++]); }

        // Copy the sorted elements back to the original array
        for (long long k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    // Divide and count inversions recursively
    void divide(long long arr[], long long n, long long l, long long r) {
        if (l >= r) return; // When only one element is left
        long long mid = l + (r - l) / 2;
        divide(arr, n, l, mid);
        divide(arr, n, mid + 1, r);
        merge(arr, l, mid, r);
    }

    // Function to count inversions
    long long int inversionCount(long long arr[], long long N) {
        divide(arr, N, 0, N - 1);
        return cnt;
    }
};

/*
Dry Run for Optimized Approach:
Input: arr = [4, 3, 2, 1]
    - Initially the array is [4, 3, 2, 1]
    - Divide step:
      - Left part: [4, 3] → merge → [3, 4]
      - Right part: [2, 1] → merge → [1, 2]
    - Now merge the two halves [3, 4] and [1, 2]
    - During merging, the following inversions are counted:
      - (4, 1) → contributes 2 inversions (since 4 > 1, and 4, 3 are also greater)
    - Total inversions = 6

Output: 6
*/

int main() {
    vector<int> arr1 = {4, 3, 2, 1};
    int n = arr1.size();
    
    // Brute Force Solution
    int result = numberOfInversions(arr1, n);
    cout << "Inversion Count (Merge Sort Approach): " << result << endl;

    // Optimized Solution (GFG Version)
    long long arr2[] = {4, 3, 2, 1};
    long long N = sizeof(arr2) / sizeof(arr2[0]);
    Solution sol;
    long long ans = sol.inversionCount(arr2, N);
    cout << "Inversion Count (GFG Version): " << ans << endl;

    return 0;
}
