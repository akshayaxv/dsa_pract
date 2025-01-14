#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Consecutive Ones with At Most K Zeros
// Brute Force + Optimized Approach Included

class Solution {
public:
    /*
     * Brute Force Approach:
     * Time Complexity: O(N^2)
     * Space Complexity: O(1)
     * Explanation:
     * For each starting index `i`, expand the subarray by moving `j` to the right.
     * Count the number of zeros in the current subarray. If it exceeds `k`, stop and update the result.
     */

    int longestOnesBruteForce(vector<int> &nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int zeroCount = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zeroCount++;
                }

                // If zero count exceeds `k`, break.
                if (zeroCount > k) {
                    break;
                }

                // Update max length
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }

    /*
     * Optimized Approach:
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * Explanation:
     * Use a sliding window approach with two pointers `i` and `j`.
     * Expand the window by moving `j` and count the zeros.
     * If the count of zeros exceeds `k`, shrink the window from the left by moving `i`.
     */

    int longestOnesOptimized(vector<int> &nums, int k) {
        int i = 0, j = 0, count = 0, ans = 0;
        int n = nums.size();

        while (j < n) {
            if (nums[j] == 0) {
                count++;
            }

            if (count <= k) {
                j++;
            } else {
                ans = max(ans, j - i);

                if (nums[i] == 0) {
                    count--;
                }

                i++;
                j++;
            }
        }

        ans = max(ans, j - i); // Handle the last window
        return ans;
    }
};

/*
 * Dry Run Example:
 * Input: nums = [1, 1, 0, 0, 1, 1, 0, 1, 1], k = 2
 *
 * Brute Force:
 * - Start i = 0
 *   - j = 0: nums[j] = 1, count = 0, maxLen = 1
 *   - j = 1: nums[j] = 1, count = 0, maxLen = 2
 *   - j = 2: nums[j] = 0, count = 1, maxLen = 3
 *   - j = 3: nums[j] = 0, count = 2, maxLen = 4
 *   - j = 4: nums[j] = 1, count = 2, maxLen = 5
 *   - j = 6: nums[j] = 0, count = 3 > k, stop and move to i = 1
 * Repeat for each i.
 *
 * Optimized:
 * - Initialize i = 0, j = 0, count = 0, ans = 0
 * - Expand j:
 *   - j = 0: nums[j] = 1, count = 0, ans = 0
 *   - j = 3: nums[j] = 0, count = 2, ans = 0
 * - Exceeds k, shrink from i = 0.
 * Final ans = 6
 */

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 0, 1, 1};
    int k = 2; // Maximum zeros allowed

    cout << "Longest subarray with at most " << k << " zeros (Brute Force): "
         << sol.longestOnesBruteForce(nums, k) << endl;

    cout << "Longest subarray with at most " << k << " zeros (Optimized): "
         << sol.longestOnesOptimized(nums, k) << endl;

    return 0;
}
