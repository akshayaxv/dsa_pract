#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Time Complexity: O(n^2) 
// Space Complexity: O(1)
class BruteForceSolution {
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n) {
        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[j] > A[i]) {
                    ans.push_back({i, j});
                    break; // Exit as soon as we find the first profitable sell
                }
            }
        }
        return ans;
    }
};

/* 
Dry Run: Brute Force Solution
Input: A = {100, 180, 260, 310, 40, 535, 695}, n = 7

Step 1: Start with i = 0
  - j = 1 → 180 > 100 → Buy on day 0, Sell on day 1
  - j = 2 → 260 > 100 → Update to Buy on day 0, Sell on day 2
  - j = 3 → 310 > 100 → Update to Buy on day 0, Sell on day 3

Step 2: Continue for i = 1 to i = 5, finding profitable buys and sells.

Final Output: [[0, 3], [4, 6]]
*/

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
class OptimalSolution {
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n) {
        vector<vector<int>> ans;
        bool buy = true;
        int b, s;

        for (int i = 0; i < n - 1; i++) {
            if (buy && A[i] < A[i + 1]) {
                // Start a new transaction
                b = i;
                buy = false;
            } else if (!buy && A[i] > A[i + 1]) {
                // Complete the transaction
                s = i;
                ans.push_back({b, s});
                buy = true;
            }
        }
        // If we end with a buy but no sell, handle the last transaction
        if (!buy && A[n - 1] > A[b]) {
            ans.push_back({b, n - 1});
        }
        return ans;
    }
};

/* 
Dry Run: Optimal Solution
Input: A = {100, 180, 260, 310, 40, 535, 695}, n = 7

Step 1: Initialize buy = true, b = -1, s = -1

Step 2: Traverse the array
  - i = 0 → buy = true → A[0] < A[1] → b = 0, buy = false
  - i = 3 → !buy → A[3] > A[4] → s = 3, ans = {{0, 3}}, buy = true
  - i = 4 → buy = true → A[4] < A[5] → b = 4, buy = false
  - i = 6 → End of array → !buy → A[6] > A[4] → s = 6, ans = {{0, 3}, {4, 6}}

Final Output: [[0, 3], [4, 6]]
*/

// Driver Code
int main() {
    vector<int> A = {100, 180, 260, 310, 40, 535, 695};
    int n = A.size();

    // Brute Force Solution
    BruteForceSolution brute;
    vector<vector<int>> bruteResult = brute.stockBuySell(A, n);
    cout << "Brute Force Result:" << endl;
    for (auto x : bruteResult) {
        cout << "[" << x[0] << ", " << x[1] << "] ";
    }
    cout << endl;

    // Optimal Solution
    OptimalSolution optimal;
    vector<vector<int>> optimalResult = optimal.stockBuySell(A, n);
    cout << "Optimal Result:" << endl;
    for (auto x : optimalResult) {
        cout << "[" << x[0] << ", " << x[1] << "] ";
    }
    cout << endl;

    return 0;
}
