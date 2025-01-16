#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-permutation/

// Approach #1: Brute Force
// Time Complexity: O(n! * n), where n! is for generating all permutations and n is for comparing.
// Space Complexity: O(n!) for storing permutations.

class BruteForceSolution {
public:
    void nextPermutation(vector<int> &nums) {
        // Step 1: Generate all permutations
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        do {
            permutations.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        // Step 2: Find the next permutation
        for (int i = 0; i < permutations.size(); i++) {
            if (permutations[i] == nums && i + 1 < permutations.size()) {
                nums = permutations[i + 1];
                return;
            }
        }

        // Step 3: If no next permutation, return the first (smallest) permutation
        nums = permutations[0];
    }
};

/* 
Dry Run: Brute Force Solution
Input: nums = {1, 2, 3}

Step 1: Generate all permutations
  Permutations = { {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1} }

Step 2: Find the next permutation
  Current permutation = {1, 2, 3}, Next permutation = {1, 3, 2}

Output: nums = {1, 3, 2}
*/

// Approach #2: Using STL `next_permutation`
// Time Complexity: O(n) for the internal implementation of `next_permutation`.
// Space Complexity: O(1).
class STLSolution {
public:
    void nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

/* 
Dry Run: STL Solution
Input: nums = {1, 2, 3}
Step: Use next_permutation(nums.begin(), nums.end())
Output: nums = {1, 3, 2}
*/

// Approach #3: Optimal Solution
// Time Complexity: O(n) for traversing and reversing.
// Space Complexity: O(1) since no extra space is used.
class OptimalSolution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size(), pt = -1;

        // Step 1: Find the breakpoint (first element smaller than the next from the right)
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pt = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse the entire array
        if (pt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest number greater than nums[pt] to the right of pt
        for (int i = n - 1; i > pt; --i) {
            if (nums[i] > nums[pt]) {
                swap(nums[i], nums[pt]);
                break;
            }
        }

        // Step 4: Reverse the portion of the array to the right of the breakpoint
        reverse(nums.begin() + pt + 1, nums.end());
    }
};

/* 
Dry Run: Optimal Solution
Input: nums = {1, 2, 3}

Step 1: Find breakpoint
  i = 1, nums[1] < nums[2] → pt = 1

Step 2: Find smallest number greater than nums[1] = 2
  nums[2] = 3 → Swap nums[1] and nums[2]
  nums = {1, 3, 2}

Step 3: Reverse the portion after pt = 1
  Reverse nums[2:] → nums = {1, 3, 2}

Output: nums = {1, 3, 2}
*/

// Driver Code
int main() {
    vector<int> nums = {1, 2, 3};

    // Brute Force Solution
    BruteForceSolution bruteForce;
    vector<int> bruteNums = nums;
    bruteForce.nextPermutation(bruteNums);
    cout << "Brute Force Result: ";
    for (int x : bruteNums) {
        cout << x << " ";
    }
    cout << endl;

    // STL Solution
    STLSolution stl;
    vector<int> stlNums = nums;
    stl.nextPermutation(stlNums);
    cout << "STL Result: ";
    for (int x : stlNums) {
        cout << x << " ";
    }
    cout << endl;

    // Optimal Solution
    OptimalSolution optimal;
    vector<int> optNums = nums;
    optimal.nextPermutation(optNums);
    cout << "Optimal Result: ";
    for (int x : optNums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
