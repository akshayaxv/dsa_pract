#include <bits/stdc++.h>
using namespace std;

// Problem: https://leetcode.com/problems/3sum/

// BRUTE FORCE -> Take three nested loops and try out all possible triplets and store the ones giving zero on summation and are unique.
// Time Complexity: O(n^3)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;
        
        // Brute Force: Using three nested loops
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> vec = {nums[i], nums[j], nums[k]}; 
                        sort(vec.begin(), vec.end());  // Sort the triplet to ensure uniqueness
                        if(!st.count(vec)) {
                            st.insert(vec);  // Store unique triplets
                            ans.push_back(vec);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/*
Dry Run for Brute Force Approach:
Input: nums = [-1, 0, 1, 2, -1, -4]

1. Iterating over all triplets:
   - First loop starts with i = 0 (nums[i] = -1).
   - Second loop starts with j = 1 (nums[j] = 0).
   - Third loop starts with k = 2 (nums[k] = 1).

   Check: -1 + 0 + 1 = 0 → Triplet found: [-1, 0, 1]
   Sort it to [-1, 0, 1] and store it if not present in set.

   Continue this process for all combinations, and store unique triplets.

Output: [ [-1, -1, 2], [-1, 0, 1] ]
*/

// OPTIMIZED APPROACH
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        set<vector<int>> st;
        
        // Using HashSet to store unique pairs
        for(int i = 0; i < n; i++) {
            unordered_set<int> pk;
            for(int j = i + 1; j < n; j++) {
                int req = -(nums[i] + nums[j]);
                if(pk.count(req)) {
                    vector<int> temp = {nums[i], nums[j], req};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);  // Insert the triplet into the set to ensure uniqueness
                }
                pk.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

/*
Dry Run for Optimized Approach:
Input: nums = [-1, 0, 1, 2, -1, -4]

1. First loop starts with i = 0 (nums[i] = -1).
2. Initialize unordered set pk to store numbers we have already seen.
3. Second loop starts with j = 1 (nums[j] = 0).
   - req = -(nums[i] + nums[j]) = 1
   - pk.insert(nums[j]) adds 0 to pk.

   Repeat for each pair and check if the third number exists in pk. If it does, we found a triplet.

Output: [ [-1, -1, 2], [-1, 0, 1] ]
*/

// MOST EFFICIENT APPROACH
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array first to handle duplicates more efficiently
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {
            // Skip duplicate elements to avoid repeating the same triplet
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1, high = n - 1, req = -(nums[i]);

                while(low < high) {
                    if(nums[low] + nums[high] == req) {
                        ans.push_back({nums[i], nums[low], nums[high]});
                        
                        // Skip duplicates for the second number (nums[low]) and third number (nums[high])
                        while(low < high && nums[low] == nums[low + 1]) low++;
                        while(low < high && nums[high] == nums[high - 1]) high--;
                        
                        // Move the pointers
                        low++, high--;
                    }
                    else if(nums[low] + nums[high] < req) {
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
Dry Run for Most Efficient Approach:
Input: nums = [-1, 0, 1, 2, -1, -4]

1. Sort the array: [-4, -1, -1, 0, 1, 2]
2. Iterate through the array:
   - First loop: i = 0 (nums[i] = -4).
   - Second loop: low = 1 (nums[low] = -1), high = 5 (nums[high] = 2).
   - Check sum: -4 + (-1) + 2 = -3. So, move the pointer `low`.
   
   Continue the process for each i and update low and high pointers.
   
Output: [ [-1, -1, 2], [-1, 0, 1] ]
*/

int main() {
    vector<int> nums = [-1, 0, 1, 2, -1, -4];

    // Brute Force Solution
    Solution bruteForce;
    vector<vector<int>> result = bruteForce.threeSum(nums);
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
    result = optimized.threeSum(nums);
    cout << "Optimized Result: ";
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Efficient Solution
    Solution efficient;
    result = efficient.threeSum(nums);
    cout << "Efficient Result: ";
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
