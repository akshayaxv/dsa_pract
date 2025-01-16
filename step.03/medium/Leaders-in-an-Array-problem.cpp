#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Approach #1: Brute Force
// Time Complexity: O(n^2), where n is the size of the array.
// Space Complexity: O(1).
class BruteForceSolution {
public:
    vector<int> leaders(int a[], int n) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            // Check if the current element is greater than or equal to all elements to its right
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};

/* 
Dry Run: Brute Force Solution
Input: a = {16, 17, 4, 3, 5, 2}, n = 6

Iteration 1: i = 0, a[0] = 16, check {17, 4, 3, 5, 2} → not a leader
Iteration 2: i = 1, a[1] = 17, check {4, 3, 5, 2} → leader
Iteration 3: i = 2, a[2] = 4, check {3, 5, 2} → not a leader
Iteration 4: i = 3, a[3] = 3, check {5, 2} → not a leader
Iteration 5: i = 4, a[4] = 5, check {2} → leader
Iteration 6: i = 5, a[5] = 2 → leader

Output: ans = {17, 5, 2}
*/

// Approach #2: Optimal Solution
// Time Complexity: O(n), as we traverse the array once from right to left.
// Space Complexity: O(1), apart from the output vector.
class OptimalSolution {
public:
    vector<int> leaders(int a[], int n) {
        vector<int> ans;
        int maxi = INT_MIN; // To keep track of the maximum element to the right
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= maxi) {
                ans.push_back(a[i]);
                maxi = a[i]; // Update the maximum
            }
        }
        // Since we collected leaders in reverse order, reverse the result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* 
Dry Run: Optimal Solution
Input: a = {16, 17, 4, 3, 5, 2}, n = 6

Step 1: Start from right
  i = 5, a[5] = 2, maxi = -∞ → leader, maxi = 2, ans = {2}
  i = 4, a[4] = 5, maxi = 2 → leader, maxi = 5, ans = {2, 5}
  i = 3, a[3] = 3, maxi = 5 → not a leader
  i = 2, a[2] = 4, maxi = 5 → not a leader
  i = 1, a[1] = 17, maxi = 5 → leader, maxi = 17, ans = {2, 5, 17}
  i = 0, a[0] = 16, maxi = 17 → not a leader

Step 2: Reverse the result
Output: ans = {17, 5, 2}
*/

// Driver Code
int main() {
    int a[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);

    // Brute Force Solution
    BruteForceSolution bruteForce;
    vector<int> bruteAns = bruteForce.leaders(a, n);
    cout << "Brute Force Result: ";
    for (int x : bruteAns) {
        cout << x << " ";
    }
    cout << endl;

    // Optimal Solution
    OptimalSolution optimal;
    vector<int> optimalAns = optimal.leaders(a, n);
    cout << "Optimal Result: ";
    for (int x : optimalAns) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
