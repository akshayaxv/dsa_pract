#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Optimized Solution using Two Pointers
vector<int> findUnionOptimized(int arr1[], int arr2[], int n, int m) {
    /*
     * Optimized Solution:
     * Time Complexity: O(N + M) 
     * Space Complexity: O(1) (excluding the output array)
     * Explanation:
     * We use two pointers (i, j) for iterating through both arrays.
     * As the arrays are already sorted, we compare elements at arr1[i] and arr2[j].
     * If arr1[i] < arr2[j], we add arr1[i] to the result if it's not already present.
     * Similarly, we compare arr1[i] with arr2[j] and add the smaller element to the result.
     * The space complexity is O(1) excluding the space used for the result.
     */

    int i = 0, j = 0;
    vector<int> unionArray;

    // Traverse both arrays
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (unionArray.empty() || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (unionArray.empty() || unionArray.back() != arr2[j]) {
                unionArray.push_back(arr2[j]);
            }
            j++;
        } else {  // arr1[i] == arr2[j]
            if (unionArray.empty() || unionArray.back() != arr1[i]) {
                unionArray.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while (i < n) {
        if (unionArray.empty() || unionArray.back() != arr1[i]) {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements of arr2
    while (j < m) {
        if (unionArray.empty() || unionArray.back() != arr2[j]) {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }

    return unionArray;
}

/*
 * Dry Run of Optimized Approach:
 * Input:
 * arr1 = {2, 3, 4, 4, 5, 11, 12}
 * arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 * n = 7, m = 10
 *
 * 1. Initial pointers: i = 0, j = 0, unionArray = {}
 * 2. Compare arr1[i] (2) and arr2[j] (1), since 2 > 1, add 1 to unionArray, j++
 *    unionArray = {1}
 * 3. Compare arr1[i] (2) and arr2[j] (2), since 2 == 2, add 2 to unionArray, i++, j++
 *    unionArray = {1, 2}
 * 4. Compare arr1[i] (3) and arr2[j] (3), since 3 == 3, add 3 to unionArray, i++, j++
 *    unionArray = {1, 2, 3}
 * 5. Compare arr1[i] (4) and arr2[j] (4), since 4 == 4, add 4 to unionArray, i++, j++
 *    unionArray = {1, 2, 3, 4}
 * 6. Compare arr1[i] (5) and arr2[j] (5), since 5 == 5, add 5 to unionArray, i++, j++
 *    unionArray = {1, 2, 3, 4, 5}
 * 7. Compare arr1[i] (11) and arr2[j] (6), since 11 > 6, add 6 to unionArray, j++
 *    unionArray = {1, 2, 3, 4, 5, 6}
 * 8. Compare arr1[i] (11) and arr2[j] (7), since 11 > 7, add 7 to unionArray, j++
 *    unionArray = {1, 2, 3, 4, 5, 6, 7}
 * 9. Compare arr1[i] (11) and arr2[j] (8), since 11 > 8, add 8 to unionArray, j++
 *    unionArray = {1, 2, 3, 4, 5, 6, 7, 8}
 * 10. Compare arr1[i] (11) and arr2[j] (9), since 11 > 9, add 9 to unionArray, j++
 *     unionArray = {1, 2, 3, 4, 5, 6, 7, 8, 9}
 * 11. Compare arr1[i] (11) and arr2[j] (10), since 11 > 10, add 10 to unionArray, j++
 *     unionArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 * 12. Now arr2 is exhausted, add the remaining elements of arr1 (11, 12) to unionArray
 *     unionArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 *
 * Final Union: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 */

// Brute Force Solution using Set
vector<int> findUnionBruteForce(int arr1[], int arr2[], int n, int m) {
    /*
     * Brute Force Approach:
     * Time Complexity: O(N + M + (N + M) log(N + M)) due to sorting
     * Space Complexity: O(N + M)
     * Explanation:
     * We use a set to store all elements from both arrays. Then, we convert the set back to a vector and sort it.
     */
    
    set<int> s;

    // Insert elements of both arrays into the set
    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }

    // Convert set to vector
    vector<int> unionArray(s.begin(), s.end());

    return unionArray;
}

/*
 * Dry Run of Brute Force Approach:
 * Input:
 * arr1 = {2, 3, 4, 4, 5, 11, 12}
 * arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 * n = 7, m = 10
 *
 * 1. Insert elements of arr1 into set: {2, 3, 4, 5, 11, 12}
 * 2. Insert elements of arr2 into set: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 * 3. Convert set to vector and sort it (though set is already sorted):
 *    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 *
 * Final Union: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 */

int main() {
    int arr1[] = {2, 3, 4, 4, 5, 11, 12};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // Call Optimized Approach
    vector<int> resultOptimized = findUnionOptimized(arr1, arr2, n, m);
    cout << "Optimized Union of arr1 and arr2 is: ";
    for (int val : resultOptimized) {
        cout << val << " ";
    }
    cout << endl;

    // Call Brute Force Approach
    vector<int> resultBruteForce = findUnionBruteForce(arr1, arr2, n, m);
    cout << "Brute Force Union of arr1 and arr2 is: ";
    for (int val : resultBruteForce) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

//Optimized Approach (Two Pointers):

// Time Complexity: O(N + M), where N and M are the sizes of the two arrays.
// Space Complexity: O(1), excluding space for the result.
// Dry Run: Explained in the comments of the code, where we compare elements from both arrays and insert only distinct values into the result.
// Brute Force Approach (Set):

// Time Complexity: O(N + M + (N + M) log(N + M)) due to sorting the combined set.
// Space Complexity: O(N + M) for storing the elements in the set.
// Dry Run: Explained in the comments, where elements from both arrays are inserted into a set, and then the set is converted to a sorted vector.
