#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class BruteForceSolution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Dry Run Example:
        // Input: nums = [3, 1, 3, 3, 2]
        // Expected Output: 3 (appears 3 times, n/2 = 5/2 = 2)

        for (int i = 0; i < n; i++) {
            int count = 0;

            // Count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            // Dry Run Step:
            // nums[0] = 3 -> Count = 3 (Valid: Count > n/2)
            // nums[1] = 1 -> Count = 1 (Invalid: Count <= n/2)
            // nums[2] = 3 -> Count = 3 (Valid: Count > n/2)
            // nums[3] = 3 -> Count = 3 (Valid: Count > n/2)
            // nums[4] = 2 -> Count = 1 (Invalid: Count <= n/2)

            // If count > n/2, nums[i] is the majority element
            if (count > n / 2) {
                return nums[i];
            }
        }

        // No majority element found
        return -1;
    }
};

// Optimal Solution: Moore's Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
class OptimalSolution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, candidate;

        // Phase 1: Find the potential majority element
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }

            // Dry Run for Phase 1:
            // Input: nums = [3, 1, 3, 3, 2]
            // Step 1: num = 3, count = 1, candidate = 3
            // Step 2: num = 1, count = 0
            // Step 3: num = 3, count = 1, candidate = 3
            // Step 4: num = 3, count = 2
            // Step 5: num = 2, count = 1
        }

        // Candidate after Phase 1: 3

        // Phase 2: Verify if the candidate is a majority element
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        // Dry Run for Phase 2:
        // Candidate = 3
        // Count occurrences of 3: Count = 3
        // Majority check: Count > n/2 (3 > 2) -> Valid

        // Return the candidate if it is indeed a majority element
        if (count > n / 2) {
            return candidate;
        }

        // No majority element found
        return -1;
    }
};

// Driver Code
int main() {
    // Test Case
    vector<int> nums = {3, 1, 3, 3, 2};

    // Brute Force Solution
    BruteForceSolution bruteForce;
    int bruteResult = bruteForce.majorityElement(nums);
    cout << "Brute Force Result: " << bruteResult << endl;

    // Optimal Solution
    OptimalSolution optimal;
    int optimalResult = optimal.majorityElement(nums);
    cout << "Optimal Result: " << optimalResult << endl;

    return 0;
}
