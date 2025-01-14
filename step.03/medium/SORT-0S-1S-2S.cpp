#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1)
class BruteForceSolution {
public:
    void sort012(vector<int>& a) {
        // Dry Run Example:
        // Input: a = [2, 0, 1, 1, 0, 2]
        // Expected Output: a = [0, 0, 1, 1, 2, 2]
        
        // Approach: Use in-built sorting function
        sort(a.begin(), a.end());

        // Dry Run:
        // Initial Vector: [2, 0, 1, 1, 0, 2]
        // After Sorting: [0, 0, 1, 1, 2, 2]
    }
};

// Optimal Solution (Dutch National Flag Algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)
class OptimalSolution {
public:
    void sort012(vector<int>& a) {
        // Dry Run Example:
        // Input: a = [2, 0, 1, 1, 0, 2]
        // Expected Output: a = [0, 0, 1, 1, 2, 2]
        
        int zero = 0, one = 0, two = a.size() - 1; // Three pointers to track positions
        
        // Traverse the vector
        while (one <= two) {
            if (a[one] == 0) {
                // Case 1: a[one] == 0
                // Swap a[zero] and a[one], increment zero and one
                swap(a[zero++], a[one++]);
            } else if (a[one] == 1) {
                // Case 2: a[one] == 1
                // Increment one as 1 is already in the correct position
                one++;
            } else {
                // Case 3: a[one] == 2
                // Swap a[one] and a[two], decrement two
                swap(a[one], a[two--]);
            }
        }

        // Dry Run:
        // Input: [2, 0, 1, 1, 0, 2]
        // Initial pointers: zero = 0, one = 0, two = 5
        // Step-by-step:
        // Step 1: a[0] = 2 -> swap(a[0], a[5]) -> [2, 0, 1, 1, 0, 2], two = 4
        // Step 2: a[0] = 2 -> swap(a[0], a[4]) -> [0, 0, 1, 1, 2, 2], two = 3
        // Step 3: a[0] = 0 -> swap(a[0], a[0]) -> [0, 0, 1, 1, 2, 2], zero = 1, one = 1
        // Step 4: a[1] = 0 -> swap(a[1], a[1]) -> [0, 0, 1, 1, 2, 2], zero = 2, one = 2
        // Step 5: a[2] = 1 -> one++
        // Step 6: a[3] = 1 -> one++
        // Final Array: [0, 0, 1, 1, 2, 2]
    }
};

// Driver Code
int main() {
    // Test Case
    vector<int> a = {2, 0, 1, 1, 0, 2};

    // Brute Force Solution
    BruteForceSolution bruteForce;
    vector<int> bruteVector = a; // Create a copy for brute force
    bruteForce.sort012(bruteVector);
    cout << "Brute Force Sorted Vector: ";
    for (int num : bruteVector) {
        cout << num << " ";
    }
    cout << endl;

    // Optimal Solution
    OptimalSolution optimal;
    vector<int> optimalVector = a; // Create a copy for optimal solution
    optimal.sort012(optimalVector);
    cout << "Optimal Sorted Vector: ";
    for (int num : optimalVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
