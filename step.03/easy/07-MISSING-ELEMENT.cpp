#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Optimized Approach:
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // Explanation:
    // We calculate the sum of all elements in the array using `accumulate`.
    // We also calculate the expected sum of all numbers from 1 to n using the formula: (n * (n+1)) / 2.
    // The missing number is the difference between the expected sum and the actual sum.
    // This approach works efficiently in O(N) time and constant space.
    
    int missingNumberOptimized(vector<int>& array, int n) {
        int act = accumulate(array.begin(), array.end(), 0);
        int tot = (n * (n + 1)) / 2;
        return tot - act;
    }

    // Brute Force Approach:
    // Time Complexity: O(N^2) because we check for each number from 1 to n if it is in the array.
    // Space Complexity: O(1) (excluding the space for the input array).

    int missingNumberBruteForce(vector<int>& array, int n) {
        // Check for each number from 1 to n
        for (int i = 1; i <= n; i++) {
            bool found = false;
            // Check if the number exists in the array
            for (int j = 0; j < array.size(); j++) {
                if (array[j] == i) {
                    found = true;
                    break;
                }
            }
            // If the number is not found, it is the missing number
            if (!found) {
                return i;
            }
        }

        return -1; // In case no missing number is found (this is a fallback, though there should always be one missing number)
    }
};

/*
 * Time Complexity and Dry Run Explanation:

 * Optimized Approach:
   - Time Complexity: O(N)
   - Space Complexity: O(1)
   - Explanation: We calculate the sum of elements in the array (`act`) and the total sum of numbers from 1 to `n` (`tot`). The difference between `tot` and `act` gives the missing number.

 * Dry Run for Optimized Approach:
   Input: array = [1, 2, 4, 5, 6], n = 6
   1. `act = accumulate(array.begin(), array.end(), 0) = 1 + 2 + 4 + 5 + 6 = 18`
   2. `tot = (6 * (6 + 1)) / 2 = 21`
   3. Missing number = `tot - act = 21 - 18 = 3`
   Output: 3

 * Brute Force Approach:
   - Time Complexity: O(N^2)
   - Space Complexity: O(1)
   - Explanation: We iterate through each number from 1 to `n`, checking if it exists in the array. If it doesn't, we return it as the missing number.

 * Dry Run for Brute Force Approach:
   Input: array = [1, 2, 4, 5, 6], n = 6
   1. Check for 1: found in the array.
   2. Check for 2: found in the array.
   3. Check for 3: not found in the array.
   4. Return 3 as the missing number.
   Output: 3
 */

int main() {
    Solution sol;
    vector<int> array = {1, 2, 4, 5, 6}; // Array with a missing number
    int n = 6; // The total number of elements including the missing one
    
    // Test the optimized solution
    cout << "Optimized approach missing number is: " << sol.missingNumberOptimized(array, n) << endl;
    
    // Test the brute force solution
    cout << "Brute force approach missing number is: " << sol.missingNumberBruteForce(array, n) << endl;
    
    return 0;
}
