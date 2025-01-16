#include <bits/stdc++.h>
using namespace std;

// Problem: https://practice.geeksforgeeks.org/problems/find-the-largest-subarray-with-zero-sum/1

// BRUTE FORCE -> Check all possible subarrays and compute their sums to find the maximum length subarray with zero sum.
// Time Complexity: O(n^2) - Two nested loops to check all subarrays
// Space Complexity: O(1) - No extra space used for storing intermediate results.
class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        int ans = 0;

        // Brute Force approach: Check each subarray and calculate sum
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += A[j];
                if (sum == 0) {
                    ans = max(ans, j - i + 1);  // Update the answer if we find a larger subarray
                }
            }
        }

        return ans;
    }
};

/*
Dry Run for Brute Force Approach:
Input: A = {1, -1, 3, -2, 2, -3}, n = 6

- Start with i = 0, sum = 0
  - j = 0: sum = 1
  - j = 1: sum = 0, ans = 2 (subarray [1, -1])
  - j = 2: sum = 3
  - j = 3: sum = 1
  - j = 4: sum = 3
  - j = 5: sum = 0, ans = 6 (subarray [1, -1, 3, -2, 2, -3])

Final Answer: 6 (maximum subarray length with zero sum)
*/

// OPTIMIZED APPROACH -> Using prefix sum and hashing (unordered_map) to track previously encountered sums
// Time Complexity: O(n) - We traverse the array once
// Space Complexity: O(n) - We store sums in the hash map
class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> mp;  // Map to store the first occurrence of a prefix sum
        int sum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i];

            // If sum is zero, we found a subarray from index 0 to i
            if (sum == 0) {
                ans = i + 1;
            }
            // If this sum has been encountered before, it means we have found a subarray with zero sum
            else if (mp.count(sum)) {
                ans = max(ans, i - mp[sum]);  // Update the answer with the length of the subarray
            }
            // Store the first occurrence of this sum
            else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};

/*
Dry Run for Optimized Approach:
Input: A = {1, -1, 3, -2, 2, -3}, n = 6

- i = 0, sum = 1, map = {}
- i = 1, sum = 0, ans = 2 (first subarray [1, -1])
- i = 2, sum = 3, map = {0: 1}
- i = 3, sum = 1, map = {0: 1, 3: 2}
- i = 4, sum = 3, map = {0: 1, 3: 2}
- i = 5, sum = 0, ans = 6 (subarray [1, -1, 3, -2, 2, -3])

Final Answer: 6
*/

int main() {
    vector<int> A = {1, -1, 3, -2, 2, -3};
    int n = A.size();

    // Brute Force Solution
    Solution bruteForce;
    int result = bruteForce.maxLen(A, n);
    cout << "Brute Force Result: " << result << endl;  // Expected output: 6

    // Optimized Solution
    Solution optimized;
    result = optimized.maxLen(A, n);
    cout << "Optimized Result: " << result << endl;  // Expected output: 6

    return 0;
}
