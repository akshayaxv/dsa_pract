#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Longest Subarray of Consecutive 1s After Flipping Any Number of Zeros
// Includes both Brute Force and Optimized Approaches

class Solution {
public:
    /*
     * Brute Force Approach:
     * Time Complexity: O(N^2)
     * Space Complexity: O(1)
     * Explanation:
     * For each starting index `i`, expand the subarray by moving `j` to the right.
     * Track the length of the subarray and update the maximum length.
     * Dry Run Example:
     * nums = [1, 1, 0, 0, 1], n = 5
     * i = 0: subarrays -> [1], [1, 1], [1, 1, 0], [1, 1, 0, 0], [1, 1, 0, 0, 1] -> maxLen = 5
     * i = 1: subarrays -> [1], [1, 0], [1, 0, 0], [1, 0, 0, 1] -> maxLen = 5
     * i = 2: subarrays -> [0], [0, 0], [0, 0, 1] -> maxLen = 5
     * i = 3: subarrays -> [0], [0, 1] -> maxLen = 5
     * i = 4: subarrays -> [1] -> maxLen = 5
     */
    int longestOnesBruteForce(vector<int> &nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }

    /*
     * Optimized Sliding Window Approach:
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * Explanation:
     * Use a sliding window approach to traverse the array.
     * Expand the window by moving `j`. Maintain the length of the current window and update the maximum length.
     * Dry Run Example:
     * nums = [1, 1, 0, 0, 1], n = 5
     * Step-by-step:
     * i = 0, j = 0, maxLen = 0
     * - nums[j] = 1 -> Expand window -> maxLen = 1
     * i = 0, j = 1, maxLen = 1
     * - nums[j] = 1 -> Expand window -> maxLen = 2
     * i = 0, j = 2, maxLen = 2
     * - nums[j] = 0 -> Expand window -> maxLen = 3
     * i = 0, j = 3, maxLen = 3
     * - nums[j] = 0 -> Expand window -> maxLen = 4
     * i = 0, j = 4, maxLen = 4
     * - nums[j] = 1 -> Expand window -> maxLen = 5
     */
    int longestOnesOptimized(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0, maxLen = 0;

        while (j < n) {
            // Expand the window
            j++;

            // Update maximum length
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Input array
    vector<int> nums = {1, 1, 0, 0, 1};

    cout << "Longest subarray with all ones (Brute Force): "
         << sol.longestOnesBruteForce(nums) << endl;

    cout << "Longest subarray with all ones (Optimized): "
         << sol.longestOnesOptimized(nums) << endl;

    return 0;
}
