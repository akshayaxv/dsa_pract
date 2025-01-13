#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the second largest element in the array
    int print2largest(vector<int> &arr, int n)
    {
        /*
            This function returns the second largest element in the array.
            If no second largest element exists, it returns -1.
        */

        // Initialize two variables to store the largest and second largest elements
        int largest = -1, second_largest = -1;

        // Traverse the array to find the two largest distinct elements
        for (int i = 0; i < n; i++)
        {
            // Update largest and second largest as needed
            if (arr[i] > largest)
            {
                second_largest = largest;
                largest = arr[i];
            }
            else if (arr[i] > second_largest && arr[i] < largest)
            {
                second_largest = arr[i];
            }
        }

        // Return the second largest value
        return second_largest;
    }
};

// Main function to demonstrate the solution
int main()
{
    Solution obj;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int n = arr.size();
    cout << "Second largest element: " << obj.print2largest(arr, n) << endl;

    return 0;
}

/*
Problem Statement:
Given an array of size `n`, find the second largest element in the array.
If there is no second largest element, return -1.

Constraints:
1 <= n <= 10^5 (size of the array)
1 <= arr[i] <= 10^5 (values of the array elements)

Example:
Input: arr = {12, 35, 1, 10, 34, 1}, n = 6
Output: 34

Brute Force Solution:
- Sort the array in descending order.
- Traverse the sorted array to find the first element smaller than the largest.
- Return that element as the second largest, or -1 if no such element exists.

Code:
int bruteForcePrint2Largest(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end(), greater<int>()); // Sort in descending order
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < largest)
        {
            return arr[i];
        }
    }
    return -1;
}

Time Complexity Analysis:
Optimal Solution:
- Best case: O(n) (when the second largest is found early)
- Worst case: O(n) (entire array is traversed)
- Space Complexity: O(1) (no additional data structures used)

Brute Force Solution:
- Time Complexity: O(n log n) (due to sorting)
- Space Complexity: O(1) (no additional data structures used)

Dry Run (Example Input):
Input: arr = {12, 35, 1, 10, 34, 1}, n = 6
Optimal Solution:
- Initialize largest = -1, second_largest = -1
- Traverse the array:
  i=0: arr[i]=12 -> largest=12, second_largest=-1
  i=1: arr[i]=35 -> largest=35, second_largest=12
  i=2: arr[i]=1  -> no change
  i=3: arr[i]=10 -> no change
  i=4: arr[i]=34 -> second_largest=34
  i=5: arr[i]=1  -> no change
- Output: 34

Brute Force:
- Sort array: {35, 34, 12, 10, 1, 1}
- Traverse sorted array: largest=35, second largest=34
- Output: 34

Output: Second largest element: 34
*/
