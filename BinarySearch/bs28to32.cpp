#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound
using namespace std;

/* 📝 1️⃣ FIND ROW WITH MAXIMUM NUMBER OF 1's (Binary Search)
   - Each row is sorted (0s followed by 1s).
   - Use Binary Search to find the first occurrence of 1.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
int rowWithMaxOnes(vector<vector<int>>& matrix) {
    int maxRow = -1, maxOnes = 0;
    int rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        int firstOne = lower_bound(matrix[i].begin(), matrix[i].end(), 1) - matrix[i].begin();
        int onesCount = cols - firstOne;
        if (onesCount > maxOnes) {
            maxOnes = onesCount;
            maxRow = i;
        }
    }

    return maxRow;
}

/*
📌 DRY RUN (Input: [[0,0,1,1],[0,1,1,1],[0,0,0,1]])
Step 1: Binary search first 1 in each row.
Step 2: Find row with max ones.
Output: 1 (2nd row)
*/

/* 📝 2️⃣ SEARCH IN A 2D MATRIX
   - Matrix is sorted row-wise and top to bottom.
   - Binary Search on entire matrix treating it as a 1D array.
   - Time Complexity: O(log (N*M))
   - Space Complexity: O(1)
*/
bool searchInMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midElement = matrix[mid / cols][mid % cols]; // Convert 1D index to 2D

        if (midElement == target) return true;
        else if (midElement < target) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

/*
📌 DRY RUN (Input: [[1,3,5],[7,10,11],[12,14,15]], target=10)
Step 1: Binary search on 1D index.
Step 2: Convert mid to 2D index and check value.
Output: true
*/

/* 📝 3️⃣ SEARCH IN A ROW & COLUMN WISE SORTED MATRIX
   - Start search from top-right or bottom-left.
   - Time Complexity: O(N + M)
   - Space Complexity: O(1)
*/
bool searchInSortedMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int row = 0, col = cols - 1; // Start from top-right corner

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++; // Move down
        else col--; // Move left
    }

    return false;
}

/*
📌 DRY RUN (Input: [[1,4,7],[2,5,8],[3,6,9]], target=5)
Step 1: Start at top-right (7).
Step 2: Move left to (4), then down to (5) ✅ Found.
Output: true
*/

/* 📝 4️⃣ FIND PEAK ELEMENT IN A 2D MATRIX (Binary Search)
   - A peak element is greater than its neighbors.
   - Binary Search on mid column, find max row, move left/right.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
pair<int, int> findPeakElement2D(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = cols - 1;

    while (left <= right) {
        int midCol = left + (right - left) / 2;

        // Find row index of max element in this column
        int maxRow = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][midCol] > matrix[maxRow][midCol]) {
                maxRow = i;
            }
        }

        bool isLeftSmaller = (midCol == 0) || (matrix[maxRow][midCol] > matrix[maxRow][midCol - 1]);
        bool isRightSmaller = (midCol == cols - 1) || (matrix[maxRow][midCol] > matrix[maxRow][midCol + 1]);

        if (isLeftSmaller && isRightSmaller) return {maxRow, midCol}; // Peak found
        else if (midCol > 0 && matrix[maxRow][midCol - 1] > matrix[maxRow][midCol]) right = midCol - 1; // Move left
        else left = midCol + 1; // Move right
    }

    return {-1, -1}; // No peak found
}

/*
📌 DRY RUN (Input: [[10,20,15],[21,30,14],[7,16,32]])
Step 1: Binary search on middle column.
Step 2: Find max row in mid column.
Step 3: Move left/right based on neighbors.
Output: (1,1) (30 is the peak)
*/

/* 📝 5️⃣ FIND MEDIAN OF A ROW-WISE SORTED MATRIX (Binary Search)
   - Find median in a row-wise sorted matrix.
   - Binary Search on value range.
   - Time Complexity: O(N log MaxElement)
   - Space Complexity: O(1)
*/
int countSmallerOrEqual(vector<vector<int>>& matrix, int num) {
    int count = 0;
    for (auto& row : matrix) {
        count += upper_bound(row.begin(), row.end(), num) - row.begin();
    }
    return count;
}

int findMedianMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 1, right = 1e9; // Assumed value range (1 to max possible)

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countSmallerOrEqual(matrix, mid) < (rows * cols + 1) / 2) left = mid + 1;
        else right = mid;
    }

    return left;
}

/*
📌 DRY RUN (Input: [[1,3,5],[2,6,9],[3,6,9]])
Step 1: Binary search on value range.
Step 2: Count elements ≤ mid.
Step 3: Find median.
Output: 5
*/

/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    vector<vector<int>> matrix = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };
    cout << "Row with max 1s: " << rowWithMaxOnes(matrix) << endl;

    vector<vector<int>> sortedMatrix = {
        {1, 3, 5},
        {7, 10, 11},
        {12, 14, 15}
    };
    cout << "Element found in 2D Matrix: " << (searchInMatrix(sortedMatrix, 10) ? "true" : "false") << endl;

    vector<vector<int>> sortedRowColMatrix = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    cout << "Element found in row-wise and column-wise sorted matrix: " 
         << (searchInSortedMatrix(sortedRowColMatrix, 5) ? "true" : "false") << endl;

    auto peak = findPeakElement2D(sortedMatrix);
    cout << "Peak Element Found at: (" << peak.first << ", " << peak.second << ")" << endl;

    vector<vector<int>> medianMatrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median of Matrix: " << findMedianMatrix(medianMatrix) << endl;

    return 0;
}
