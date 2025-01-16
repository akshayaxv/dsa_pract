#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// Approach #1: Brute Force
// Time Complexity: O(n * log(n)) for sorting + O(n) for traversal = O(n * log(n)).
// Space Complexity: O(1).
class BruteForceSolution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        sort(arr, arr + N); // Sort the array
        int longest = 1, current = 1;

        for (int i = 1; i < N; i++) {
            // If consecutive, increase the streak
            if (arr[i] == arr[i - 1] + 1) {
                current++;
            }
            // If duplicate, skip
            else if (arr[i] != arr[i - 1]) {
                longest = max(longest, current);
                current = 1;
            }
        }

        longest = max(longest, current);
        return longest;
    }
};

/*
Dry Run: Brute Force Solution
Input: arr = {1, 9, 3, 10, 4, 20, 2}, N = 7
Step 1: Sort array → arr = {1, 2, 3, 4, 9, 10, 20}
Step 2: Traverse sorted array
  i = 1 → arr[1] = 2, arr[0] + 1 → current = 2
  i = 2 → arr[2] = 3, arr[1] + 1 → current = 3
  i = 3 → arr[3] = 4, arr[2] + 1 → current = 4
  i = 4 → arr[4] = 9 → reset, longest = 4, current = 1
  i = 5 → arr[5] = 10, arr[4] + 1 → current = 2
  i = 6 → arr[6] = 20 → reset, longest = 4
Output: longest = 4
*/

// Approach #2: Optimal Solution
// Time Complexity: O(n), as we process each element once.
// Space Complexity: O(n), for the unordered set.
class OptimalSolution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        unordered_set<int> st;
        // Insert all elements into the set
        for (int i = 0; i < N; i++) {
            st.insert(arr[i]);
        }

        int longest = 0;
        // Traverse each element in the array
        for (int i = 0; i < N; i++) {
            // Check if the current element is the start of a sequence
            if (st.find(arr[i] - 1) == st.end()) {
                int currentNum = arr[i];
                int currentStreak = 1;

                // Count the streak for the current element
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak
                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

/*
Dry Run: Optimal Solution
Input: arr = {1, 9, 3, 10, 4, 20, 2}, N = 7
Step 1: Insert into set → st = {1, 9, 3, 10, 4, 20, 2}
Step 2: Traverse elements
  i = 0, arr[0] = 1 → start of sequence → count = 4 (1 → 2 → 3 → 4)
  i = 1, arr[1] = 9 → start of sequence → count = 2 (9 → 10)
  i = 2, arr[2] = 3 → not the start
  i = 3, arr[3] = 10 → not the start
  i = 4, arr[4] = 4 → not the start
  i = 5, arr[5] = 20 → start of sequence → count = 1
  i = 6, arr[6] = 2 → not the start
Output: longest = 4
*/

// Driver Code
int main() {
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Brute Force Solution
    BruteForceSolution brute;
    cout << "Brute Force Result: " << brute.findLongestConseqSubseq(arr, N) << endl;

    // Optimal Solution
    OptimalSolution optimal;
    cout << "Optimal Result: " << optimal.findLongestConseqSubseq(arr, N) << endl;

    return 0;
}
