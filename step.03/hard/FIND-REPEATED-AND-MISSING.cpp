#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of size n, find two elements - one that appears twice and the other that is missing.

class Solution {
public:
    // Brute Force Approach:
    // In brute force, we can use an unordered map to keep track of the frequencies of elements.
    // The element which has frequency > 1 is the repeated element, and the element that does not appear in the map is the missing element.
    // Time Complexity: O(n) - We traverse the array twice (one for counting, one for checking)
    // Space Complexity: O(n) - We are using an unordered map to store the counts of elements.

    vector<int> findTwoElement_bruteforce(vector<int> arr, int n) {
        unordered_map<int, int> mp;
        vector<int> ans;

        // Traverse through the array to count frequencies of elements
        for (auto it : arr) {
            mp[it]++;
            if (mp[it] > 1) {
                ans.push_back(it);  // If element appears more than once, it is the repeated element
            }
        }

        // Traverse from 1 to n to find the missing element (which has 0 frequency in the map)
        for (int i = 1; i <= n; i++) {
            if (mp[i] == 0) {
                ans.push_back(i);  // Missing element
            }
        }

        return ans;
    }
    
    /*
    Dry Run for Brute Force Approach:
    Input: arr = [4, 3, 2, 7, 8, 2, 1]
    n = 8

    - Frequency map after traversing arr:
      mp = {4: 1, 3: 1, 2: 2, 7: 1, 8: 1, 1: 1}

    - Repeated element: 2 (appears more than once)
    - Missing element: 5 (doesn't appear in the map)
    
    Output: [2, 5]
    */

    /* -------------------------------------------------- */

    // Optimized Approach:
    // We can avoid using extra space and solve the problem in O(n) time and O(1) space by manipulating the array.
    // 1. Traverse the array, and for each element 'x', mark the element at index |x| - 1 as negative.
    // 2. If we encounter a number whose corresponding index is already negative, then it is the repeated number.
    // 3. After this step, the positive index will indicate the missing number.
    // Time Complexity: O(n) - We traverse the array once.
    // Space Complexity: O(1) - No extra space except for the output.

    vector<int> findTwoElement_optimized(vector<int> arr, int n) {
        vector<int> ans;
        
        // Traverse the array to find the repeated and missing element
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1;
            
            // If the element at the index is negative, it means the current number is repeated
            if (arr[index] < 0) {
                ans.push_back(abs(arr[i]));
            } else {
                arr[index] = -arr[index];  // Mark the element as visited by negating it
            }
        }

        // Traverse the array again to find the missing element
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {  // The index + 1 is the missing element
                ans.push_back(i + 1);
                break;
            }
        }

        return ans;
    }
    
    /*
    Dry Run for Optimized Approach:
    Input: arr = [4, 3, 2, 7, 8, 2, 1]
    n = 8

    - After first traversal:
      arr = [-4, -3, -2, 7, 8, 2, -1] (marked the indices for 4, 3, 2, and 1)
      Repeated element: 2 (the second occurrence of 2 is detected)

    - After second traversal, index 4 is positive, meaning 5 is missing.

    Output: [2, 5]
    */
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {4, 3, 2, 7, 8, 2, 1};
    int n = arr1.size();
    
    // Brute Force Solution
    vector<int> result_bruteforce = sol.findTwoElement_bruteforce(arr1, n);
    cout << "Brute Force Result: Repeated Element = " << result_bruteforce[0] 
         << ", Missing Element = " << result_bruteforce[1] << endl;

    // Optimized Solution
    vector<int> arr2 = {4, 3, 2, 7, 8, 2, 1};
    vector<int> result_optimized = sol.findTwoElement_optimized(arr2, n);
    cout << "Optimized Result: Repeated Element = " << result_optimized[0] 
         << ", Missing Element = " << result_optimized[1] << endl;

    return 0;
}
