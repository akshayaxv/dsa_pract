#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
 * Problem Statement: 
 * Given two sorted arrays arr1[] and arr2[] of sizes n and m, 
 * the task is to find the union of these two arrays.
 * 
 * The union of two arrays is the set of all distinct elements present in both arrays.
 * The output should contain the distinct elements in ascending order.
 * 
 * Example 1:
 * Input: arr1[] = {1, 2, 3, 4, 5}, arr2[] = {2, 3, 4, 4, 5}
 * Output: {1, 2, 3, 4, 5}
 * 
 * Example 2:
 * Input: arr1[] = {2, 3, 4, 4, 5, 11, 12}, arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 * Output: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
 */

// Optimized Solution: O(N + M) time complexity, O(1) space complexity
vector<int> findUnion(const vector<int>& arr1, const vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> unionArr;

    // Traverse both arrays and merge them
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            // If element from arr1 is smaller and not already in unionArr, add it
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            // If element from arr2 is smaller and not already in unionArr, add it
            if (unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        } else {
            // If elements are equal, add any one of them and move both pointers
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1, if any
    while (i < arr1.size()) {
        if (unionArr.empty() || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements from arr2, if any
    while (j < arr2.size()) {
        if (unionArr.empty() || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

// Driver function to test the solution
int main() {
    vector<int> arr1 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Finding the union of two sorted arrays
    vector<int> unionArr = findUnion(arr1, arr2);

    // Printing the result
    cout << "Union of arr1 and arr2 is: ";
    for (int val : unionArr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Time Complexity Analysis:
 * - Time Complexity: O(N + M), where N is the size of arr1 and M is the size of arr2.
 * - We are iterating over both arrays once, making this solution linear in terms of time.
 * 
 * - Space Complexity: O(1) for extra space used, but O(N + M) space is used for the output array.
 * 
 * The time complexity is optimal as we only traverse both arrays once.
 * 
 * Brute Force Approach (using a set):
 * - Time Complexity: O(N + M) for inserting into the set, and O(N log N + M log M) for sorting.
 * - Space Complexity: O(N + M) for storing the union in the set.
 * 
 * Brute Force Code (using set and sorting):
 * 
 * vector<int> findUnionBruteForce(const vector<int>& arr1, const vector<int>& arr2) {
 *     unordered_set<int> set;
 *     for (int num : arr1) set.insert(num);
 *     for (int num : arr2) set.insert(num);
 *     
 *     vector<int> result(set.begin(), set.end());
 *     sort(result.begin(), result.end());
 *     
 *     return result;
 * }
 */
