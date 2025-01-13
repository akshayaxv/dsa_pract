#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if the array is sorted or not
    bool arraySortedOrNot(vector<int> &arr, int n)
    {
        /*
            This function checks if the given array is sorted in non-decreasing order.
            If the array is sorted, it returns true; otherwise, it returns false.
        */

        // If the array has only one element, it is considered sorted
        if (n == 1)
            return true;

        // Traverse the array and check for any inversion (arr[i] < arr[i-1])
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                return false; // Return false if an inversion is found
        }

        return true; // Return true if no inversion is found
    }
};

// Main function to demonstrate the solution
int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    if (obj.arraySortedOrNot(arr, n))
        cout << "The array is sorted.\n";
    else
        cout << "The array is not sorted.\n";

    return 0;
}

/*
Problem Statement:
Given an array of size `n`, check if the array is sorted in non-decreasing order.
If it is sorted, return true; otherwise, return false.

Constraints:
1 <= n <= 10^5 (size of the array)
1 <= arr[i] <= 10^9 (values of the array elements)

Example:
Input: arr = {1, 2, 3, 4, 5}, n = 5
Output: true

Input: arr = {5, 3, 2, 1}, n = 4
Output: false

Brute Force Solution:
- Compare every element `arr[i]` with every other element after it.
- Return false if any inversion (arr[j] < arr[i]) is found.

Code:
bool bruteForceArraySortedOrNot(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                return false; // Found an inversion
        }
    }
    return true; // No inversion found
}

Time Complexity Analysis:
Optimal Solution:
- Best case: O(n) (when the array is sorted, only one pass is required)
- Worst case: O(n) (entire array is traversed to find the inversion)
- Space Complexity: O(1) (no additional space used)

Brute Force Solution:
- Time Complexity: O(n^2) (nested loop for comparisons)
- Space Complexity: O(1) (no additional space used)

Dry Run (Example Input):
Input: arr = {1, 2, 3, 4, 5}, n = 5
Optimal Solution:
- Traverse the array:
  i=1: arr[1] >= arr[0] (2 >= 1) -> continue
  i=2: arr[2] >= arr[1] (3 >= 2) -> continue
  i=3: arr[3] >= arr[2] (4 >= 3) -> continue
  i=4: arr[4] >= arr[3] (5 >= 4) -> continue
- No inversion found; return true.

Input: arr = {5, 3, 2, 1}, n = 4
- Traverse the array:
  i=1: arr[1] < arr[0] (3 < 5) -> inversion found; return false.

Output:
- For arr = {1, 2, 3, 4, 5}, output: "The array is sorted."
- For arr = {5, 3, 2, 1}, output: "The array is not sorted."
*/
