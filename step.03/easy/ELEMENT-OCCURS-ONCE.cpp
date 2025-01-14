#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Brute Force Approach:
     * Time Complexity: O(N^2) -> For each element, we count its occurrences.
     * Space Complexity: O(1) -> No extra space used.
     * Explanation:
     * - For every element, we count how many times it appears in the array.
     * - If it appears exactly once, it is returned as the answer.
     * Dry Run:
     * A = [1, 2, 3, 2, 1], N = 5
     * Step 1: Count occurrences of 1 -> appears 2 times.
     * Step 2: Count occurrences of 2 -> appears 2 times.
     * Step 3: Count occurrences of 3 -> appears 1 time.
     * Output: 3
     */
    int searchBruteForce(vector<int>& A, int N) {
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (A[i] == A[j]) {
                    count++;
                }
            }
            if (count == 1) {
                return A[i];
            }
        }
        return -1; // Should never reach here if the input guarantees a unique element.
    }

    /*
     * Optimized Approach:
     * Time Complexity: O(N) -> Single traversal of the array.
     * Space Complexity: O(1) -> Constant space used.
     * Explanation:
     * - Use XOR properties: a ^ a = 0 and a ^ 0 = a.
     * - XOR all elements; duplicates cancel each other, leaving the unique element.
     * Dry Run:
     * A = [1, 2, 3, 2, 1], N = 5
     * Step 1: ans = 0 ^ 1 = 1
     * Step 2: ans = 1 ^ 2 = 3
     * Step 3: ans = 3 ^ 3 = 0
     * Step 4: ans = 0 ^ 2 = 2
     * Step 5: ans = 2 ^ 1 = 1
     * Output: 1
     */
    int searchOptimized(vector<int>& A, int N) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans ^= A[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> A = {1, 2, 3, 2, 1};
    int N = A.size();

    // Brute Force Approach
    cout << "Brute Force Approach: The unique element is: " << sol.searchBruteForce(A, N) << endl;

    // Optimized Approach
    cout << "Optimized Approach: The unique element is: " << sol.searchOptimized(A, N) << endl;

    return 0;
}
