#include <bits/stdc++.h>
using namespace std;

// Problem Statement:
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals k.

// Link: https://leetcode.com/problems/subarray-sum-equals-k/

// [Approach #1] Brute Force Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class BruteForceSolution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;

        // Check all subarrays
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

/*
Dry Run for Brute Force:
Input: nums = {1, 1, 1}, k = 2

Step-by-Step Execution:
1. Start with i = 0:
   - j = 0: sum = 1 (not equal to k)
   - j = 1: sum = 2 (equal to k → count = 1)
   - j = 2: sum = 3 (not equal to k)
2. Move to i = 1:
   - j = 1: sum = 1 (not equal to k)
   - j = 2: sum = 2 (equal to k → count = 2)
3. Move to i = 2:
   - j = 2: sum = 1 (not equal to k)

Output: 2
*/

// [Approach #2] Optimal Solution Using Prefix Sum and HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)

class OptimalSolution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        unordered_map<int, int> prefixMap; // Map to store prefix sums and their frequencies
        prefixMap[0] = 1; // Initialize with 0 to handle cases where prefixSum == k

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];

            // Check if there exists a prefixSum such that prefixSum - k exists in the map
            if (prefixMap.count(prefixSum - k)) {
                count += prefixMap[prefixSum - k];
            }

            // Update the map with the current prefixSum
            prefixMap[prefixSum]++;
        }

        return count;
    }
};

/*
Dry Run for Optimal Solution:
Input: nums = {1, 1, 1}, k = 2

Step-by-Step Execution:
1. Initialize: prefixSum = 0, count = 0, prefixMap = {0: 1}

2. Process nums[0] = 1:
   - prefixSum = 0 + 1 = 1
   - prefixSum - k = 1 - 2 = -1 (not in prefixMap)
   - Update prefixMap: {0: 1, 1: 1}

3. Process nums[1] = 1:
   - prefixSum = 1 + 1 = 2
   - prefixSum - k = 2 - 2 = 0 (exists in prefixMap with frequency 1)
   - count += 1 → count = 1
   - Update prefixMap: {0: 1, 1: 1, 2: 1}

4. Process nums[2] = 1:
   - prefixSum = 2 + 1 = 3
   - prefixSum - k = 3 - 2 = 1 (exists in prefixMap with frequency 1)
   - count += 1 → count = 2
   - Update prefixMap: {0: 1, 1: 1, 2: 1, 3: 1}

Output: 2
*/

// Driver Code
int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    // Brute Force Solution
    BruteForceSolution bruteForce;
    cout << "Brute Force Result: " << bruteForce.subarraySum(nums, k) << endl;

    // Optimal Solution
    OptimalSolution optimal;
    cout << "Optimal Result: " << optimal.subarraySum(nums, k) << endl;

    return 0;
}
