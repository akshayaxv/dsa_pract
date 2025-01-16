#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/spiral-matrix/

/*
Problem Statement:
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

/*
Approach #1: Brute Force
- Keep track of visited elements in a separate matrix of size m x n.
- Traverse in a spiral order while checking if the cell is already visited.

Time Complexity: O(m * n)
Space Complexity: O(m * n) (for visited matrix)
*/

class BruteForceSolution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> ans;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int row = 0, col = 0, dir = 0; // Directions: 0 -> right, 1 -> down, 2 -> left, 3 -> up
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0}; // Direction vectors

        for (int i = 0; i < rows * cols; i++) {
            ans.push_back(matrix[row][col]);
            visited[row][col] = true;
            int nextRow = row + dr[dir];
            int nextCol = col + dc[dir];

            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && !visited[nextRow][nextCol]) {
                row = nextRow;
                col = nextCol;
            } else {
                dir = (dir + 1) % 4; // Change direction
                row += dr[dir];
                col += dc[dir];
            }
        }
        return ans;
    }
};

/*
Dry Run for Brute Force Solution:
Input: matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}

Initial State:
  rows = 3, cols = 3
  visited = {{false, false, false}, {false, false, false}, {false, false, false}}
  dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0}
  row = 0, col = 0, dir = 0
  ans = {}

Step-by-Step Execution:
1. Visit matrix[0][0] = 1 → ans = {1}, mark visited[0][0] = true
2. Move right to matrix[0][1] = 2 → ans = {1, 2}, mark visited[0][1] = true
3. Move right to matrix[0][2] = 3 → ans = {1, 2, 3}, mark visited[0][2] = true
4. Change direction (down), move to matrix[1][2] = 6 → ans = {1, 2, 3, 6}, mark visited[1][2] = true
5. Move down to matrix[2][2] = 9 → ans = {1, 2, 3, 6, 9}, mark visited[2][2] = true
6. Change direction (left), move to matrix[2][1] = 8 → ans = {1, 2, 3, 6, 9, 8}, mark visited[2][1] = true
7. Move left to matrix[2][0] = 7 → ans = {1, 2, 3, 6, 9, 8, 7}, mark visited[2][0] = true
8. Change direction (up), move to matrix[1][0] = 4 → ans = {1, 2, 3, 6, 9, 8, 7, 4}, mark visited[1][0] = true
9. Change direction (right), move to matrix[1][1] = 5 → ans = {1, 2, 3, 6, 9, 8, 7, 4, 5}, mark visited[1][1] = true

Output: {1, 2, 3, 6, 9, 8, 7, 4, 5}
*/

/*
Approach #2: Optimal Solution
- Use four boundaries: top, bottom, left, right.
- Traverse in a spiral order while shrinking the boundaries.

Time Complexity: O(m * n)
Space Complexity: O(1) (no additional space used)
*/

class OptimalSolution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left

            // Traverse from right to left across the bottom row (if still within bounds)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--; // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if still within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }

        return ans;
    }
};

/*
Dry Run for Optimal Solution:
Input: matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}

Initial State:
  top = 0, bottom = 2, left = 0, right = 2
Step 1: Traverse top row (1, 2, 3)
  ans = {1, 2, 3}, top++
Step 2: Traverse right column (6, 9)
  ans = {1, 2, 3, 6, 9}, right--
Step 3: Traverse bottom row (8, 7)
  ans = {1, 2, 3, 6, 9, 8, 7}, bottom--
Step 4: Traverse left column (4)
  ans = {1, 2, 3, 6, 9, 8, 7, 4}, left++
Step 5: Traverse middle element (5)
  ans = {1, 2, 3, 6, 9, 8, 7, 4, 5}, top++

Output: {1, 2, 3, 6, 9, 8, 7, 4, 5}
*/

// Driver Code
int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Brute Force Solution
    BruteForceSolution brute;
    vector<int> bruteResult = brute.spiralOrder(matrix);
    cout << "Brute Force Result: ";
    for (int num : bruteResult) cout << num << " ";
    cout << endl;

    // Optimal Solution
    OptimalSolution optimal;
    vector<int> optimalResult = optimal.spiralOrder(matrix);
    cout << "Optimal Result: ";
    for (int num : optimalResult) cout << num << " ";
    cout << endl;

    return 0;
}
