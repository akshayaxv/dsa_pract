#include <bits/stdc++.h>
using namespace std;

// Approach #1: Using Hashing
// Time Complexity: O(N) - we traverse the array once, and the operations on the unordered_map (insertion and lookup) take O(1) time on average.
// Space Complexity: O(N) - space used by the hashmap.
class Solution
{
public:
    // Function to check if the array has 2 elements whose sum is equal to the given value
    bool hasArrayTwoCandidates(vector<int>& arr, int x)
    {
        // Using an unordered map (hashmap) to store the array elements and their indices
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            // If (x - arr[i]) is found in the map, we have found two elements whose sum is equal to x
            if (mp.find(x - arr[i]) != mp.end())
            {
                return true; //{x - arr[i], arr[i]}
            }
            mp[arr[i]] = i;  // Store the element in the map with its index
        }
        return false;  // No such pair found {-1,-1}
    }
};

/*
Dry Run of Approach 1:
----------------------
Array: [1, 4, 7, 3, 6, 5]
Target sum (x): 10

Step-by-Step Execution:
1. Initialize an empty map.
2. Traverse the array:
   - i = 0, arr[0] = 1, check if (10 - 1 = 9) exists in map → no. Add 1 to map.
   - i = 1, arr[1] = 4, check if (10 - 4 = 6) exists in map → no. Add 4 to map.
   - i = 2, arr[2] = 7, check if (10 - 7 = 3) exists in map → no. Add 7 to map.
   - i = 3, arr[3] = 3, check if (10 - 3 = 7) exists in map → yes! Pair found: 7 + 3 = 10.
3. Return true as pair is found.

Time Complexity: O(N)
Space Complexity: O(N)
*/

// Approach #2: Using Two Pointer Technique
// Time Complexity: O(NlogN) due to the sorting step. The while loop itself takes O(N).
// Space Complexity: O(1) - only a few variables are used, and no extra space is used apart from the array.
class Solution {
public:
    bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        // Sorting the array first
        sort(arr.begin(), arr.end()); 
        int i = 0, j = arr.size() - 1;  // Using two pointers: i starts from the left, j starts from the right
        
        while (i < j) {
            // If the sum of the elements at i and j is equal to x, return true
            if (arr[i] + arr[j] == x) {
                return true; //{arr[i], arr[j]}
            }
            // If the sum is greater than x, move the right pointer to the left to decrease the sum
            else if (arr[i] + arr[j] > x) {
                --j;
            }
            // If the sum is less than x, move the left pointer to the right to increase the sum
            else {
                ++i;
            }
        }
        return false;  // No such pair found
    }
};

/*
Dry Run of Approach 2:
----------------------
Array: [1, 4, 7, 3, 6, 5]
Target sum (x): 10

Step-by-Step Execution:
1. Sort the array: [1, 3, 4, 5, 6, 7]
2. Initialize two pointers: i = 0, j = 5 (points to 7)
3. Traverse using the two-pointer technique:
   - i = 0, j = 5, arr[0] + arr[5] = 1 + 7 = 8, less than 10, so increment i.
   - i = 1, j = 5, arr[1] + arr[5] = 3 + 7 = 10, equal to 10. Pair found: 3 + 7 = 10.
4. Return true as pair is found.

Time Complexity: O(NlogN) due to sorting
Space Complexity: O(1)
*/

int main() {
    Solution sol;
    vector<int> arr = {1, 4, 7, 3, 6, 5};
    int x = 10;
    
    // Approach 1: Hashing
    if (sol.hasArrayTwoCandidates(arr, x)) {
        cout << "Pair found with sum " << x << " (Using Hashing)" << endl;
    } else {
        cout << "No pair found with sum " << x << " (Using Hashing)" << endl;
    }
    
    // Approach 2: Two Pointers
    if (sol.hasArrayTwoCandidates(arr, x)) {
        cout << "Pair found with sum " << x << " (Using Two Pointers)" << endl;
    } else {
        cout << "No pair found with sum " << x << " (Using Two Pointers)" << endl;
    }

    return 0;
}
