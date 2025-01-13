#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to left-rotate the array by K positions
    void rotateLeft(int arr[], int n, int k)
    {
        /*
            Time Complexity: O(N)
            Space Complexity: O(N)
            This approach uses a temporary array to store intermediate results.
        */

        // Ensure rotation is within bounds
        k = k % n;

        // Create a temporary array
        int temp[n];

        // Copy elements from original array to temp array
        for (int i = 0; i < n; i++)
            temp[i] = arr[i];

        // Copy the elements starting from K to the beginning of the array
        for (int i = 0; i < n - k; i++)
            arr[i] = temp[i + k];

        // Copy the first K elements from temp to the end of the array
        for (int i = 0; i < k; i++)
            arr[n - k + i] = temp[i];
    }

    // Optimal in-place solution using reversal
    void rotateLeftInPlace(int arr[], int n, int k)
    {
        /*
            Time Complexity: O(N)
            Space Complexity: O(1)
            This approach uses array reversal to achieve the rotation in place.
        */

        // Ensure rotation is within bounds
        k = k % n;

        // Reverse the first K elements
        reverse(arr, arr + k);

        // Reverse the remaining elements
        reverse(arr + k, arr + n);

        // Reverse the entire array
        reverse(arr, arr + n);
    }
};

// Main function
int main()
{
    Solution obj;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    // Rotate using temp array
    cout << "Rotation using temp array:\n";
    obj.rotateLeft(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Reset array for in-place rotation
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    // Rotate in place using reversal
    cout << "In-place rotation using reversal:\n";
    obj.rotateLeftInPlace(arr2, n, k);
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}

/*
### Explanation of Methods:

#### Method 1: Using a Temporary Array
1. Copy the entire array into a temporary array.
2. From index `k` to the end, copy elements to the start of the original array.
3. Append the first `k` elements of the temporary array to the end of the original array.

#### Method 2: Using Reversal
1. Reverse the first `k` elements.
2. Reverse the remaining `n-k` elements.
3. Reverse the entire array.

### Dry Run for Reversal Approach:
Input: arr[] = {1, 2, 3, 4, 5, 6, 7}, k = 2
1. Reverse first `k`: {2, 1, 3, 4, 5, 6, 7}
2. Reverse remaining `n-k`: {2, 1, 7, 6, 5, 4, 3}
3. Reverse entire array: {3, 4, 5, 6, 7, 1, 2}

Output:
- {3, 4, 5, 6, 7, 1, 2}

### Complexity Analysis:
- **Temporary Array Method**:
  - Time: \( O(N) \)
  - Space: \( O(N) \)

- **In-Place Reversal Method**:
  - Time: \( O(N) \)
  - Space: \( O(1) \)

Both methods are efficient, but the in-place reversal method is preferred for space-constrained environments.
*/
