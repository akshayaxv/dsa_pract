#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to remove duplicates and return both the count and modified array
    pair<int, vector<int>> remove_duplicates(int A[], int N)
    {
        /*
            This function removes duplicates from a sorted array
            and returns the number of unique elements and the modified array.
        */

        int i = 0, j = 0; // Initialize two pointers
        vector<int> result; // To store the modified array

        while (j < N)
        {
            // If it's the last element or current element is not equal to the next
            if (j == N - 1 || A[j] != A[j + 1])
            {
                result.push_back(A[j]); // Store unique element in the result
                i++;
                j++;
            }
            else
            {
                j++; // Skip duplicates
            }
        }

        return {i, result}; // Return the count and the modified array
    }

    // STL-based solution for vectors
    pair<int, vector<int>> remove_duplicates(vector<int> &A)
    {
        /*
            Using STL functions `unique` and `erase` to remove duplicates from a vector.
            This returns the number of unique elements and the modified vector.
        */
        A.erase(unique(A.begin(), A.end()), A.end());
        return {A.size(), A}; // Return the size and the modified vector
    }
};

// Main function to demonstrate the solution
int main()
{
    Solution obj;

    // Example with array
    int A[] = {1, 1, 2, 2, 3, 3, 4, 5};
    int N = sizeof(A) / sizeof(A[0]);
    auto array_result = obj.remove_duplicates(A, N);
    cout << "Number of unique elements in the array: " << array_result.first << endl;
    cout << "Modified array: ";
    for (int x : array_result.second)
        cout << x << " ";
    cout << endl;

    // Example with vector
    vector<int> vec = {1, 1, 2, 2, 3, 3, 4, 5};
    auto vector_result = obj.remove_duplicates(vec);
    cout << "Number of unique elements in the vector: " << vector_result.first << endl;
    cout << "Modified vector: ";
    for (int x : vector_result.second)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
### Explanation:

#### Input/Output:
Input:
    Array: {1, 1, 2, 2, 3, 3, 4, 5}
    N = 8
Output:
    Number of Unique Elements: 5
    Modified Array: {1, 2, 3, 4, 5}

Input:
    Vector: {1, 1, 2, 2, 3, 3, 4, 5}
Output:
    Number of Unique Elements: 5
    Modified Vector: {1, 2, 3, 4, 5}

---

### Time Complexity:
- Optimal Solution (Two-pointer approach for arrays): **O(N)**
- STL Solution (For vectors): **O(N)** for `unique` + **O(k)** for `erase` (where `k` is the number of duplicates removed)

### Space Complexity:
- Two-pointer approach: **O(k)** for storing the modified array
- STL Solution: **O(1)** (modifies the vector in place)

---

### Dry Run (Example Input: {1, 1, 2, 2, 3, 3, 4, 5}):
1. Initialize `result = []`, `i = 0`, `j = 0`
2. Traverse the array:
    - `j = 0`: A[0] = 1, add 1 to `result`, increment `i` and `j`
    - `j = 1`: A[1] = 1 (duplicate), increment `j`
    - `j = 2`: A[2] = 2, add 2 to `result`, increment `i` and `j`
    - `j = 3`: A[3] = 2 (duplicate), increment `j`
    - `j = 4`: A[4] = 3, add 3 to `result`, increment `i` and `j`
    - `j = 5`: A[5] = 3 (duplicate), increment `j`
    - `j = 6`: A[6] = 4, add 4 to `result`, increment `i` and `j`
    - `j = 7`: A[7] = 5, add 5 to `result`, increment `i` and `j`

Final Output:
- Modified Array: {1, 2, 3, 4, 5}
- Number of Unique Elements: 5
*/
