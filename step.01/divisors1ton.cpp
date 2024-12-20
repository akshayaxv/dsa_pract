#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
// Time Complexity: O(N * sqrt(N))
//   - Outer loop runs from 1 to N: O(N)
//   - Inner loop checks divisors up to sqrt(n): O(sqrt(N)) per number.
// Space Complexity: O(1)
//   - No extra space is used.

class Solution {
public:
    long long sumOfDivisors(int N) {
        long long ans = 0; // Initialize total sum to 0

        // Loop through all numbers from 1 to N
        for (int j = 1; j <= N; j++) {
            int n = j; // Current number for which divisors are being calculated

            // Find divisors of the current number
            for (int i = 1; i <= sqrt(n); i++) { // Check divisors up to sqrt(n)
                if (n % i == 0) { // If i is a divisor
                    ans += i; // Add i to the sum of divisors

                    // If i is not equal to n / i (to avoid double counting)
                    if (i != n / i) {
                        ans += n / i; // Add the other divisor
                    }
                }
            }
        }

        return ans; // Return the total sum of divisors from 1 to N
    }
};

int main() {
    int N;
    cin >> N; // Input the number N
    Solution sol;
    cout << sol.sumOfDivisors(N) << endl; // Output the result
    return 0;
}

/*
Dry Run Example:
Input: N = 4

Step 1: Initialize ans = 0.

Step 2: Iterate through numbers 1 to 4.

- For j = 1:
  Divisors: 1
  Add: 1
  Total ans = 1

- For j = 2:
  Divisors: 1, 2
  Add: 1 + 2
  Total ans = 4

- For j = 3:
  Divisors: 1, 3
  Add: 1 + 3
  Total ans = 8

- For j = 4:
  Divisors: 1, 2, 4
  Add: 1 + 2 + 4
  Total ans = 15

Output:
ans = 15
*/
