#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Brute Force Approach:
     * Time Complexity: O(N^2)
     * Space Complexity: O(1)
     * Explanation:
     * For each starting index `i`, iterate through the array until encountering a `0`.
     * Track the length of consecutive ones and update the maximum length.
     * Dry Run:
     * nums = [1, 1, 0, 1, 1, 1], n = 6
     * i = 0: subarray -> [1, 1], maxLen = 2
     * i = 1: subarray -> [1], maxLen = 2
     * i = 2: subarray -> [0], maxLen = 2
     * i = 3: subarray -> [1, 1, 1], maxLen = 3
     * i = 4: subarray -> [1, 1], maxLen = 3
     * i = 5: subarray -> [1], maxLen = 3
     */
    int maxConsecutiveOnesBruteForce(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 1) {
                    count++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, count);
        }

        return maxLen;
    }

    /*
     * Optimized Sliding Window Approach:
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * Explanation:
     * Use a single loop to traverse the array.
     * Maintain a counter `count` to track the length of the current streak of ones.
     * Reset the counter to zero whenever a zero is encountered.
     * Dry Run:
     * nums = [1, 1, 0, 1, 1, 1], n = 6
     * i = 0: nums[i] = 1 -> count = 1, maxLen = 1
     * i = 1: nums[i] = 1 -> count = 2, maxLen = 2
     * i = 2: nums[i] = 0 -> count = 0, maxLen = 2
     * i = 3: nums[i] = 1 -> count = 1, maxLen = 2
     * i = 4: nums[i] = 1 -> count = 2, maxLen = 2
     * i = 5: nums[i] = 1 -> count = 3, maxLen = 3
     */
    int maxConsecutiveOnesOptimized(vector<int>& nums) {
        int maxLen = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxLen = max(maxLen, count);
            } else {
                count = 0;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Input array
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    // Brute Force
    cout << "Maximum consecutive ones (Brute Force): "
         << sol.maxConsecutiveOnesBruteForce(nums) << endl;

    // Optimized
    cout << "Maximum consecutive ones (Optimized): "
         << sol.maxConsecutiveOnesOptimized(nums) << endl;

    return 0;
}
