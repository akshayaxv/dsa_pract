#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class BruteForceSolution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        long long ans = LLONG_MIN;

        // Dry Run Example:
        // Input: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        // Subarrays and their sums:
        // [-2] = -2
        // [-2, 1] = -1
        // [-2, 1, -3] = -4
        // ...
        // Maximum Sum: 6 (Subarray [4, -1, 2, 1])

        for (int i = 0; i < n; i++) {
            long long temp = 0;
            for (int j = i; j < n; j++) {
                temp += arr[j]; // Calculate the sum of subarray arr[i..j]
                ans = max(ans, temp); // Update the maximum sum
            }
        }
        return ans;
    }
};

// Optimized Solution: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
class OptimizedSolution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        long long maxi = LLONG_MIN, sum = 0;

        // Dry Run Example:
        // Input: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        // Step-by-step calculations:
        // i = 0, sum = -2, maxi = -2
        // i = 1, sum = 1, maxi = 1
        // i = 2, sum = -2, maxi = 1
        // i = 3, sum = 4, maxi = 4
        // i = 4, sum = 3, maxi = 4
        // i = 5, sum = 5, maxi = 5
        // i = 6, sum = 6, maxi = 6
        // i = 7, sum = 1, maxi = 6
        // i = 8, sum = 5, maxi = 6
        // Output: 6

        for (int i = 0; i < n; i++) {
            sum += arr[i];           // Add the current element to the sum
            maxi = max(maxi, sum);   // Update the maximum sum
            if (sum < 0) sum = 0;    // Reset the sum if it becomes negative
        }
        return maxi;
    }
};

// Driver Code
int main() {
    // Test Case
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Brute Force Solution
    BruteForceSolution bruteForce;
    long long bruteResult = bruteForce.maxSubarraySum(arr);
    cout << "Brute Force Result: " << bruteResult << endl;

    // Optimized Solution
    OptimizedSolution optimized;
    long long optimizedResult = optimized.maxSubarraySum(arr);
    cout << "Optimized Result: " << optimizedResult << endl;

    return 0;
}
