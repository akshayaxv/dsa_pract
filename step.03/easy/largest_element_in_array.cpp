#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an array of integers, find the largest element in the array.

Approach:
1. Use the built-in `max_element` function from the `<algorithm>` header to find the maximum element.
2. `max_element` returns an iterator to the maximum element, which is then dereferenced to get the value.

Time Complexity:
- Best Case: O(n) (The function traverses the array once.)
- Worst Case: O(n) (The function always traverses the array once.)

Space Complexity:
- O(1) (No additional space is used apart from input.)

Dry Run:
Input: arr = {3, 7, 2, 8, 5}
Steps:
- Call `max_element(arr.begin(), arr.end())` -> Points to the largest element.
- Dereference the iterator to get the value -> 8.
Output: 8
*/

class Solution
{
public:
    // Function to find the largest element in the array
    int largest(vector<int> &arr, int n)
    {
        // Using max_element to find the largest value in the array
        return *max_element(arr.begin(), arr.end());
    }
};

int main()
{
    // Example usage
    vector<int> arr = {3, 7, 2, 8, 5};
    int n = arr.size();

    Solution solution;
    int largestElement = solution.largest(arr, n);

    // Output the result
    cout << "The largest element is: " << largestElement << endl;

    return 0;
}

/*
Dry Run Example:
Input:
arr = {3, 7, 2, 8, 5}
n = 5

Execution:
1. Call `largest(arr, n)`
2. max_element(arr.begin(), arr.end()) -> Points to the value 8
3. Return the value 8.

Output:
The largest element is: 8
*/
