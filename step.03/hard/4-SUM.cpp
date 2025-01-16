#include <bits/stdc++.h>
using namespace std;

// Problem: https://leetcode.com/problems/4sum/

// BRUTE FORCE -> Use four nested loops to check all possible quadruples and store the ones giving target sum.
// Time Complexity: O(n^4) - four nested loops
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Brute Force approach using four nested loops
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());  // Sort to handle duplicates
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }

        // Removing duplicate quadruples by sorting and using set
        set<vector<int>> st(ans.begin(), ans.end());
        ans.assign(st.begin(), st.end());  // Convert set back to vector

        return ans;
    }
};

/*
Dry Run for Brute Force Approach:
Input: nums = [1, 0, -1, 0, -2, 2], target = 0

1. Iterate through each quadruple (i, j, k, l) and check if their sum equals target:
   - First loop: i = 0 (nums[i] = 1)
   - Second loop: j = 1 (nums[j] = 0)
   - Third loop: k = 2 (nums[k] = -1)
   - Fourth loop: l = 3 (nums[l] = 0)

   Check if 1 + 0 + (-1) + 0 == 0 → Triplet found: [1, 0, -1, 0]
   Continue this for all combinations.
Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
*/

// OPTIMIZED APPROACH USING HASHSET AND TWO POINTERS
// Time Complexity: O(n^3) - Two pointers and one iteration
// Space Complexity: O(n) - For storing the set of quadruples
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st; // To store unique quadruples
        
        // Sorting the array to handle duplicates and apply two pointer technique
        sort(nums.begin(), nums.end());

        // Iterate through all elements as the first element
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Iterate for the second element
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int low = j + 1, high = n - 1;

                // Use two-pointer approach for the remaining two elements
                while (low < high) {
                    long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];
                    
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        // Skip duplicates for the third and fourth elements
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;

                        low++, high--;
                    }
                    else if (sum < target) {
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }

        return ans;
    }
};

/*
Dry Run for Optimized Approach:
Input: nums = [1, 0, -1, 0, -2, 2], target = 0

1. Sort the array: [-2, -1, 0, 0, 1, 2]
2. Iterate through the array for the first two elements (i, j):
   - First loop: i = 0 (nums[i] = -2)
   - Second loop: j = 1 (nums[j] = -1)
   
   Apply two-pointer technique with low = 2 (nums[low] = 0) and high = 5 (nums[high] = 2):
   - Check sum = -2 + (-1) + 0 + 2 = -1 → Move the low pointer.
   
   Continue this for all pairs (i, j) and update the low and high pointers accordingly.
   
Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
*/

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // Brute Force Solution
    Solution bruteForce;
    vector<vector<int>> result = bruteForce.fourSum(nums, target);
    cout << "Brute Force Result: ";
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Optimized Solution
    Solution optimized;
    result = optimized.fourSum(nums, target);
    cout << "Optimized Result: ";
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
