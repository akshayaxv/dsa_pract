#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class BruteForceSolution {
public:
    vector<int> findSubarray(int a[], int n) {
        int maxi = INT_MIN; // Store the maximum sum
        int ansStart = -1, ansEnd = -1; // Indices of the subarray
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j]; // Calculate sum of subarray a[i..j]
                if (sum > maxi || (sum == maxi && (j - i > ansEnd - ansStart))) {
                    // Update if sum is greater or same with larger subarray
                    maxi = sum;
                    ansStart = i;
                    ansEnd = j;
                }
            }
        }
        
        vector<int> ans;
        if (maxi < 0) return {-1}; // Return {-1} if no valid subarray found
        for (int i = ansStart; i <= ansEnd; i++) ans.push_back(a[i]);
        return ans;
    }
};

/* 
Dry Run: Brute Force Solution
Input: a[] = {1, 2, 5, -7, 2, 3}, n = 6

Step 1: Start with i = 0, sum = 0
  - j = 0 → sum = 1, maxi = 1, ansStart = 0, ansEnd = 0
  - j = 1 → sum = 3, maxi = 3, ansStart = 0, ansEnd = 1
  - j = 2 → sum = 8, maxi = 8, ansStart = 0, ansEnd = 2
  - j = 3 → sum = 1, no update
  - j = 4 → sum = 3, no update
  - j = 5 → sum = 6, no update

Step 2: Continue for i = 1, i = 2, ..., updating maxi and indices as needed.
Final Subarray: [1, 2, 5] with maxi = 8.
*/

// Optimal Solution: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
class OptimalSolution {
public:
    vector<int> findSubarray(int a[], int n) {
        int maxi = INT_MIN, sum = 0;
        int ansStart = -1, ansEnd = -1, start = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                sum = 0; // Reset the sum on negative elements
                continue;
            }
            if (sum == 0) start = i; // Start a new subarray
            
            sum += a[i];
            if (sum > maxi || (sum == maxi && (i - start > ansEnd - ansStart))) {
                // Update if sum is greater or same with larger subarray
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
        }
        
        vector<int> ans;
        if (ansStart == -1) return {-1}; // Return {-1} if no valid subarray found
        for (int i = ansStart; i <= ansEnd; i++) ans.push_back(a[i]);
        return ans;
    }
};

/*
Dry Run: Optimal Solution (Kadane's Algorithm)
Input: a[] = {1, 2, 5, -7, 2, 3}, n = 6

Step 1: Initialize maxi = INT_MIN, sum = 0, ansStart = -1, ansEnd = -1, start = 0

Step 2: Iterate through the array
  - i = 0 → sum = 1, maxi = 1, ansStart = 0, ansEnd = 0
  - i = 1 → sum = 3, maxi = 3, ansStart = 0, ansEnd = 1
  - i = 2 → sum = 8, maxi = 8, ansStart = 0, ansEnd = 2
  - i = 3 → Negative element resets sum to 0
  - i = 4 → sum = 2, no update
  - i = 5 → sum = 5, no update

Step 3: Final Subarray: [1, 2, 5] with maxi = 8.
*/

// Driver Code
int main() {
    int arr[] = {1, 2, 5, -7, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Brute Force Solution
    BruteForceSolution brute;
    vector<int> bruteResult = brute.findSubarray(arr, n);
    cout << "Brute Force Result: ";
    for (int x : bruteResult) cout << x << " ";
    cout << endl;
    
    // Optimal Solution
    OptimalSolution optimal;
    vector<int> optimalResult = optimal.findSubarray(arr, n);
    cout << "Optimal Result: ";
    for (int x : optimalResult) cout << x << " ";
    cout << endl;
    
    return 0;
}
