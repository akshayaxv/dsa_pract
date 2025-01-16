#include <bits/stdc++.h>
using namespace std;

// Problem: https://leetcode.com/problems/merge-intervals/

// BRUTE FORCE APPROACH:
// In brute force, we could use nested loops to check for overlapping intervals
// and merge them manually. However, this is inefficient and not optimal.
// Time Complexity: O(n^2) - Two nested loops for checking overlaps
// Space Complexity: O(1) - No extra space used (apart from input/output)

class Solution {
public:
    vector<vector<int>> merge_bruteforce(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        // Iterate through each interval and check if it can be merged
        for (int i = 0; i < n; i++) {
            bool merged = false;
            // Check for overlaps with all intervals
            for (int j = 0; j < ans.size(); j++) {
                if (ans[j][1] >= intervals[i][0] && ans[j][0] <= intervals[i][1]) {
                    // Merge the intervals
                    ans[j][0] = min(ans[j][0], intervals[i][0]);
                    ans[j][1] = max(ans[j][1], intervals[i][1]);
                    merged = true;
                    break;
                }
            }
            // If no merge happened, add the interval to the result
            if (!merged) {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

/*
Dry Run for Brute Force:
Input: intervals = [[1, 3], [2, 4], [5, 7], [6, 8]]
Output: [[1, 4], [5, 8]]

- Start with empty result.
- Compare each interval with the result list:
  - First interval [1, 3] is added.
  - Second interval [2, 4] merges with [1, 3] -> [1, 4]
  - Third interval [5, 7] is added.
  - Fourth interval [6, 8] merges with [5, 7] -> [5, 8]
*/

/* -------------------------------------------------- */

// OPTIMIZED APPROACH:
// Sorting the intervals first and then merging them in a single pass.
// Time Complexity: O(n log n) - Sorting intervals
// Space Complexity: O(n) - Result array for merged intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Step 1: Sort the intervals based on their start times
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize result with the first interval
        vector<vector<int>> ans;
        vector<int> curr = intervals[0];

        // Step 3: Iterate over the sorted intervals and merge them if needed
        for (int i = 1; i < n; i++) {
            // If the current interval doesn't overlap with the next one
            if (curr[1] < intervals[i][0]) {
                ans.push_back(curr);
                curr = intervals[i];
            } else {
                // If there's an overlap, merge the intervals
                curr[0] = min(curr[0], intervals[i][0]);
                curr[1] = max(curr[1], intervals[i][1]);
            }
        }
        // Add the last interval to the result
        ans.push_back(curr);

        return ans;
    }
};

/*
Dry Run for Optimized Approach:
Input: intervals = [[1, 3], [2, 4], [5, 7], [6, 8]]
Output: [[1, 4], [5, 8]]

- First, sort the intervals: [[1, 3], [2, 4], [5, 7], [6, 8]]
- Initialize curr = [1, 3]
- Iterate over the sorted intervals:
  - Compare [1, 3] with [2, 4]: merge them -> curr = [1, 4]
  - Compare [1, 4] with [5, 7]: no overlap, push [1, 4] to result, set curr = [5, 7]
  - Compare [5, 7] with [6, 8]: merge them -> curr = [5, 8]
- Add [5, 8] to the result.

Final Result: [[1, 4], [5, 8]]
*/

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    
    Solution sol;

    // Brute Force Solution
    vector<vector<int>> result_bruteforce = sol.merge_bruteforce(intervals);
    cout << "Brute Force Result: ";
    for (auto& interval : result_bruteforce) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Optimized Solution
    vector<vector<int>> result = sol.merge(intervals);
    cout << "Optimized Result: ";
    for (auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
