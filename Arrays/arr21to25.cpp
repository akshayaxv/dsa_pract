#include <iostream>
#include <vector>
#include <algorithm> // For next_permutation
#include <unordered_set> // For longest consecutive sequence
using namespace std;

/* 📝 1️⃣ REARRANGE ARRAY IN ALTERNATING POSITIVE & NEGATIVE ORDER
   - Separate positives & negatives, then merge them alternately.
   - Time Complexity: O(N)
   - Space Complexity: O(N) (Extra vector)
*/
vector<int> rearrangeAlternately(vector<int>& arr) {
    vector<int> pos, neg, result;
    for (int num : arr) {
        if (num >= 0) pos.push_back(num);
        else neg.push_back(num);
    }
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }
    while (i < pos.size()) result.push_back(pos[i++]);
    while (j < neg.size()) result.push_back(neg[j++]);
    return result;
}

/*
📌 DRY RUN (Input: [1,2,-3,-4,5,-6])
Step 1: Positives: [1,2,5], Negatives: [-3,-4,-6]
Step 2: Merge alternately → [1,-3,2,-4,5,-6]
Output: [1,-3,2,-4,5,-6]
*/

/* 📝 2️⃣ NEXT PERMUTATION
   - Find the next lexicographically greater permutation.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
void nextPermutation(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end());
}

/*
📌 DRY RUN (Input: [1,2,3])
Step 1: Swap last increasing pair → [1,3,2]
Output: [1,3,2]
*/

/* 📝 3️⃣ LEADERS IN AN ARRAY
   - Traverse from right & keep track of max leader.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
vector<int> findLeaders(vector<int>& arr) {
    vector<int> leaders;
    int maxRight = arr.back(); // Rightmost element is always a leader
    leaders.push_back(maxRight);
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            leaders.push_back(arr[i]);
            maxRight = arr[i]; // Update max
        }
    }
    reverse(leaders.begin(), leaders.end()); // Reverse to maintain order
    return leaders;
}

/*
📌 DRY RUN (Input: [16,17,4,3,5,2])
Step 1: Right to left scan → Leaders found: [17,5,2]
Output: [17,5,2]
*/

/* 📝 4️⃣ LONGEST CONSECUTIVE SEQUENCE
   - Use Hash Set for fast lookup.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
int longestConsecutive(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end()); // Store all elements in a set
        int longest = 0;

        for (int num : s) { // Iterate over set to avoid duplicate checks
            // Start a sequence only if it's the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currNum = num;
                int count = 1;

                // Count consecutive elements
                while (s.find(currNum + 1) != s.end()) {
                    currNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
   
}

/*
📌 DRY RUN (Input: [100,4,200,1,3,2])
Step 1: Find start of sequences → [1,2,3,4] is longest
Output: 4
*/

/* 📝 5️⃣ SET MATRIX ZEROS (Using First Row & Column as Markers)
   - Mark rows & cols to be set to zero.
   - Time Complexity: O(N*M)
   - Space Complexity: O(1)
*/
void setMatrixZeros(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < m; i++) if (matrix[i][0] == 0) firstCol = true;
    for (int j = 0; j < n; j++) if (matrix[0][j] == 0) firstRow = true;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (firstRow) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    if (firstCol) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}

/*
📌 DRY RUN (Input: [[1,1,1],[1,0,1],[1,1,1]])
Step 1: Mark rows & cols → [[1,0,1],[0,0,0],[1,0,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

/* 📝 6️⃣ ROTATE MATRIX BY 90 DEGREES (Transpose & Reverse)
   - First Transpose, then Reverse rows.
   - Time Complexity: O(N²)
   - Space Complexity: O(1)
*/
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]); // Transpose

    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end()); // Reverse each row
}

/*
📌 DRY RUN (Input: [[1,2,3],[4,5,6],[7,8,9]])
Step 1: Transpose → [[1,4,7],[2,5,8],[3,6,9]]
Step 2: Reverse Rows → [[7,4,1],[8,5,2],[9,6,3]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

/* 🏆 MAIN FUNCTION */
int main() {
    vector<int> arr = {1, 2, -3, -4, 5, -6};
    vector<int> altArr = rearrangeAlternately(arr);
    cout << "Alternating Pos/Neg: ";
    for (int num : altArr) cout << num << " ";
    cout << endl;

    vector<int> permArr = {1, 2, 3};
    nextPermutation(permArr);
    cout << "Next Permutation: ";
    for (int num : permArr) cout << num << " ";
    cout << endl;

    vector<int> leaderArr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(leaderArr);
    cout << "Leaders: ";
    for (int num : leaders) cout << num << " ";
    cout << endl;

    vector<int> seqArr = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << longestConsecutive(seqArr) << endl;

    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZeros(matrix);

    vector<vector<int>> rotMatrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(rotMatrix);

    return 0;
}
