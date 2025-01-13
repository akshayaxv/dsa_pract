#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if the array is sorted and rotated
    bool isSortedAndRotated(vector<int> &arr, int n)
    {
        /*
            This function checks if the given array is sorted and rotated.
            A sorted and rotated array has at most one "decreasing point".
        */

        int count = 0; // To count the number of "decreasing points"

        for (int i = 0; i < n; i++)
        {
            // Check if the current element is greater than the next element
            if (arr[i] > arr[(i + 1) % n])
                count++;

            // If there is more than one decreasing point, return false
            if (count > 1)
                return false;
        }

        return true; // Array is sorted and rotated
    }
};

// Main function to demonstrate the solution
int main()
{
    Solution obj;
    vector<int> arr = {3, 4, 5, 1, 2}; // Example input
    int n = arr.size();
    if (obj.isSortedAndRotated(arr, n))
        cout << "The array is sorted and rotated.\n";
    else
        cout << "The array is not sorted and rotated.\n";

    return 0;
}

/*
Problem Statement:
Given an array of size `n`, determine if the array is sorted in non-decreasing order 
and then rotated.

Constraints:
1 <= n <= 10^5 (size of the array)
1 <= arr[i] <= 10^9 (values of the array elements)

Examples:
Input: arr = {3, 4, 5, 1, 2}, n = 5
Output: true

Input: arr = {1, 2, 3, 4, 5}, n = 5
Output: false

Input: arr = {3, 5, 4, 1, 2}, n = 5
Output: false

Brute Force Solution:
- Create all possible rotations of the array.
- Check if any rotation is sorted in non-decreasing order.
- If found, return true; otherwise, return false.

Code:
bool bruteForceIsSortedAndRotated(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool sorted = true;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[(i + j) % n] > arr[(i + j + 1) % n])
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
            return true;
    }
    return false;
}

Time Complexity Analysis:
Optimal Solution:
- Best case: O(n) (one pass through the array)
- Worst case: O(n) (entire array is checked)
- Space Complexity: O(1) (no additional space used)

Brute Force Solution:
- Time Complexity: O(n^2) (nested loop for checking rotations)
- Space Complexity: O(1) (no additional space used)

Dry Run (Example Input):
Input: arr = {3, 4, 5, 1, 2}, n = 5
Optimal Solution:
- Traverse the array:
  i=0: arr[0]=3, arr[1]=4 -> no decreasing point
  i=1: arr[1]=4, arr[2]=5 -> no decreasing point
  i=2: arr[2]=5, arr[3]=1 -> decreasing point found (count=1)
  i=3: arr[3]=1, arr[4]=2 -> no decreasing point
  i=4: arr[4]=2, arr[0]=3 -> no decreasing point
- Only one decreasing point; return true.

Output:
- For arr = {3, 4, 5, 1, 2}, output: "The array is sorted and rotated."
- For arr = {1, 2, 3, 4, 5}, output: "The array is not sorted and rotated."
- For arr = {3, 5, 4, 1, 2}, output: "The array is not sorted and rotated."
*/
