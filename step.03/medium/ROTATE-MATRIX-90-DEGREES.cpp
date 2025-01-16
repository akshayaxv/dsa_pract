#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

/*
Problem Statement:
Given a square matrix, rotate it by 90 degrees in an anti-clockwise direction without using extra space.
*/

/*
Approach #1: Brute Force (Using Extra Space)
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class BruteForceSolution {
public:
    void rotateby90(vector<vector<int>> &matrix, int n) {
        vector<vector<int>> temp(n, vector<int>(n));
        // Store the rotated matrix in temp
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[n - j - 1][i] = matrix[i][j];
            }
        }
        // Copy temp to the original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};

/*
Dry Run for Brute Force:
Input: matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
Step 1: Initialize temp:
  temp = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
Step 2: Fill temp with rotated values:
  temp = {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}}
Step 3: Copy temp to matrix:
  matrix = {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}}
Output: {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}}
*/

/*
Approach #2: Optimal Solution (In-Place Rotation)
Steps:
1. Transpose the matrix: Swap matrix[i][j] with matrix[j][i] for all i, j where j > i.
2. Reverse each column to achieve the 90-degree rotation.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class OptimalSolution {
public:
    void rotateby90(vector<vector<int>> &matrix, int n) {
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each column
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n / 2; i++) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};

/*
Dry Run for Optimal Solution:
Input: matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
Step 1: Transpose:
  matrix = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}
Step 2: Reverse columns:
  matrix = {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}}
Output: {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}}
*/

// Driver Code
int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();

    // Brute Force Solution
    BruteForceSolution brute;
    vector<vector<int>> bruteMatrix = matrix;
    brute.rotateby90(bruteMatrix, n);
    cout << "Brute Force Result:" << endl;
    for (auto row : bruteMatrix) {
        for (auto elem : row) cout << elem << " ";
        cout << endl;
    }

    // Optimal Solution
    OptimalSolution optimal;
    vector<vector<int>> optimalMatrix = matrix;
    optimal.rotateby90(optimalMatrix, n);
    cout << "Optimal Result:" << endl;
    for (auto row : optimalMatrix) {
        for (auto elem : row) cout << elem << " ";
        cout << endl;
    }

    return 0;
}
