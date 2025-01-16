#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/description/

// Approach #1: Brute Force
// Time Complexity: O((n * m) * (n + m)), where `n` is the number of rows and `m` is the number of columns.
// Space Complexity: O(1).
class BruteForceSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        // Traverse the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If a cell is zero, mark the entire row and column with a special marker
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        if (matrix[k][j] != 0) matrix[k][j] = INT_MIN;
                    }
                    for (int k = 0; k < m; k++) {
                        if (matrix[i][k] != 0) matrix[i][k] = INT_MIN;
                    }
                }
            }
        }

        // Replace the markers with zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == INT_MIN) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
Dry Run: Brute Force Solution
Input: matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}
Step 1: Traverse and mark zeros:
  matrix = {{1, INT_MIN, 1}, {INT_MIN, 0, INT_MIN}, {1, INT_MIN, 1}}
Step 2: Replace markers with zeros:
  matrix = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}
Output: {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}
*/

// Approach #2: Optimal Solution
// Time Complexity: O(n * m)
// Space Complexity: O(1)
class OptimalSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Check if the first row or first column should be zero
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) firstRowZero = true;
        }

        // Use the first row and column as markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set rows and columns to zero based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row and column
        if (firstColZero) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        if (firstRowZero) {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }
    }
};

/*
Dry Run: Optimal Solution
Input: matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}
Step 1: Check first row/column:
  firstRowZero = false, firstColZero = false
Step 2: Mark zeros:
  matrix = {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}}
Step 3: Set rows/columns to zero:
  matrix = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}
Step 4: Handle first row/column:
  matrix = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}
Output: {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}
*/

// Driver Code
int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Brute Force Solution
    BruteForceSolution brute;
    vector<vector<int>> bruteMatrix = matrix;
    brute.setZeroes(bruteMatrix);
    cout << "Brute Force Result:" << endl;
    for (auto row : bruteMatrix) {
        for (auto elem : row) cout << elem << " ";
        cout << endl;
    }

    // Optimal Solution
    OptimalSolution optimal;
    vector<vector<int>> optimalMatrix = matrix;
    optimal.setZeroes(optimalMatrix);
    cout << "Optimal Result:" << endl;
    for (auto row : optimalMatrix) {
        for (auto elem : row) cout << elem << " ";
        cout << endl;
    }

    return 0;
}
