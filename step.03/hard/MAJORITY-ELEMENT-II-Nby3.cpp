#include <bits/stdc++.h>
using namespace std;

/* 
Problem Statement:
- Given an integer array nums, return all elements that appear more than n/3 times.
- There can be at most two elements that occur more than n/3 times in the array.

Link: https://leetcode.com/problems/majority-element-ii/

[BRUTE FORCE] Approach:
- For each element in the array, count its occurrences using nested loops.
- Time Complexity: O(n^2)
- Space Complexity: O(n)
*/

// [BRUTE FORCE] -> For each element check if it occurs more than n/3 times using nested-loops.
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        // Time Complexity: O(n) -> Traversing the array to count frequencies
        for (auto it : nums) {
            mp[it]++;
        }

        // Time Complexity: O(n) -> Iterating over the map to check if the count is greater than n/3
        for (auto it : mp) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

/*
Dry Run for Brute Force Approach:
Input: nums = [3, 2, 3]

Step-by-Step Execution:
1. Count frequencies using the unordered map:
   - 3 occurs 2 times
   - 2 occurs 1 time

2. Iterate over the map and check if any element's count exceeds n/3:
   - For element 3: count = 2 > 3/3, so 3 is added to the result.
   - For element 2: count = 1 < 3/3, so 2 is not added.

Output: [3]
*/

// [OPTIMIZED] Approach: Using Moore's Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {

        int cnt1 = 0, cnt2 = 0, num1 = -1, num2 = -1;
        int n = nums.size();

        // Step 1: Apply Moore's Voting Algorithm for 2 potential majority elements
        // Time Complexity: O(n) -> We iterate over the array to find 2 potential candidates
        for (auto it : nums) {
            if (it == num1) {
                cnt1++;
            } else if (it == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = it;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = it;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify the candidates by counting their actual occurrences in the array
        // Time Complexity: O(n) -> We traverse the array again to count occurrences of the potential candidates
        cnt1 = 0, cnt2 = 0;
        for (auto it : nums) {
            if (it == num1) {
                cnt1++;
            } else if (it == num2) {
                cnt2++;
            }
        }

        // Step 3: Check if the candidates meet the majority condition
        // Time Complexity: O(1) -> Constant time checks for the final condition
        vector<int> result;
        if (cnt1 > n / 3) {
            result.push_back(num1);
        }
        if (cnt2 > n / 3) {
            result.push_back(num2);
        }

        return result.empty() ? vector<int> {-1} : result;
    }
};

/*
Dry Run for Optimized Approach:
Input: nums = [3, 2, 3]

Step-by-Step Execution:
1. First pass:
   - cnt1 = 0, cnt2 = 0, num1 = -1, num2 = -1
   - For 3: cnt1 = 1, num1 = 3
   - For 2: cnt2 = 1, num2 = 2
   - For 3: cnt1 = 2

2. Second pass:
   - Count occurrences of num1 (3) and num2 (2)
   - cnt1 = 2 for 3, cnt2 = 1 for 2

3. Compare cnt1 and cnt2 with n/3 (n = 3):
   - For 3: cnt1 = 2 > 3/3, so 3 is added to the result.
   - For 2: cnt2 = 1 < 3/3, so 2 is not added.

Output: [3]
*/

// Driver Code
int main() {
    vector<int> nums = {3, 2, 3};

    // Brute Force Solution
    Solution bruteForce;
    vector<int> result = bruteForce.majorityElement(nums);
    cout << "Brute Force Result: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Optimized Solution
    Solution optimized;
    result = optimized.majorityElement(nums);
    cout << "Optimized Result: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
