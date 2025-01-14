#include <bits/stdc++.h>
using namespace std;

// Approach #1: Brute Force (Nested Loop)
// Time Complexity: O(n^2), where n is the number of elements in the array
// Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSumBruteForce(vector<int>& nums, int x) {
        int n = nums.size();

        // Dry Run Example:
        // Input: nums = {2, 7, 11, 15}, x = 9
        // Expected Output: [0, 1] (nums[0] + nums[1] = 2 + 7 = 9)
        
        // Step 1: Traverse the array using two nested loops
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Step 2: Check if nums[i] + nums[j] equals the target x
                // In first iteration, nums[0] + nums[1] = 2 + 7 = 9 == 9, so return indices
                if (nums[i] + nums[j] == x) {
                    // Return the pair of indices
                    return {i, j};  
                }
            }
        }
        // If no pair is found, return an empty vector
        return {};
    }
};

// Approach #2: Optimal Approach (Using Hash Map)
// Time Complexity: O(n), where n is the number of elements in the array
// Space Complexity: O(n) for the unordered_map
class Solution {
public:
    vector<int> twoSumOptimal(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;  // Store number and its index

        // Dry Run Example:
        // Input: nums = {2, 7, 11, 15}, x = 9
        // Expected Output: [0, 1] (nums[0] + nums[1] = 2 + 7 = 9)

        // Step 1: Traverse the array and check if (x - nums[i]) exists in the map
        for (int i = 0; i < n; i++) {
            // Checking each step of the dry run:
            // For nums = {2, 7, 11, 15} and x = 9, we need to find a pair that sums to 9

            // i = 0, nums[i] = 2
            // We check if 9 - 2 = 7 exists in the map, but the map is empty at this point.
            // So, we store 2 in the map: mp = {2: 0}
            mp[nums[i]] = i;

            // i = 1, nums[i] = 7
            // We check if 9 - 7 = 2 exists in the map. It does, and mp[2] = 0.
            // Therefore, we return the indices {0, 1}, because nums[0] + nums[1] = 9.

            if (mp.find(x - nums[i]) != mp.end()) {
                // Return indices of the pair (0, 1) when nums[0] + nums[1] = 2 + 7 = 9
                return {mp[x - nums[i]], i};  
            }

            // If no pair found, store the current number and its index in the map
            mp[nums[i]] = i;
        }
        // If no pair is found, return an empty vector
        return {};
    }
};

// Driver code to test both approaches
int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int x = 9;

    // Testing brute force approach
    vector<int> result = s.twoSumBruteForce(nums, x);
    if (!result.empty()) {
        cout << "Brute Force Approach - Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "Brute Force Approach - No pair found." << endl;
    }

    // Testing optimal approach (hash map)
    result = s.twoSumOptimal(nums, x);
    if (!result.empty()) {
        cout << "Optimal Approach - Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "Optimal Approach - No pair found." << endl;
    }

    return 0;
}
