#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Problem Statement:
// Generate Pascal's Triangle up to numRows rows.

// Link: https://leetcode.com/problems/pascals-triangle/

// [Approach #1] Brute Force Using nCr Formula
// Time Complexity: O(numRows^2)
// Space Complexity: O(1) (excluding the result vector)

class BruteForceSolution {
public:
    // Function to calculate nCr = n! / (r! * (n-r)!)
    long long ncr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; ++i) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        // Generate each row of Pascal's Triangle
        for (int i = 1; i <= numRows; ++i) {
            vector<int> row;
            for (int j = 1; j <= i; ++j) {
                row.push_back(ncr(i - 1, j - 1));
            }
            ans.push_back(row);
        }

        return ans;
    }
};

/*
Dry Run for Brute Force:
Input: numRows = 4

Step-by-Step Execution:
1. i = 1:
   - j = 1: nCr(0, 0) = 1 → row = [1]
   → ans = [[1]]
2. i = 2:
   - j = 1: nCr(1, 0) = 1
   - j = 2: nCr(1, 1) = 1 → row = [1, 1]
   → ans = [[1], [1, 1]]
3. i = 3:
   - j = 1: nCr(2, 0) = 1
   - j = 2: nCr(2, 1) = 2
   - j = 3: nCr(2, 2) = 1 → row = [1, 2, 1]
   → ans = [[1], [1, 1], [1, 2, 1]]
4. i = 4:
   - j = 1: nCr(3, 0) = 1
   - j = 2: nCr(3, 1) = 3
   - j = 3: nCr(3, 2) = 3
   - j = 4: nCr(3, 3) = 1 → row = [1, 3, 3, 1]
   → ans = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]
*/

// [Approach #2] Optimal Solution Without nCr
// Time Complexity: O(numRows^2)
// Space Complexity: O(1) (excluding the result vector)

class OptimalSolution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // Initialize the row with 1s
            for (int j = 1; j < i; ++j) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }

        return ans;
    }
};

/*
Dry Run for Optimal Solution:
Input: numRows = 4

Step-by-Step Execution:
1. i = 0:
   - row = [1]
   → ans = [[1]]
2. i = 1:
   - row = [1, 1]
   → ans = [[1], [1, 1]]
3. i = 2:
   - row = [1, 1] → Update: row[1] = ans[1][0] + ans[1][1] = 1 + 1 = 2
   → row = [1, 2, 1]
   → ans = [[1], [1, 1], [1, 2, 1]]
4. i = 3:
   - row = [1, 1, 1, 1] → Update:
     row[1] = ans[2][0] + ans[2][1] = 1 + 2 = 3
     row[2] = ans[2][1] + ans[2][2] = 2 + 1 = 3
   → row = [1, 3, 3, 1]
   → ans = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]
*/

// Driver Code
int main() {
    int numRows = 5;

    // Brute Force Solution
    BruteForceSolution bruteForce;
    vector<vector<int>> bruteResult = bruteForce.generate(numRows);
    cout << "Brute Force Result:" << endl;
    for (auto row : bruteResult) {
        for (auto ele : row) cout << ele << " ";
        cout << endl;
    }

    // Optimal Solution
    OptimalSolution optimal;
    vector<vector<int>> optimalResult = optimal.generate(numRows);
    cout << "\nOptimal Result:" << endl;
    for (auto row : optimalResult) {
        for (auto ele : row) cout << ele << " ";
        cout << endl;
    }

    return 0;
}
