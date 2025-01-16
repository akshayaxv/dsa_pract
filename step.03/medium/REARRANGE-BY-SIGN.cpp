#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Time Complexity: O(n) (for traversal) + O(n) (for creating separate arrays) = O(n)
// Space Complexity: O(n) (for storing separate positive and negative arrays)
class BruteForceSolution {
public:
    void rearrange(int arr[], int n) {
        // Step 1: Create separate vectors for positive and negative numbers
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }

        // Step 2: Merge positive and negative numbers alternatively
        int i = 0, j = 0, k = 0;
        while (i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }

        // Step 3: Add remaining elements
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }
        while (j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};

/* 
Dry Run: Brute Force Solution
Input: arr[] = {1, -2, 3, -4, 5, -6}, n = 6
Step 1: Separate positive and negative arrays
  pos = {1, 3, 5}, neg = {-2, -4, -6}

Step 2: Merge alternatively
  i = 0, j = 0, k = 0 → arr[0] = 1, arr[1] = -2
  i = 1, j = 1, k = 2 → arr[2] = 3, arr[3] = -4
  i = 2, j = 2, k = 4 → arr[4] = 5, arr[5] = -6

Final Output: {1, -2, 3, -4, 5, -6}
*/

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class OptimalSolution {
public:
    void rearrange(int arr[], int n) {
        int i = 0;  // Position to place the next positive/negative element

        // Step 1: Reorder positive and negative numbers in alternate positions
        for (int j = 0; j < n; j++) {
            if (arr[j] >= 0 && i % 2 == 0) {
                // If we need a positive number and it's already positive
                swap(arr[i++], arr[j]);
            } else if (arr[j] < 0 && i % 2 != 0) {
                // If we need a negative number and it's already negative
                swap(arr[i++], arr[j]);
            }
        }

        // Step 2: If the array isn't fully arranged, move remaining elements to their correct positions
        for (int j = i; j < n; j++) {
            if (arr[j] >= 0 && i % 2 == 0) {
                swap(arr[i++], arr[j]);
            } else if (arr[j] < 0 && i % 2 != 0) {
                swap(arr[i++], arr[j]);
            }
        }
    }
};

/* 
Dry Run: Optimal Solution
Input: arr[] = {1, -2, 3, -4, 5, -6}, n = 6

Step 1: Reorder array alternately
  i = 0, j = 0 → arr[0] is positive, swap with itself → arr = {1, -2, 3, -4, 5, -6}, i = 1
  i = 1, j = 1 → arr[1] is negative, swap with itself → arr = {1, -2, 3, -4, 5, -6}, i = 2
  i = 2, j = 2 → arr[2] is positive, swap with itself → arr = {1, -2, 3, -4, 5, -6}, i = 3
  i = 3, j = 3 → arr[3] is negative, swap with itself → arr = {1, -2, 3, -4, 5, -6}, i = 4

Step 2: Fully arranged → Final Output: {1, -2, 3, -4, 5, -6}
*/

// Driver Code
int main() {
    int arr[] = {1, -2, 3, -4, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Brute Force Solution
    BruteForceSolution bruteForce;
    int bruteArr[n];
    copy(arr, arr + n, bruteArr);
    bruteForce.rearrange(bruteArr, n);
    cout << "Brute Force Result: ";
    for (int x : bruteArr) {
        cout << x << " ";
    }
    cout << endl;

    // Optimal Solution
    OptimalSolution optimal;
    int optArr[n];
    copy(arr, arr + n, optArr);
    optimal.rearrange(optArr, n);
    cout << "Optimal Result: ";
    for (int x : optArr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
