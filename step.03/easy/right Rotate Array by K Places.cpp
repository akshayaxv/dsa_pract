#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to right-rotate the array by K positions using temp array
    void rotateRight(int arr[], int n, int k)
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

        // Copy the last K elements to the beginning of the array
        for (int i = 0; i < k; i++)
            arr[i] = temp[n - k + i];

        // Copy the remaining elements to the rest of the array
        for (int i = 0; i < n - k; i++)
            arr[k + i] = temp[i];
    }

    // Optimal in-place solution using reversal
    void rotateRightInPlace(int arr[], int n, int k)
    {
        /*
            Time Complexity: O(N)
            Space Complexity: O(1)
            This approach uses array reversal to achieve the rotation in place.
        */

        // Ensure rotation is within bounds
        k = k % n;

        // Reverse the last K elements
        reverse(arr + n - k, arr + n);

        // Reverse the first n-K elements
        reverse(arr, arr + n - k);

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
    obj.rotateRight(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Reset array for in-place rotation
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    // Rotate in place using reversal
    cout << "In-place rotation using reversal:\n";
    obj.rotateRightInPlace(arr2, n, k);
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}

/*
### Explanation of Methods:

#### Method 1: Using a Temporary Array
1. Copy the entire array into a temporary array.
2. Copy the last \( k \) elements from the temporary array to the start of the original array.
3. Append the first \( n-k \) elements of the temporary array to the rest of the original array.

#### Method 2: Using Reversal
1. Reverse the last \( k \) elements.
2. Reverse the first \( n-k \) elements.
3. Reverse the entire array.

### Dry Run for Reversal Approach:
Input: arr[] = {1, 2, 3, 4, 5, 6, 7}, k = 2
1. Reverse last \( k \): {1, 2, 3, 4, 5, 7, 6}
2. Reverse first \( n-k \): {5, 4, 3, 2, 1, 7, 6}
3. Reverse entire array: {6, 7, 1, 2, 3, 4, 5}

Output:
- {6, 7, 1, 2, 3, 4, 5}

### Complexity Analysis:
- **Temporary Array Method**:
  - Time: \( O(N) \)
  - Space: \( O(N) \)

- **In-Place Reversal Method**:
  - Time: \( O(N) \)
  - Space: \( O(1) \)

The in-place reversal method is more space-efficient and is preferred for environments where memory usage is critical.
*/
