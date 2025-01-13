#include <bits/stdc++.h>
using namespace std;

// Problem Statement:
// Given an array of integers, find the largest element in the array.
// Constraints: 
// 1 <= n <= 10^5 (size of the array)
// -10^9 <= arr[i] <= 10^9 (values of the array elements)

// Optimal Solution Class
class Solution
{
public:
    // Function to find the largest element in the array
    int largest(vector<int> &arr, int n)
    {
        // Use the STL function max_element to find the maximum element
        // max_element returns an iterator to the largest element in the range
        return *max_element(arr.begin(), arr.end());
    }
};

// Main function to demonstrate functionality
int main()
{
    Solution obj;
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = arr.size();
    
    // Find and print the largest element
    cout << "Largest element: " << obj.largest(arr, n) << endl;
    return 0;
}

/*
    Brute Force Solution:
    Instead of using the STL function, we can iterate through the array manually
    to find the maximum element. This approach takes O(n) time.

    int bruteForceLargest(vector<int> &arr, int n) {
        int maxElement = INT_MIN; // Initialize with the smallest possible value
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxElement) {
                maxElement = arr[i]; // Update maxElement if a larger value is found
            }
        }
        return maxElement;
    }
*/

/*
    Time Complexity Analysis:
    Optimal Solution:
    - Best case: O(n) (as we have to iterate through the array once to find the maximum)
    - Worst case: O(n) (the entire array is iterated)
    - Space Complexity: O(1) (no additional data structures are used, aside from iterators)

    Brute Force Solution:
    - Time Complexity: O(n) (we iterate through the array to find the maximum)
    - Space Complexity: O(1) (only a variable to store the max value)

    Dry Run (Example Input):
    Input: arr = {3, 1, 4, 1, 5, 9, 2, 6}, n = 8
    Optimal Solution:
    - `max_element` internally compares elements and returns the iterator pointing to 9.
    - Dereferencing the iterator gives 9 as the result.

    Brute Force:
    - Start with maxElement = INT_MIN
    - Iterate through arr: Compare each element with maxElement
      Step-by-step:
      maxElement = max(-∞, 3) = 3
      maxElement = max(3, 1) = 3
      maxElement = max(3, 4) = 4
      maxElement = max(4, 1) = 4
      maxElement = max(4, 5) = 5
      maxElement = max(5, 9) = 9
      maxElement = max(9, 2) = 9
      maxElement = max(9, 6) = 9
    - Final maxElement = 9

    Output: Largest element: 9
*/
